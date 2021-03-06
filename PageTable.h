/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PageTable.h
 * Author: giovani
 *
 * Created on 23 de Outubro de 2016, 20:41
 */

#ifndef PAGETABLE_H
#define PAGETABLE_H

#include "HW_MMU_Paging.h"
#include "Page.h"

typedef HW_MMU::PhysicalAddress PhysicalAddress;

class PageTable {
public:
    PageTable(PhysicalAddress baseAddress, int pageCount);
    Information getPageEntry(int pageNumber);
    void setPageEntry(int pageNumber, int pageFrame, int M, int R, const Page& page, bool isValid = true);
    void setPageEntry(int pageNumber, int pageFrame, int M, int R, bool isReadable, bool isWritable, bool isExecutable, bool isValid = true);
    PageTable(const PageTable& orig);
    void setM(int pageNumber);
    void setR(int pageNumber, int R);
    void setVality(int pageNumber, int vality);
    virtual ~PageTable();
    int getPageCount();
    void dump();
private:
    PhysicalAddress baseAddress;
    int pageCount;

};

#endif /* PAGETABLE_H */

