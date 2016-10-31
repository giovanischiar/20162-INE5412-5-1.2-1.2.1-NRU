/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MMU.cpp
 * Author: cancian
 * 
 * Created on 29 de Agosto de 2016, 14:57
 */

#include "Mediator_MMU.h"
#include "HW_Machine.h"
#include "HW_MMU.h"
#include "OperatingSystem.h"
#include "Traits.h"
#include "NRU.h"

MMU::MMU(unsigned int instance) {
    _instance = instance;

    //INSERT YOUR CODE HERE
    //...
    createPageTable(Traits<Process>::maxAddressSpace/Traits<MemoryManager>::pageSize);

    //Adding page entry that references the simulator application code.
    pageTable->setPageEntry(0, 0x0000, 0x0, 0x0, true, true, true);

    HW_Machine::MMU()->writeRegister(1, NO_ADDRESS);
}

MMU::~MMU() {
    if (pageTable) {
        delete pageTable;
    }
}

void MMU::createPageTable(int pageCount) {
    if (pageTable) {
        delete pageTable;
    }

    Information addr = Traits<HW_MMU>::RAMsize - 1;
    pageTable = new PageTable(addr, pageCount);
}

void MMU::protection_error_interrupt_handler() {
    // INSERT YOUR CODE HERE
    // ...
}

void MMU::chunk_fault_interrupt_handler() {
    HW_MMU::LogicalAddress logicalAddressMissed = HW_Machine::MMU()->readRegister(1);
    OperatingSystem::Memory_Manager()->handlePageFault(logicalAddressMissed);
}

void MMU::updatePageTable(int pageNumber, PhysicalAddress baseAddress, Page page) {
    int pageFrame = (baseAddress & HW_MMU_Paging::mask_Frame);
    pageTable->setPageEntry(pageNumber, pageFrame, 0x0, 0x1, page);
    HW_Machine::MMU()->writeRegister(1, NO_ADDRESS);
}

void MMU::setModified(int pageNumber) {
    pageTable->setM(pageNumber);
}

void MMU::setReferenced(int pageNumber, int R) {
    pageTable->setR(pageNumber, R);
}

Information MMU::getPageFrame(int pageNumber) {
    return pageTable->getPageEntry(pageNumber);
}

void MMU::cleanReferenceBits() {
    //queremos ignorar a entrada da página do "SO"
    for (int i = 1; i < (Traits<HW_MMU>::RAMsize / Traits<MemoryManager>::pageSize); i++) {
        setReferenced(i, 0x0);
    }
}

PageToBeReplaced MMU::findPageToBeReplaced() {
    PageReplacementAlgorithm* nru = new NRU();
    PageToBeReplaced pageToBeReplaced = nru->findPageToBeReplaced(pageTable);
    return pageToBeReplaced;
}