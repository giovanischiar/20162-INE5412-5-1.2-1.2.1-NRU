/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HW_MMU_Paging.cpp
 * Author: cancian
 * 
 * Created on 23 de Setembro de 2016, 16:49
 */

#include "HW_MMU_Paging.h"
#include "HW_Machine.h"

#include "Simulator.h"
#include "PageTable.h"
#include "Mediator_MMU.h"
#include "OperatingSystem.h"

HW_MMU_Paging::HW_MMU_Paging() {
    // INSERT YOUR CODE HERE
    // ...

    //    // It will create basic Page Table at top of RAM defining one page in the bottom of the RAM
    //    // This code should be somewhere else (when loading an Application), but it is here for convenience
    //    Information addr = Traits<HW_MMU>::RAMsize-1; // base of Page Table (PT occupies one address)
    //    this->_PTBR = addr;  // by default, PTBR points to the new Page Table
    //    // fill the page table with one page descriptor 
    //    Information data =  (1 << HW_MMU_Paging::off_vality) +  // page is in memory
    //                        (1 << HW_MMU_Paging::off_read) + // page can be read
    //                        (1 << HW_MMU_Paging::off_write) + // page can be write
    //                        (1 << HW_MMU_Paging::off_exec) +  // page can be execute
    //                        (0x0000 << HW_MMU_Paging::off_Frame);  // page is in frame 0
    //    HW_Machine::RAM()->write(addr, data); // load the page descriptor into RAM
    //    // page table (with only one page descriptor) loaded in memory!

}

HW_MMU_Paging::HW_MMU_Paging(const HW_MMU_Paging& orig) {
}

HW_MMU_Paging::~HW_MMU_Paging() {
}

HW_MMU::Register HW_MMU_Paging::readRegister(unsigned int registerNum) {
    switch (registerNum) {
        case LOGICAL_ADDRESS_MISSED_REGISTER:
            return this->_logicalAddressMissed;
        default:
            return 0;
    }
}

void HW_MMU_Paging::writeRegister(unsigned int registerNum, HW_MMU::Register value) {
    switch (registerNum) {
        case LOGICAL_ADDRESS_MISSED_REGISTER:
            this->_logicalAddressMissed = value;
            break;
    }
}

HW_MMU::PhysicalAddress HW_MMU_Paging::translateAddress(HW_MMU::LogicalAddress logical, Operation operation) {
    unsigned int logicalPageNumber = (logical & HW_MMU_Paging::mask_LogicalPage) >> HW_MMU_Paging::off_LogicalPage;
    unsigned int logicalPageOffset = (logical & HW_MMU_Paging::mask_PageOffset) >> HW_MMU_Paging::off_PageOffset;
    Information pageEntry = OperatingSystem::MMU_Mediator()->getPageFrame(logicalPageNumber);

    unsigned int frameNumber = (pageEntry & HW_MMU_Paging::mask_Frame);
    bool isPageInMemory = (pageEntry & HW_MMU_Paging::mask_vality) > 0;

    if (!isPageInMemory) { // page fault
        this->writeRegister(LOGICAL_ADDRESS_MISSED_REGISTER, logical);
        // schedule an event to notify that a page fault just happened
        Simulator* simulator = Simulator::getInstance();
        Entity* entity = simulator->getEntity();
        entity->getAttribute("MethodName")->setValue("MMU::chunk_fault_interrupt_handler()");
        simulator->insertEvent(simulator->getTnow(), HW_Machine::Module_HardwareEvent(), entity);
        return;
    }

    bool hasProtectionError = (!(pageEntry & HW_MMU_Paging::mask_read) && (operation == Operation::Read));
    hasProtectionError |= (!(pageEntry & HW_MMU_Paging::mask_write) && (operation == Operation::Write));

    if (hasProtectionError) {
        // schedule an event to notify that a protection error just happened
        Simulator* simulator = Simulator::getInstance();
        Entity* entity = simulator->getEntity();
        entity->getAttribute("MethodName")->setValue("MMU::protection_error_interrupt_handler()");
        simulator->insertEvent(simulator->getTnow(), HW_Machine::Module_HardwareEvent(), entity);
        return;
    }

    OperatingSystem::MMU_Mediator()->setReferenced(logicalPageNumber, 0x1);
    if (operation == Operation::Write) OperatingSystem::MMU_Mediator()->setModified(logicalPageNumber);
    PhysicalAddress phys = (frameNumber << HW_MMU_Paging::off_LogicalPage) + logicalPageOffset;
    return phys;
}