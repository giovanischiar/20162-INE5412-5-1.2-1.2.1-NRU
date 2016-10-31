/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DataMemoryChunk.h
 * Author: giovani
 *
 * Created on 23 de Outubro de 2016, 01:59
 */

#ifndef DATAMEMORYCHUNK_H
#define DATAMEMORYCHUNK_H

#include "Abstr_MemoryChunk.h"
#include "Page.h"

typedef HW_MMU::Information Information;
typedef HW_MMU::LogicalAddress LogicalAddress;

class DataMemoryChunk : public MemoryChunk {
public:
    DataMemoryChunk(LogicalAddress beginAddress, bool isExecutable, bool isReadable, bool isWritable);
    DataMemoryChunk(const DataMemoryChunk& orig);
    virtual ~DataMemoryChunk();
    void setData(Information* data);
    Information const * getData() const;
    void setValue(unsigned int index, Information value);
private:
    Information data[PAGESIZE_IN_WORDS];
};

#endif /* DATAMEMORYCHUNK_H */

