/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PageTable.cpp
 * Author: giovani
 * 
 * Created on 23 de Outubro de 2016, 20:41
 */

#include "PageTable.h"
#include "HW_RAM.h"
#include "HW_Machine.h"

PageTable::PageTable(PhysicalAddress baseAddress, int pageCount) {
    this->pageCount = pageCount;
    this->baseAddress = baseAddress;
    for (int i = 0; i < pageCount; i++) {
        Information pageEntry;
        pageEntry = (0 << HW_MMU_Paging::off_vality) + // page is not in memory
                    (0 << HW_MMU_Paging::off_read) + // page can't be read
                    (0 << HW_MMU_Paging::off_write) + // page can't be written
                    (0 << HW_MMU_Paging::off_exec) + // page can't be executed
                    (0 << HW_MMU_Paging::off_M) + 
                    (0 << HW_MMU_Paging::off_R) +
                    (0x0000 << HW_MMU_Paging::off_Frame); // page is in frame 0
        HW_Machine::RAM()->write(baseAddress-i, pageEntry);
    }
}

Information PageTable::getPageFrame(int pageNumber) {
    PhysicalAddress pageEntryAddress = baseAddress - pageNumber;
    return HW_Machine::RAM()->read(pageEntryAddress);
}

void PageTable::setPageEntry(int pageNumber, int pageFrame, int M, int R, const Page& page) {
    Information pageEntry = (1 << HW_MMU_Paging::off_vality) +
                          (page.isIsReadable() << HW_MMU_Paging::off_read) +
                          (page.isIsWritable() << HW_MMU_Paging::off_write) +
                          (page.isIsExecutable() << HW_MMU_Paging::off_exec) +
                          (M << HW_MMU_Paging::off_M) + 
                          (R << HW_MMU_Paging::off_R) +
                          (pageFrame << HW_MMU_Paging::off_Frame);
    HW_Machine::RAM()->write(baseAddress - pageNumber, pageEntry);
}

void PageTable::setM(int pageNumber) {
    Information newPageEntry = (1 << HW_MMU_Paging::off_M) | getPageFrame(pageNumber);
    HW_Machine::RAM()->write(baseAddress - pageNumber, newPageEntry);
}

void PageTable::setR(int pageNumber, int R) {
    Information newPageEntry = (R << HW_MMU_Paging::off_R) | getPageFrame(pageNumber);
    HW_Machine::RAM()->write(baseAddress - pageNumber, newPageEntry);    
}

int PageTable::getPageCount() {
    return pageCount;
}

PageTable::PageTable(const PageTable& orig) {
}

PageTable::~PageTable() {
}

