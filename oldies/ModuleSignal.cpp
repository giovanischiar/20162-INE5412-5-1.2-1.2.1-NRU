/*
 * File:   ModuleSignal.cpp
 * Author: cancian
 *
 * Created on October 11, 2015, 11:50 AM
 */

#include "ModuleSignal.h"
#include "Simulator.h"
#include "Simul_Debug.h"
#include "Module.h"
#include "ModuleWait.h"

ModuleSignal::ModuleSignal(std::string name, std::string signal) : Module(name) {
    this->_signal = signal;
}

ModuleSignal::ModuleSignal(const ModuleSignal& orig) : Module(orig) {
}

ModuleSignal::~ModuleSignal() {
}

void ModuleSignal::setSignal(std::string _signal) {
    this->_signal = _signal;
}

std::string ModuleSignal::getSignal() const {
    return _signal;
}

void ModuleSignal::do_run(Entity* entity) {
    Simulator* simulator = Simulator::getInstance();
    Debug::cout(Debug::Level::info, this, entity, "Sending the signal '" + this->_signal + "'");

    std::list<Module*>* modules = simulator->getModel()->getModules();
    Module* module;
    ModuleWait* waitModule;
    for (std::list<Module*>::iterator it = modules->begin(); it != modules->end(); it++) {
        module = *it;
        // @TODO
        try {
            if (dynamic_cast<ModuleWait*> (module) != nullptr) {
                waitModule = (ModuleWait*) module;
                std::string attribName = waitModule->getAttribute();
                int released = 0;
                if (waitModule->getSignal() == _signal) {
                    for (std::list<Entity*>::iterator it = waitModule->getQueue()->begin(); it != waitModule->getQueue()->end(); it++) {
                        if (released < waitModule->getNumEntitiesToRelease()) {
                            if ((attribName == "") || (entity->getAttribute(attribName)->getValue() == (*it)->getAttribute(attribName)->getValue())) {
                                // found an entity in the wait_module' queue to be forwarded
                                simulator->insertEvent(simulator->getTnow(), *(waitModule->getNextModules()->begin()), (*it)); // forward entity
                                // remove entity from the queue
                                waitModule->getQueue()->erase(it);
                                released++;
                                it = waitModule->getQueue()->begin();
                            }
                        } else {
                            break;
                        }
                    }
                }
            }
        } catch (int ex) {

        }
    }

    Module* nextModule = *(this->_nextModules->begin());
    simulator->insertEvent(simulator->getTnow(), nextModule, entity);
}
