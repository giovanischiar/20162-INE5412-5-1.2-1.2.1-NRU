/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ModuleInovoke_MemoryAlloc.h
 * Author: cancian
 *
 * Created on 22 de Abril de 2016, 13:14
 */

#ifndef MODULEINOVOKE_MEMORYALLOC_H
#define MODULEINOVOKE_MEMORYALLOC_H

#include "Module.h"

class ModuleInvoke_MemoryAlloc: public Module {
public:
    ModuleInvoke_MemoryAlloc(std::string name);
    ModuleInvoke_MemoryAlloc(const ModuleInvoke_MemoryAlloc& orig);
    virtual ~ModuleInvoke_MemoryAlloc();
protected:
    virtual void do_run(Entity* entity);
private:

};

#endif /* MODULEINOVOKE_MEMORYALLOC_H */

