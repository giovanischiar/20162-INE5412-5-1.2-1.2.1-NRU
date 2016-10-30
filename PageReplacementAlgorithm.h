/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PageReplacementAlgorithm.h
 * Author: giovani
 *
 * Created on 30 de Outubro de 2016, 15:26
 */

#ifndef PAGEREPLACEMENTALGORITHM_H
#define PAGEREPLACEMENTALGORITHM_H

#include "HW_MMU.h"
#include "PageTable.h"

struct PageToBeReplaced {
    HW_MMU::PhysicalAddress basePhysicalAddress;
    int pageNumber;
    bool modified;
};

class PageReplacementAlgorithm {
public:
    virtual PageToBeReplaced findPageToBeReplaced(PageTable* pageTable) = 0;

    virtual ~PageReplacementAlgorithm() {
    };
};

#endif /* PAGEREPLACEMENTALGORITHM_H */

