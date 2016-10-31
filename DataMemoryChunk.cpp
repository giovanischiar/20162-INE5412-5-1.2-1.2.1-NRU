/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DataMemoryChunk.cpp
 * Author: giovani
 * 
 * Created on 23 de Outubro de 2016, 01:59
 */

#include "DataMemoryChunk.h"
#include <algorithm>
#include <iostream>
#include <string.h>

DataMemoryChunk::DataMemoryChunk(LogicalAddress beginAddress, bool isExecutable, bool isReadable, bool isWritable) 
    : MemoryChunk(beginAddress, PAGESIZE_IN_WORDS, isExecutable, isReadable, isWritable)
{
}

DataMemoryChunk::DataMemoryChunk(const DataMemoryChunk& orig) 
    : MemoryChunk(orig)
{
    Information const * origData = orig.getData();
    std::copy(origData, origData+orig.getSize(), this->data);
}

DataMemoryChunk::~DataMemoryChunk() {
}

void DataMemoryChunk::setData(Information* data) {
    std::copy(data, data+PAGESIZE_IN_WORDS, this->data);
}

Information const * DataMemoryChunk::getData() const {
    return this->data;
}

void DataMemoryChunk::setValue(unsigned int index, Information value) {
    if (index >= getSize()) {
        return;
    }
    
    this->data[index] = value;
    std::cout << "set DataMemoryChun.data[" << index << "] = " << value << std::endl;
}