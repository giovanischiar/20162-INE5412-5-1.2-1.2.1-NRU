/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ModuleInvoke_DiskScheduler.h
 * Author: cancian
 *
 * Created on 29 de Agosto de 2016, 12:18
 */

#ifndef MODULEINVOKE_DISKSCHEDULER_H
#define MODULEINVOKE_DISKSCHEDULER_H

#include "Module.h"

class ModuleInvoke_DiskScheduler : public Module {
public:
    ModuleInvoke_DiskScheduler(std::string name);
    ModuleInvoke_DiskScheduler(const ModuleInvoke_DiskScheduler& orig);
    virtual ~ModuleInvoke_DiskScheduler();
private:
protected:
    virtual void do_run(Entity* entity);
};

#endif /* MODULEINVOKE_DISKSCHEDULER_H */

