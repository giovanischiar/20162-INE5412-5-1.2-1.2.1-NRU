/*
 * File:   ModuleInvoke_ThreadExec.cpp
 * Author: cancian
 *
 * Created on October 11, 2015, 11:21 AM
 */

#include <assert.h>
#include <string>
#include <iostream>

#include "ModuleInvoke_ThreadExec.h"
#include "Simulator.h"
#include "OperatingSystem.h"
#include "Simul_Debug.h"
#include "Traits.h"
#include "Simul_Entity.h"

ModuleInvoke_ThreadExec::ModuleInvoke_ThreadExec(std::string name) : Module(name) {
}

ModuleInvoke_ThreadExec::ModuleInvoke_ThreadExec(const ModuleInvoke_ThreadExec& orig) : Module(orig) {
}

ModuleInvoke_ThreadExec::~ModuleInvoke_ThreadExec() {
}

void ModuleInvoke_ThreadExec::do_run(Entity* entity) {
    Simulator* simulator = Simulator::getInstance();
    //Debug::cout(Debug::Level::info, this, entity, "Thread is running");
    // simulate thread execution
    // (execute for some time, then (invoke a system call, wait for a thread)+ )+ then exits
    Attribute* attrExecutionStage = entity->getAttribute("ExecutionStage");
    int executionStage = std::stoi(attrExecutionStage->getValue());
    std::string value;
    Thread* running;
    Module* nextModule;
    double remainingExecutionTime;
    double time = simulator->getTnow();
    switch (executionStage) {
        case 0: // thread just start running. If it is the first thread, then create others, otherwise just run
            value = entity->getAttribute("NumThreads")->getValue();
            if (value == "0") { // this is the main thread
                int MAX_THREADS = Simulator::generate_uniform_distribution(Traits<Thread>::minThreadsPerProcess, Traits<Thread>::maxThreadsPerProcess);
                running = Thread::running();
                running->_accountInfo._priority = -99;
                // reordenar fila de prontos
                //Debug::cout(Debug::Level::info, "Thread " + std::to_string(reinterpret_cast<unsigned long> (running)) + " is running");
                entity->getAttribute("NumThreads")->setValue(std::to_string(MAX_THREADS));
                Entity* duplicatedEntity;
                Entity* mainThreadEntity;
                // now if the process will have more than one thread, create all threads at once
                // duplicates entity to represent the main() thread. Entity will be sent to the wait module by the invovke process module and
                // the new duplicate will remain in this module
                mainThreadEntity = simulator->createEntity(entity); // the main thread
                mainThreadEntity->getAttribute("EntityType")->setValue("Thread"); // this is no longer a process
                mainThreadEntity->getAttribute("ThreadPtr")->setValue(std::to_string(reinterpret_cast<unsigned long> (running)));
                mainThreadEntity->getAttribute("CPUBursts")->setValue(std::to_string(Traits<Thread>::maxBursts));
                mainThreadEntity->getAttribute("ThreadNum")->setValue("1"); // this is the main() thread
                //simulator->insertEvent(time + Traits<CPU>::context_switch_overhead*MAX_THREADS, this, mainThreadEntity);
                for (int i = 2; i <= MAX_THREADS; i++) {
                    duplicatedEntity = simulator->createEntity(entity);
                    duplicatedEntity->getAttribute("EntityType")->setValue("Thread"); // this is no longer a process
                    duplicatedEntity->getAttribute("CPUBursts")->setValue(std::to_string(Traits<Thread>::maxBursts));
                    duplicatedEntity->getAttribute("ThreadNum")->setValue(std::to_string(i));
                    Thread* newThread = Thread::thread_create(running->_process); // should cause a context switch, but it will NOT, since "ThreadPtr"="0", so, insert event to execute in this loop
                    //Attribute* attrChild = new Attribute("Child" + std::to_string(i), std::to_string(reinterpret_cast<unsigned long> (newThread)));
                    //mainThreadEntity->getAttributes()->insert(entity->getAttributes()->end(), attrChild);
                    mainThreadEntity->getAttribute("Child" + std::to_string(i))->setValue(std::to_string(reinterpret_cast<unsigned long> (newThread)));
                    duplicatedEntity->getAttribute("ThreadPtr")->setValue(std::to_string(reinterpret_cast<unsigned long> (newThread)));
                    //time += Traits<CPU>::context_switch_overhead;
                    //simulator->insertEvent(time, this, duplicatedEntity); // new thread start to execute
                }
                if (MAX_THREADS > 1) {
                    // main() thread goes directly to the last execution stage: joining all created threads
                    executionStage = 99; // any large number to match "default case" -> thread MAIN will join())
                }
                mainThreadEntity->getAttribute("ExecutionStage")->setValue(std::to_string(++executionStage));
                simulator->insertEvent(time, this, mainThreadEntity);
                remainingExecutionTime = time + Simulator::generate_uniform_distribution(Traits<Thread>::minCpuBurst, Traits<Thread>::maxCpuBurst);
                mainThreadEntity->getAttribute("RemainingExecutionTime")->setValue(std::to_string(remainingExecutionTime)); // will execute until the end of CpuBurst and then chooses agains
                attrExecutionStage->setValue(std::to_string(++executionStage));
                Debug::cout(Debug::Level::info, "Thread " + mainThreadEntity->getAttribute("ThreadPtr")->getValue() + " (main) just started running for " + std::to_string(remainingExecutionTime) + " time units");

            } else {
                // set the time to run
                remainingExecutionTime = time + Simulator::generate_uniform_distribution(Traits<Thread>::minCpuBurst, Traits<Thread>::maxCpuBurst);
                entity->getAttribute("RemainingExecutionTime")->setValue(std::to_string(remainingExecutionTime)); // will execute until the end of CpuBurst and then chooses agains
                attrExecutionStage->setValue(std::to_string(++executionStage));
                simulator->insertEvent(time, this, entity);
                Debug::cout(Debug::Level::info, "Thread " + entity->getAttribute("ThreadPtr")->getValue() + " just started running for " + std::to_string(remainingExecutionTime) + " time units");
                break;
            }
            break;
        case 1: // just run
            remainingExecutionTime = std::stod(entity->getAttribute("RemainingExecutionTime")->getValue());
            remainingExecutionTime -= Traits<CPU>::context_switch_overhead;
            entity->getAttribute("RemainingExecutionTime")->setValue(std::to_string(remainingExecutionTime));
            if (remainingExecutionTime <= 0.0) {
                // execution time has finished. Advance to the next stage
                attrExecutionStage->setValue(std::to_string(++executionStage));
            }
            Debug::cout(Debug::Level::fine, "Thread " + entity->getAttribute("ThreadPtr")->getValue() + " is running for " + std::to_string(remainingExecutionTime) + " time units");
            time += Traits<CPU>::context_switch_overhead; //Simulator::generate_uniform_distribution(Traits<Thread>::minCpuBurst, Traits<Thread>::maxCpuBurst); // will execute until the end of CpuBurst and then chooses agains
            simulator->insertEvent(time, this, entity);
            break;
        case 2: // yields
            Debug::cout(Debug::Level::info, "Thread " + entity->getAttribute("ThreadPtr")->getValue() + " is running ad will yield()");
            running = Thread::running();
            running->yield();
            // advance to next stage
            attrExecutionStage->setValue(std::to_string(++executionStage));
            // set the time to run when it is back
            remainingExecutionTime = time + Simulator::generate_uniform_distribution(Traits<Thread>::minCpuBurst, Traits<Thread>::maxCpuBurst);
            entity->getAttribute("RemainingExecutionTime")->setValue(std::to_string(remainingExecutionTime)); // will execute until the end of CpuBurst and then chooses agains
            //simulator->insertEvent(time, this, entity);
            break;
        case 3: // just scheduled back from yield
            Debug::cout(Debug::Level::info, "Thread " + entity->getAttribute("ThreadPtr")->getValue() + " was scheduled back after yield() and is running for " + entity->getAttribute("RemainingExecutionTime")->getValue() + " time units");
            attrExecutionStage->setValue(std::to_string(++executionStage));
            simulator->insertEvent(time, this, entity);
            break;
        case 4: // just run
            //Debug::cout(Debug::Level::info, "Thread " + entity->getAttribute("ThreadPtr")->getValue() + " is running");
            remainingExecutionTime = std::stod(entity->getAttribute("RemainingExecutionTime")->getValue());
            remainingExecutionTime -= Traits<CPU>::context_switch_overhead;
            entity->getAttribute("RemainingExecutionTime")->setValue(std::to_string(remainingExecutionTime));
            if (remainingExecutionTime <= 0.0) {
                Attribute* attrBursts = entity->getAttribute("CPUBursts");
                unsigned int cpuBursts = std::stoi(attrBursts->getValue());
                attrBursts->setValue(std::to_string(--cpuBursts));
                Debug::cout(Debug::Level::info, "Thread " + entity->getAttribute("ThreadPtr")->getValue() + " has "+ entity->getAttribute("CPUBursts")->getValue() + " more burst to run");
                if (cpuBursts>0)
                   attrExecutionStage->setValue(std::to_string(2)); // back to yield for another CPU burst
                else
                    attrExecutionStage->setValue(std::to_string(++executionStage));                    
            }
            Debug::cout(Debug::Level::fine, "Thread " + entity->getAttribute("ThreadPtr")->getValue() + " is running for " + std::to_string(remainingExecutionTime) + " time units");
            time += Traits<CPU>::context_switch_overhead; //Simulator::generate_uniform_distribution(Traits<Thread>::minCpuBurst, Traits<Thread>::maxCpuBurst); // will execute until the end of CpuBurst and then chooses agains
            simulator->insertEvent(time, this, entity);
            break;
            /*
        case 4:
            run_stage++;
            break;
        case 5:
            run_stage++;
            break;
             * */
        default: // thread finishes!!
            // if this was the main thread of the process, then exit the process
            if (entity->getAttribute("ThreadNum")->getValue() == "1") { // The MAIN thread
                if (entity->getAttribute("NumThreads")->getValue() == "1") {
                    Debug::cout(Debug::Level::info, "Thread " + entity->getAttribute("ThreadPtr")->getValue() + " (main) is running and will exit()");
                    Process::exit(0);
                    // emit signal
                    nextModule = *(++(this->_nextModules->begin())); // the second next (the signal module))
                    simulator->insertEvent(time, nextModule, entity);
                } else {
                    // must wait other threads to finish (JOIN)
                    Debug::cout(Debug::Level::info, "Thread " + entity->getAttribute("ThreadPtr")->getValue() + " (main) is running and will join()");
                    Thread* running = Thread::running();
                    std::string strNumThreads = entity->getAttribute("NumThreads")->getValue();
                    unsigned int numThreads = std::stoi(strNumThreads);
                    Attribute* childAttr = entity->getAttribute("Child" + strNumThreads);
                    std::string child = childAttr->getValue();
                    unsigned long longWaitfor = std::stoul(child, nullptr, 0);
                    //Thread* waitfor = dynamic_cast<Thread*> (longWaitfor);
                    Thread* waitfor = reinterpret_cast<Thread*> (longWaitfor);
                    waitfor->join();
                    numThreads--;
                    entity->getAttribute("NumThreads")->setValue(std::to_string(numThreads));
                    bool isTrue = running->_state == Thread::State::RUNNING;
                    if (waitfor->_state == Thread::State::FINISHING) {//if (running->_state==Thread::State::RUNNING){
                        // the thread was not blocked beacuse waitfor is already FINISHING
                        simulator->insertEvent(time, this, entity);
                    }
                }
            } else { //ends just the thread
                Debug::cout(Debug::Level::info, "Thread " + entity->getAttribute("ThreadPtr")->getValue() + " is running and will exit()");
                Thread::exit(0);
                simulator->removeEventsOfEntity(entity);
                nextModule = *(this->_nextModules->begin());
                simulator->insertEvent(time, nextModule, entity);
            }
            break;
    }
}