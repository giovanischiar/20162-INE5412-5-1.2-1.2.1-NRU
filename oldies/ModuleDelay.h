/*
 * File:   ModuleDelay.h
 * Author: cancian
 *
 * Created on September 27, 2015, 7:46 PM
 */

#ifndef MODULEDELAY_H
#define	MODULEDELAY_H

#include "Simul_Entity.h"
#include "Module.h"

#include <string>

class ModuleDelay : public Module {
public:
    ModuleDelay(std::string name, std::string delayTime);
    ModuleDelay(const ModuleDelay& orig);
    virtual ~ModuleDelay();
    void setDelayTime(std::string _delayTime);
    std::string getDelayTime() const;
protected:
    virtual void do_run(Entity* entity);

private:
    std::string _delayTime;
};

#endif	/* MODULEDELAY_H */

