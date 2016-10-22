/*
 * File:   ModuleAssign.h
 * Author: cancian
 *
 * Created on October 27, 2015, 9:17 AM
 */

#ifndef MODULEASSIGN_H
#define	MODULEASSIGN_H

#include <map>

#include "Module.h"

class ModuleAssign : public Module {
public:
    ModuleAssign(std::string name, std::map<std::string, std::string>* assignments);
    ModuleAssign(const ModuleAssign& orig);
    virtual ~ModuleAssign();
protected:
    virtual void do_run(Entity* entity);

private:
    std::map<std::string, std::string>* _assignments;
};

#endif	/* MODULEASSIGN_H */

