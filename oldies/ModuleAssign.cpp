/*
 * File:   ModuleAssign.cpp
 * Author: cancian
 *
 * Created on October 27, 2015, 9:17 AM
 */

#include "ModuleAssign.h"
#include "Simulator.h"

ModuleAssign::ModuleAssign(std::string name, std::map<std::string, std::string>* assignments) : Module(name) {
    _assignments = assignments;
}

ModuleAssign::ModuleAssign(const ModuleAssign& orig) : Module(orig) {
}

ModuleAssign::~ModuleAssign() {
}

void ModuleAssign::do_run(Entity* entity) {
    Simulator* simulator = Simulator::getInstance();
}