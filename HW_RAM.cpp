/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HW_RAM.cpp
 * Author: cancian
 * 
 * Created on September 13, 2016, 1:56 PM
 */

#include "HW_RAM.h"
#include "Traits.h"

HW_RAM::HW_RAM() {
    //_ramMemory = new ()
}

HW_RAM::HW_RAM(const HW_RAM& orig) {
}

HW_RAM::~HW_RAM() {
}

HW_RAM::Information HW_RAM::read(HW_RAM::PhysicalAddress address) {
    if (address < Traits<HW_MMU>::RAMsize) {
        return _ramMemory[address];
    } else {
        // error
        Debug::cout(Debug::Level::warning, "ERROR: Reading outside RAM physical address space: "+std::to_string(address));
        return 0;
    }
}

void HW_RAM::write(HW_RAM::PhysicalAddress address, HW_RAM::Information data) {
    if (address < Traits<HW_MMU>::RAMsize) {
        _ramMemory[address] = data;
    } else {
        // error
        Debug::cout(Debug::Level::warning, "ERROR: Writing outside RAM physical address space: "+std::to_string(address));
    }    
}

void HW_RAM::dump() {
    Debug::cout(Debug::Level::trace, "Starting to dump RAM");
    for (int i = 0; i < Traits<HW_MMU>::RAMsize/sizeof(Information); i+=2) {
        Debug::cout(Debug::Level::trace, "RAM[" + std::to_string(i) + "] = " + std::to_string(_ramMemory[i]) + "; RAM[" + std::to_string(i+1) + "] = " + std::to_string(_ramMemory[i+1]));
    }
    Debug::cout(Debug::Level::trace, "Finished to dump RAM");
}
