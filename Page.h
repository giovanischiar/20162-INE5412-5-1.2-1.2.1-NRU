/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Page.h
 * Author: giovani
 *
 * Created on 23 de Outubro de 2016, 02:43
 */

#ifndef PAGE_H
#define PAGE_H

#include "Traits.h"

typedef HW_MMU::LogicalAddress LogicalAddress;
typedef HW_MMU::Information Information;
#define PAGESIZE_IN_WORDS (Traits<MemoryManager>::pageSize/sizeof(Information))

class Page {
public:
    Page(LogicalAddress base, Information (& data)[PAGESIZE_IN_WORDS], bool isReadable, bool isWritable, bool isExecutable);
    Page(const Page& orig);
    virtual ~Page();
    bool isIsExecutable() const;
    bool isIsWritable() const;
    bool isIsReadable() const;
    Information const * getData() const;
    Information getValue(unsigned int index) const;
    LogicalAddress getBase() const;
private:
    Information data[PAGESIZE_IN_WORDS];
    LogicalAddress base;
    bool isReadable;
    bool isWritable;
    bool isExecutable;

};

#endif /* PAGE_H */

