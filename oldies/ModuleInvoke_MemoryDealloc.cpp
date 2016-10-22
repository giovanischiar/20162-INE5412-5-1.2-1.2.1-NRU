/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ModuleInvoke_MemoryDealloc.cpp
 * Author: cancian
 * 
 * Created on 22 de Abril de 2016, 14:50
 */

#include "ModuleInvoke_MemoryDealloc.h"

#include "Abstr_MemoryManager.h"
#include "OperatingSystem.h"
#include "Simulator.h"

ModuleInvoke_MemoryDealloc::ModuleInvoke_MemoryDealloc(std::string name): Module(name) {
}

ModuleInvoke_MemoryDealloc::ModuleInvoke_MemoryDealloc(const ModuleInvoke_MemoryDealloc& orig):Module(orig) {
}

ModuleInvoke_MemoryDealloc::~ModuleInvoke_MemoryDealloc() {
}

void ModuleInvoke_MemoryDealloc::do_run(Entity* entity) {
    unsigned long address = std::stol(entity->getAttribute("ChunkPtr")->getValue());
    MemoryChunk* chunk = reinterpret_cast<MemoryChunk*>(address);
    
    OperatingSystem::Memory_Manager()->deallocateMemory(chunk);
    OperatingSystem::Memory_Manager()->showMemory();
    
    Simulator* simulator = Simulator::getInstance();
    std::list<Module*>::iterator it = this->_nextModules->begin();
    simulator->insertEvent(simulator->getTnow(), (*it), entity);
    
}
