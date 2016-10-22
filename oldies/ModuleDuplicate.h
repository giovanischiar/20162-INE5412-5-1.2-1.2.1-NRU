/*
 * File:   ModuleDuplicate.h
 * Author: cancian
 *
 * Created on October 27, 2015, 8:52 AM
 */

#ifndef MODULEDUPLICATE_H
#define	MODULEDUPLICATE_H

#include "Module.h"

class ModuleDuplicate : public Module {
public:
    ModuleDuplicate(std::string name, unsigned int duplicates);
    ModuleDuplicate(const ModuleDuplicate& orig);
    virtual ~ModuleDuplicate();
    void setDuplicates(unsigned int _duplicates);
    unsigned int getDuplicates() const;
protected:
    virtual void do_run(Entity* entity);

private:
    unsigned int _duplicates;
};

#endif	/* MODULEDUPLICATE_H */

