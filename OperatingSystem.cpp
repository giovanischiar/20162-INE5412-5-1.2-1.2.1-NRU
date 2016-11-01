/*
 * File:   System.cpp
 * Author: cancian
 *
 * Created on October 9, 2015, 9:04 PM
 */
#include <string>
#include <cstring>

#include "OperatingSystem.h"
#include "Application.h"
#include "HW_CPU.h"
#include "HW_Machine.h"
#include "Simulator.h"
#include "DataMemoryChunk.h"

#include "Simul_Statistics.h"

const int CREATED = 0;
const int EXECUTING = 1;
const int FINISHED = 2;

TestApplication* OperatingSystem::testApplication;
int OperatingSystem::currentMemoryAccess;

void OperatingSystem::LoadApplication(Application* app, MMU::PhysicalAddress address) {
    Debug::cout(Debug::Level::trace, "OperatingSystem::LoadApplication(" + std::to_string(reinterpret_cast<unsigned long> (app)) + "," + std::to_string(address) + ")");
    std::list<Application::Information> code = app->getCode();
    HW_MMU::Information info;
    for (std::list<HW_MMU::Information>::iterator it = code.begin(); it != code.end(); it++) {
        info = (*it);
        HW_Machine::RAM()->write(address, info);
        address++;
    }
}

void OperatingSystem::SetBootApplication(Application* app) {
    Debug::cout(Debug::Level::trace, "OperatingSystem::SetBootApplication(" + std::to_string(reinterpret_cast<unsigned long> (app)) + ")");
    HW_CPU::Register address = HW_Machine::CPU()->readRegister(HW_CPU::pc);
    LoadApplication(app, address);
}

void OperatingSystem::Init() {
    Debug::cout(Debug::Level::trace, "OperatingSystem::init()");
    HW_Machine::Init();

    OperatingSystem::CPU_Mediator();
    OperatingSystem::DMA_Mediator();
    OperatingSystem::HardDisk_Mediator();
    OperatingSystem::MMU_Mediator();
    OperatingSystem::Timer_Mediator();

    SetBootApplication(Application::DefaultBootApplication()); // load boot application into RAMs
}

void OperatingSystem::ExecuteTestCode() {
    Debug::cout(Debug::Level::trace, "OperatingSystem::ExecuteTestCode()");
    Simulator* simulator = Simulator::getInstance();
    Entity* entity = simulator->getEntity();
    int executionStep = std::stoi(entity->getAttribute("ExecutionStep")->getValue());

    switch (executionStep) {
        case CREATED: // ExecutionState is initialized with 0 (CREATED)
        {
            Debug::cout(Debug::Level::trace, "Starting Test Application");
            entity->getAttribute("ExecutionStep")->setValue(std::to_string(++executionStep)); // advance execution step
            testApplication = new TestApplication();
            OperatingSystem::Memory_Manager()->fillSwap(testApplication->getAddressSpaceChunks());
            currentMemoryAccess = 0;
            break;
        }
        case EXECUTING:
        {
            if (OperatingSystem::MMU_Mediator()->hasPageFault() &&
                    !OperatingSystem::MMU_Mediator()->handledLastPageFault()) {
                break;
            }

            if (currentMemoryAccess >= testApplication->getMemoryReferences().size()) {
                entity->getAttribute("ExecutionStep")->setValue(std::to_string(++executionStep)); // advance execution step;
                break;
            }

            const MemoryAccess& memoryAccess = testApplication->getMemoryReferences().at(currentMemoryAccess);
            switch (memoryAccess.op) {
                case Operation::Read:
                {
                    Information value = HW_Machine::MMU()->readMemory(memoryAccess.addr);
                    if (OperatingSystem::MMU_Mediator()->hasProtectionError()) {
                        Debug::cout(Debug::Level::error, "Protection Error! Was Trying to Read RAM[" + std::to_string(memoryAccess.addr) + "]");
                        entity->getAttribute("ExecutionStep")->setValue(std::to_string(++executionStep)); // advance execution step;
                        break;
                    }

                    if (OperatingSystem::MMU_Mediator()->hasPageFault()) {
                        Debug::cout(Debug::Level::warning, "Page Fault! Was Trying to Read RAM[" + std::to_string(memoryAccess.addr) + "]");
                    } else {
                        Debug::cout(Debug::Level::trace, "Reading RAM[" + std::to_string(memoryAccess.addr) + "] = " + std::to_string(value));
                        currentMemoryAccess++;
                    }
                    break;
                }
                case Operation::Write:
                {
                    HW_Machine::MMU()->writeMemory(memoryAccess.addr, memoryAccess.valueToWrite);
                    if (OperatingSystem::MMU_Mediator()->hasProtectionError()) {
                        Debug::cout(Debug::Level::error, "Protection Error! Was Trying to Write to RAM[" + std::to_string(memoryAccess.addr) + "]");
                        entity->getAttribute("ExecutionStep")->setValue(std::to_string(++executionStep)); // advance execution step;
                        break;
                    }

                    if (OperatingSystem::MMU_Mediator()->hasPageFault()) {
                        Debug::cout(Debug::Level::warning, "Page Fault! Was Trying to Write to RAM[" + std::to_string(memoryAccess.addr) + "]");
                    } else {
                        Debug::cout(Debug::Level::trace, "Writing " + std::to_string(memoryAccess.valueToWrite) + " to RAM[" + std::to_string(memoryAccess.addr) + "]");
                        currentMemoryAccess++;
                    }
                    break;
                }
            }
            break;
        }
        case FINISHED:
        {
            Debug::cout(Debug::Level::trace, "Finished Test Application");
            delete testApplication;
            testApplication = nullptr;
            OperatingSystem::PrintStatistics();
            simulator->getModel()->setTerminatingCondition("1");
            break;
        }
    }
}

void OperatingSystem::PrintStatistics() {
    Debug::cout(Debug::Level::trace, "-- Statistics --");
    float rate = Statistics::getInstance().pageFaultRate();
    std::string percentage = std::to_string(rate * 100) + "%";
    Debug::cout(Debug::Level::trace, "Page Fault Rate: " + std::to_string(rate) + " (" + percentage + ")");
    std::string pagesReplaced = std::to_string(Statistics::getInstance().pagesReplaced());
    Debug::cout(Debug::Level::trace, "Amount of Pages Replaced: " + pagesReplaced);
}

/*
 Not used
 */
HW_MMU::Information OperatingSystem::asmm(std::string mnemonic) {
    HW_MMU::Information bincode;
    /* @TODO 
     */
    if (mnemonic == "Process:exec()") {
        bincode = 0xFFFFFFFF; // - (HW_CPU::addi<<24) + 
    }
    //@TODO
    bincode = (HW_CPU::addi << 26) + (HW_CPU::s0 << 21) + (HW_CPU::s1 << 16) + 1; // for tests purpose only
    return bincode;
}