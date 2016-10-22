/*
 * File:   ModuleDelay.cpp
 * Author: cancian
 *
 * Created on September 27, 2015, 7:46 PM
 */

#include "ModuleDelay.h"
#include "Simulator.h"
#include "Simul_Debug.h"

ModuleDelay::ModuleDelay(std::string name, std::string delayTime) : Module(name) {
    _delayTime = delayTime;
}

ModuleDelay::ModuleDelay(const ModuleDelay& orig) : Module(orig) {
}

ModuleDelay::~ModuleDelay() {
}

void ModuleDelay::setDelayTime(std::string _delayTime) {
    this->_delayTime = _delayTime;
}

std::string ModuleDelay::getDelayTime() const {
    return _delayTime;
}

void ModuleDelay::do_run(Entity* entity) {
    Simulator* simulator = Simulator::getInstance();
    double delay = simulator->parse(this->_delayTime);

    Module* nextModule = *(this->_nextModules->begin());
    simulator->insertEvent(delay + simulator->getTnow(), nextModule, entity);
    Debug::cout(Debug::Level::fine, this, entity, "Entity will wait for " + std::to_string(delay) + " time units");
}