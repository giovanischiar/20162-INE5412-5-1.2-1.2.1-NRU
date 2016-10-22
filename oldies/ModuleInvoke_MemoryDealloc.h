/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ModuleInvoke_MemoryDealloc.h
 * Author: cancian
 *
 * Created on 22 de Abril de 2016, 14:49
 */

#ifndef MODULEINVOKE_MEMORYDEALLOC_H
#define MODULEINVOKE_MEMORYDEALLOC_H

#include "Module.h"

class ModuleInvoke_MemoryDealloc: public Module {
public:
    ModuleInvoke_MemoryDealloc(std::string name);
    ModuleInvoke_MemoryDealloc(const ModuleInvoke_MemoryDealloc& orig);
    virtual ~ModuleInvoke_MemoryDealloc();
protected:
    virtual void do_run(Entity* entity);
private:

};

#endif /* MODULEINVOKE_MEMORYDEALLOC_H */

