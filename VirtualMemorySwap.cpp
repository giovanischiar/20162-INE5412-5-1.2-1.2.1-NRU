/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VirtualMemorySwap.cpp
 * Author: giovani
 * 
 * Created on 22 de Outubro de 2016, 20:45
 */

#include <iostream>

#include "VirtualMemorySwap.h"
#include "Traits.h"
#include <string.h>

VirtualMemorySwap::VirtualMemorySwap() {
    swapArea = new Information[SWAPAREASIZE];
}

void VirtualMemorySwap::fillSwap(List<DataMemoryChunk> chunks) {
    memset(swapArea, 0, Traits<VirtualMemorySwap>::swapAreaSize);
    std::list<DataMemoryChunk>::iterator it;
    int j = 0;
    for(it = chunks.begin(); it != chunks.end(); it++) {
        int size = it->getSize();
        Information* chunkArray = it->getData();
        MemoryChunk* chunk = new MemoryChunk(it->getBeginLogicalAddress(),
                                             it->getSize(), 
                                             it->isIsExecutable(),
                                             it->isIsReadable(),
                                             it->isIsWritable());
        this->chunks.push_back(chunk);
        for(int i = 0; i < size; i++) {
            swapArea[i+j] = chunkArray[i];
        }
        j += size;
    }
}

Page VirtualMemorySwap::getPage(LogicalAddress address) {
    int pageNumber = (int)(address/PAGESIZE);
    int baseAddress = pageNumber * PAGESIZE;
    Information pageData[PAGESIZE];
    int j = 0;
    for(int i = baseAddress; i < baseAddress+PAGESIZE; i++) {
        pageData[j] = swapArea[i];
        j++;
    }
    
    bool isExecutable, isReadable, isWritable;
    for (auto it = chunks.begin(); it != chunks.end(); ++it) {
        MemoryChunk* chunk = *it;
        if (chunk->getBeginLogicalAddress() <= baseAddress && baseAddress < chunk->getBeginLogicalAddress()+chunk->getSize()) {
            isExecutable = chunk->isIsExecutable();
            isReadable = chunk->isIsReadable();
            isWritable = chunk->isIsWritable();
            break;
        }
    }
    
    return Page(baseAddress, pageData, isReadable, isWritable, isExecutable);
}

VirtualMemorySwap::VirtualMemorySwap(const VirtualMemorySwap& orig) {
}

VirtualMemorySwap::~VirtualMemorySwap() {
}

std::vector<MemoryChunk*> VirtualMemorySwap::getChunks() const {
    return chunks;
}

Information* VirtualMemorySwap::getSwapArea() const{
    dumpSwapArea();
    return swapArea;
}

void VirtualMemorySwap::dumpChunks() const {
    std::cout << "Dumping Swap Chunks" << std::endl;
    for (auto it = chunks.begin(); it != chunks.end(); ++it) {
        MemoryChunk* chunk = *it;
        std::cout << "Chunk:" << std::endl;
        std::cout << "base logical address(" << chunk->getBeginLogicalAddress() << ")" << std::endl;
        std::cout << "size(" << chunk->getSize() << ")" << std::endl;
        std::cout << "is executable(" << chunk->isIsExecutable() << ")" << std::endl;
        std::cout << "is readable(" << chunk->isIsReadable() << ")" << std::endl;
        std::cout << "is writable(" << chunk->isIsWritable() << ")" << std::endl;
    }
    std::cout << "Finished Dumping Swap Chunks" << std::endl;
}

void VirtualMemorySwap::dumpSwapArea() const {
    std::cout << "Dumping Swap Area" << std::endl;
    for (int i = 0; i < SWAPAREASIZE; i++) {
        std::cout << "swaparea[" << i << "]" << " = " << swapArea[i] << std::endl;
    }
    std::cout << "Finished Dumping Swap Area" << std::endl;
}