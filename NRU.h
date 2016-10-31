/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NRU.h
 * Author: giovani
 *
 * Created on 30 de Outubro de 2016, 15:31
 */

#ifndef NRU_H
#define NRU_H

#include "PageReplacementAlgorithm.h"

#define PAGETABLE_PAGE_COUNT 2

class NRU : public PageReplacementAlgorithm {
public:
    NRU();
    NRU(const NRU& orig);
    PageToBeReplaced findPageToBeReplaced(PageTable* pageTable);
    virtual ~NRU();
private:
    
};

#endif /* NRU_H */

