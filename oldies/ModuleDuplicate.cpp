/*
 * File:   ModuleDuplicate.cpp
 * Author: cancian
 *
 * Created on October 27, 2015, 8:52 AM
 */

#include "ModuleDuplicate.h"
#include "Simulator.h"

ModuleDuplicate::ModuleDuplicate(std::string name, unsigned int duplicates) : Module(name) {
    _duplicates = duplicates;
}

ModuleDuplicate::ModuleDuplicate(const ModuleDuplicate& orig) : Module(orig) {
}

ModuleDuplicate::~ModuleDuplicate() {
}

void ModuleDuplicate::setDuplicates(unsigned int _duplicates) {
    this->_duplicates = _duplicates;
}

unsigned int ModuleDuplicate::getDuplicates() const {
    return _duplicates;
}

void ModuleDuplicate::do_run(Entity* entity) {
    Simulator* simulator = Simulator::getInstance();
    double tnow = simulator->getTnow();
    std::list<Module*>::iterator it = this->_nextModules->begin();
    Module* nextModule = (*it);
    it++;
    Module* nextModuleDuplicateds = (*it);
    for (unsigned int i = 0; i < _duplicates; i++) {
        Entity* duplicated = simulator->createEntity(entity);
        simulator->insertEvent(tnow, nextModuleDuplicateds, duplicated);
    }
    simulator->insertEvent(tnow, nextModule, entity);
}
