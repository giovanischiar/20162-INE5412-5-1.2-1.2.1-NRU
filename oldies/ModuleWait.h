/*
 * File:   ModuleWait.h
 * Author: cancian
 *
 * Created on October 11, 2015, 11:50 AM
 */

#ifndef MODULEWAIT_H
#define	MODULEWAIT_H

#include "Module.h"

class ModuleWait : public Module {
public:
    ModuleWait(std::string name, std::string signal, std::string attribute, unsigned int numEntitiesToRelease);
    ModuleWait(const ModuleWait& orig);
    virtual ~ModuleWait();
    void setSignal(std::string _signal);
    std::string getSignal() const;
    void setAttribute(std::string _attribute);
    std::string getAttribute() const;
    void setNumEntitiesToRelease(unsigned int _numEntitiesToRelease);
    unsigned int getNumEntitiesToRelease() const;
    std::list<Entity*>* getQueue() const;
protected:
    virtual void do_run(Entity* entity);
private:
    std::string _signal;
    std::string _attribute;
    unsigned int _numEntitiesToRelease;
    std::list<Entity*>* _queue;
};

#endif	/* MODULEWAIT_H */

