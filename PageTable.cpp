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
        HW_Machine::RAM()->write(baseAddress - i, pageEntry);
    }
}

Information PageTable::getPageEntry(int pageNumber) {
    PhysicalAddress pageEntryAddress = baseAddress - pageNumber;
    return HW_Machine::RAM()->read(pageEntryAddress);
}

void PageTable::setPageEntry(int pageNumber, int pageFrame, int M, int R, const Page& page, bool isValid) {
    setPageEntry(pageNumber, pageFrame, M, R, page.isIsReadable(), page.isIsWritable(), page.isIsExecutable(), isValid);
}

void PageTable::setPageEntry(int pageNumber, int pageFrame, int M, int R, bool isReadable, bool isWritable, bool isExecutable, bool isValid) {
    Information pageEntry = (isValid << HW_MMU_Paging::off_vality) +
            (isReadable << HW_MMU_Paging::off_read) +
            (isWritable << HW_MMU_Paging::off_write) +
            (isExecutable << HW_MMU_Paging::off_exec) +
            (M << HW_MMU_Paging::off_M) +
            (R << HW_MMU_Paging::off_R) +
            (pageFrame << HW_MMU_Paging::off_Frame);
    HW_Machine::RAM()->write(baseAddress - pageNumber, pageEntry);
}

void PageTable::setM(int pageNumber) {
    Information newPageEntry = (1 << HW_MMU_Paging::off_M) | getPageEntry(pageNumber);
    HW_Machine::RAM()->write(baseAddress - pageNumber, newPageEntry);
}

void PageTable::setR(int pageNumber, int R) {
    Information newPageEntry;
    if (R) {
        newPageEntry = (1 << HW_MMU_Paging::off_R) | getPageEntry(pageNumber);
    } else {
        newPageEntry = 0xFBFFFFFF & getPageEntry(pageNumber);
    }
    HW_Machine::RAM()->write(baseAddress - pageNumber, newPageEntry);
}

void PageTable::setVality(int pageNumber, int vality) {
    Information newPageEntry;
    if (vality) {
        newPageEntry = (1 << HW_MMU_Paging::off_vality) | getPageEntry(pageNumber);
    } else {
        newPageEntry = 0x7FFFFFFF & getPageEntry(pageNumber);
    }
    HW_Machine::RAM()->write(baseAddress - pageNumber, newPageEntry);
}

int PageTable::getPageCount() {
    return pageCount;
}

PageTable::PageTable(const PageTable& orig) {
}

PageTable::~PageTable() {
}

void PageTable::dump() {
    Debug::cout(Debug::Level::trace, "Printing Page Table:");
    Debug::cout(Debug::Level::trace, "N\tV\tRWE\tMR\tFrame");
    for (int i = 0; i < pageCount; i++) {
        Information pageEntry = HW_Machine::RAM()->read(baseAddress - i);
        int isPageInMemory = (pageEntry & HW_MMU_Paging::mask_vality) > 0;
        int isPageReadable = (pageEntry & HW_MMU_Paging::mask_read) > 0;
        int isPageWrittable = (pageEntry & HW_MMU_Paging::mask_write) > 0;
        int isPageExecutable = (pageEntry & HW_MMU_Paging::mask_exec) > 0;
        int pageM = (pageEntry & HW_MMU_Paging::mask_M) > 0;
        int pageR = (pageEntry & HW_MMU_Paging::mask_R) > 0;
        unsigned int frameNumber = (pageEntry & HW_MMU_Paging::mask_Frame);
        std::string line = std::to_string(i);
        line += "\t" + std::to_string(isPageInMemory);
        line += "\t" + std::to_string(isPageReadable) + std::to_string(isPageWrittable) + std::to_string(isPageExecutable);
        line += "\t" + std::to_string(pageM) + std::to_string(pageR);
        line += "\t" + std::to_string(frameNumber);
        Debug::cout(Debug::Level::trace, line);
    }
}
