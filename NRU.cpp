/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NRU.cpp
 * Author: giovani
 * 
 * Created on 30 de Outubro de 2016, 15:31
 */

#include "NRU.h"
#include "Simul_Statistics.h"

NRU::NRU() {
}

NRU::NRU(const NRU& orig) {
}

PageToBeReplaced NRU::findPageToBeReplaced(PageTable* pageTable) {
    pageTable->dump();
    std::vector<PageToBeReplaced> class0, class1, class2, class3;
    for (int i = 1; i < pageTable->getPageCount() - PAGETABLE_PAGE_COUNT; i++) {
        Information pageEntry = pageTable->getPageEntry(i);
        bool bitVality = (pageEntry & HW_MMU_Paging::mask_vality) > 0;
        if (!bitVality) {
            continue;
        }

        bool bitM = (pageEntry & HW_MMU_Paging::mask_M) > 0;
        bool bitR = (pageEntry & HW_MMU_Paging::mask_R) > 0;
        PhysicalAddress frameNumber = (pageEntry & HW_MMU_Paging::mask_Frame);
        PhysicalAddress phys = (frameNumber << HW_MMU_Paging::off_LogicalPage);
        PageToBeReplaced page;
        page.basePhysicalAddress = phys;
        page.pageNumber = i;
        page.modified = bitM;

        if (!bitR && !bitM) {
            class0.push_back(page);
        } else if (!bitR && bitM) {
            class1.push_back(page);
        } else if (bitR && !bitM) {
            class2.push_back(page);
        } else {
            class3.push_back(page);
        }
    }

    if (!class0.empty()) {
        Statistics::getInstance().incrementPagesReplaced(0);
        return class0.front();
    }
    if (!class1.empty()) {
        Statistics::getInstance().incrementPagesReplaced(1);
        return class1.front();
    }
    if (!class2.empty()) {
        Statistics::getInstance().incrementPagesReplaced(2);
        return class2.front();
    }

    Statistics::getInstance().incrementPagesReplaced(3);
    return class3.front();
}

NRU::~NRU() {
}

