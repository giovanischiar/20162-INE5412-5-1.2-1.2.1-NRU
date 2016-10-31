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


DataMemoryChunk::DataMemoryChunk(LogicalAddress beginAddress, unsigned int size, bool isExecutable, bool isReadable, bool isWritable) 
    : MemoryChunk(beginAddress, size, isExecutable, isReadable, isWritable)
{
    data = new Information[size];
    memset(data, 0, size*sizeof(Information));
}

DataMemoryChunk::DataMemoryChunk(const DataMemoryChunk& orig) 
    : MemoryChunk(orig)
{
    data = new Information[orig.getSize()];
    Information* origData = orig.getData();
    std::copy(origData, origData+orig.getSize(), data);
}

DataMemoryChunk::~DataMemoryChunk() {
    if (data) {
        delete[] data;
    }
}

void DataMemoryChunk::setData(Information* data) {
    if (this->data) {
        delete[] this->data;
    }
    this->data = data;
}

Information* DataMemoryChunk::getData() const {
    return data;
}

void DataMemoryChunk::setValue(unsigned int index, Information value) {
    if (index >= getSize()) {
        return;
    }
    
    data[index] = value;
    std::cout << "set DataMemoryChun.data[" << index << "] = " << value << std::endl;
}