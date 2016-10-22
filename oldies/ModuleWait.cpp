/*
 * File:   ModuleWait.cpp
 * Author: cancian
 *
 * Created on October 11, 2015, 11:50 AM
 */

#include "ModuleWait.h"
#include "Simulator.h"
#include "Simul_Debug.h"

ModuleWait::ModuleWait(std::string name, std::string signal, std::string attribute, unsigned int numEntitiesToRelease) : Module(name) {
    _signal = signal;
    _attribute == attribute;
    _numEntitiesToRelease = numEntitiesToRelease;
    _queue = new std::list<Entity*>();
}

ModuleWait::ModuleWait(const ModuleWait& orig) : Module(orig) {
}

ModuleWait::~ModuleWait() {
}

void ModuleWait::setSignal(std::string _signal) {
    this->_signal = _signal;
}

std::string ModuleWait::getSignal() const {
    return _signal;
}

void ModuleWait::setAttribute(std::string _attribute) {
    this->_attribute = _attribute;
}

std::string ModuleWait::getAttribute() const {
    return _attribute;
}

void ModuleWait::setNumEntitiesToRelease(unsigned int _numEntitiesToRelease) {
    this->_numEntitiesToRelease = _numEntitiesToRelease;
}

unsigned int ModuleWait::getNumEntitiesToRelease() const {
    return _numEntitiesToRelease;
}

std::list<Entity*>* ModuleWait::getQueue() const {
    return _queue;
}

void ModuleWait::do_run(Entity* entity) {
    Simulator* simulator = Simulator::getInstance();
    _queue->insert(_queue->end(), entity);
    Debug::cout(Debug::Level::info, this, entity, "Entity is waiting for the signal '" + _signal + "' to be sent forwarding");
}