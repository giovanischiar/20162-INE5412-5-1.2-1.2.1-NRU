/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VirtualMemorySwap.h
 * Author: giovani
 *
 * Created on 22 de Outubro de 2016, 20:44
 */

#ifndef VIRTUALMEMORYSWAP_H
#define VIRTUALMEMORYSWAP_H

#include <vector>
#include <list>
#include "HW_MMU.h"
#include "Abstr_MemoryChunk.h"

#define List std::list
extern const unsigned int SWAPAREASIZE;

class Page;
class DataMemoryChunk;

class VirtualMemorySwap {
public:
    typedef HW_MMU::Information Information;
    VirtualMemorySwap();
    void fillSwap(const std::vector<DataMemoryChunk>& chunks);
    VirtualMemorySwap(const VirtualMemorySwap& orig);
    Page getPage(HW_MMU::LogicalAddress address);
    void writePage(int pageNumber, Information pageData[]);
    virtual ~VirtualMemorySwap();
    std::vector<MemoryChunk*> getChunks() const;
    Information* getSwapArea() const;
private:
    Information* swapArea;
    std::vector<MemoryChunk*> chunks;
    
    void dumpChunks() const;
    void dumpSwapArea() const;
};

#endif /* VIRTUALMEMORYSWAP_H */

