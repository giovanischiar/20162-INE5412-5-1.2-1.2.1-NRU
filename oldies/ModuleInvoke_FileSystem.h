/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ModuleInvoke_FileSystem.h
 * Author: cancian
 *
 * Created on 29 de Agosto de 2016, 12:18
 */

#ifndef MODULEINVOKE_FILESYSTEM_H
#define MODULEINVOKE_FILESYSTEM_H

#include "Module.h"

class ModuleInvoke_FileSystem: public Module  {
public:
    ModuleInvoke_FileSystem(std::string name);
    ModuleInvoke_FileSystem(const ModuleInvoke_FileSystem& orig);
    virtual ~ModuleInvoke_FileSystem();
private:
protected:
    virtual void do_run(Entity* entity);
};

#endif /* MODULEINVOKE_FILESYSTEM_H */

