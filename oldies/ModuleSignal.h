/*
 * File:   ModuleSignal.h
 * Author: cancian
 *
 * Created on October 11, 2015, 11:50 AM
 */

#ifndef MODULESIGNAL_H
#define	MODULESIGNAL_H

#include "Module.h"

class ModuleSignal : public Module {
public:
    ModuleSignal(std::string name, std::string signal);
    ModuleSignal(const ModuleSignal& orig);
    virtual ~ModuleSignal();
    void setSignal(std::string _signal);
    std::string getSignal() const;
protected:
    virtual void do_run(Entity* entity);

private:
    std::string _signal;
};

#endif	/* MODULESIGNAL_H */

