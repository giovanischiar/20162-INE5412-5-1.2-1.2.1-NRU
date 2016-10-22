/*
 * File:   ModuleInvoke_ProcessExec.cpp
 * Author: cancian
 *
 * Created on October 9, 2015, 7:44 PM
 */

#include <string>

#include "ModuleInvoke_ProcessExec.h"
#include "Abstr_Process.h"
#include "Simulator.h"
#include "Simul_Debug.h"

ModuleInvoke_ProcessExec::ModuleInvoke_ProcessExec(std::string name) : Module(name) {
}

ModuleInvoke_ProcessExec::ModuleInvoke_ProcessExec(const ModuleInvoke_ProcessExec& orig) : Module(orig) {
}

ModuleInvoke_ProcessExec::~ModuleInvoke_ProcessExec() {
}

void ModuleInvoke_ProcessExec::do_run(Entity* entity) {
    Simulator* simulator = Simulator::getInstance();
    Debug::cout(Debug::Level::info, this, entity, "Process has arrived. Invoking Process::exec()");
    Process* process = Process::exec();
    entity->getAttribute("ProcessPtr")->setValue(std::to_string(reinterpret_cast<unsigned long> (process)));

    Module* nextModule = *(this->_nextModules->begin());
    simulator->insertEvent(simulator->getTnow(), nextModule, entity);
}