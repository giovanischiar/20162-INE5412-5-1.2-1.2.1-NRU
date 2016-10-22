/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ModuleInovoke_MemoryAlloc.cpp
 * Author: cancian
 * 
 * Created on 22 de Abril de 2016, 13:14
 */

#include "ModuleInvoke_MemoryAlloc.h"
#include "OperatingSystem.h"
#include "Simulator.h"

ModuleInvoke_MemoryAlloc::ModuleInvoke_MemoryAlloc(std::string name):Module(name) {
}

ModuleInvoke_MemoryAlloc::ModuleInvoke_MemoryAlloc(const ModuleInvoke_MemoryAlloc& orig):Module(orig) {
}

ModuleInvoke_MemoryAlloc::~ModuleInvoke_MemoryAlloc() {
}

void ModuleInvoke_MemoryAlloc::do_run(Entity* entity) {
    unsigned int requestedMemory = Simulator::generate_uniform_distribution(Traits<Process>::minAddressSpace, Traits<Process>::maxAddressSpace);
    MemoryChunk* chunk = OperatingSystem::Memory_Manager()->allocateMemory(requestedMemory);
    entity->getAttribute("ChunkPtr")->setValue(std::to_string(reinterpret_cast<unsigned long> (chunk))); // save partition as an attribute of the entity
    
    Simulator* simulator = Simulator::getInstance();
    double tnow = simulator->getTnow();
    std::list<Module*>::iterator it = this->_nextModules->begin();
    Module* nextModuleAllocated = (*it);
    it++;
    Module* nextModuleFailed = (*it);    
    if (chunk != nullptr) {
        OperatingSystem::Memory_Manager()->showMemory();
        simulator->insertEvent(tnow, nextModuleAllocated, entity);
    } else {
        Debug::cout(Debug::Level::warning, "There is no memory for the process. Exiting.");
        simulator->insertEvent(tnow, nextModuleFailed, entity);
    }
}

