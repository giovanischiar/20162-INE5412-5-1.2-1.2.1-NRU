/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TestApplication.h
 * Author: giovani
 *
 * Created on 31 de Outubro de 2016, 21:22
 */

#ifndef TESTAPPLICATION_H
#define TESTAPPLICATION_H

#include "HW_MMU.h"
#include "DataMemoryChunk.h"

#define INITIAL_ARRAY_ADDRESS   24
#define STARTUP_SECTION_SIZE    PAGESIZE_IN_WORDS

typedef HW_MMU::Operation Operation;

struct MemoryAccess {

    MemoryAccess(LogicalAddress addr, Operation op) {
        this->addr = STARTUP_SECTION_SIZE + addr;
        this->op = op;
        this->valueToWrite = 0;
    }

    MemoryAccess(LogicalAddress addr, Operation op, Information valueToWrite) {
        this->addr = STARTUP_SECTION_SIZE + addr;
        this->op = op;
        this->valueToWrite = valueToWrite;
    }

    MemoryAccess(const MemoryAccess& orig) {
        this->addr = orig.addr;
        this->op = orig.op;
        this->valueToWrite = orig.valueToWrite;
    }
    LogicalAddress addr;
    Operation op;
    Information valueToWrite;
};

class TestApplication {
public:
    TestApplication();
    TestApplication(const TestApplication& orig);
    virtual ~TestApplication();
    
    const std::vector<DataMemoryChunk>& getAddressSpaceChunks() const {
        return addressSpaceChunks;
    }

    const std::vector<MemoryAccess>& getMemoryReferences() const {
        return memoryReferences;
    }

private:
    void createAddressSpace();
    void fillStartupApplicationSection(DataMemoryChunk& chunk);
    void fillChunkData(DataMemoryChunk& chunk, int value);
    void generateMemoryReferences();

    std::vector<DataMemoryChunk> addressSpaceChunks;
    std::vector<MemoryAccess> memoryReferences;
};

#endif /* TESTAPPLICATION_H */

