/*
 * File:   MemoryManager.h
 * Authors: INSERT YOUR NAME HERE
 * Strategy: INSERT THE MEMORY MANAGEMENT SCHEMA HERE (THE ALGORITHM YOU ARE IMPLEMENTING -- RANDOMLY GENERATED BY MOODLE AS A VARIATION)
 *
 * Created on ...
 */

#ifndef MEMORYMANAGER_H
#define MEMORYMANAGER_H

#include <limits.h> 
#include "Abstr_MemoryChunk.h"
#include "VirtualMemorySwap.h"

//enum MemoryAllocationAlgorithm {FirstFit, NextFit, BestFit, WorstFit};

#define NO_FREE_ADDRESS (UINT_MAX)
#define OS_PARTITION_SIZE (1)
#define PAGETABLE_PARTITION (2)

enum PartitionType {
    PROCESS, FREE
};

typedef struct {
    PartitionType type;
    PhysicalAddress baseAddress;
    unsigned int pageCount;
} MemoryPartition;

class MemoryManager {
    friend class ProblemTester;
public: // do not change
    MemoryManager();
    MemoryManager(const MemoryManager& orig);
    virtual ~MemoryManager();
public: // do not change
    MemoryChunk* allocateMemory(unsigned int size);
    void deallocateMemory(MemoryChunk* chunk);
    void showMemory();
    unsigned int getNumMemoryChunks();
    MemoryChunk* getMemoryChunk(unsigned int index);

    //Test methods
    void fillSwap(const std::vector<DataMemoryChunk>& chunks);
private: // do not change
    std::list<MemoryChunk*>* _chunks;

private: // private attributes and methods
    List<MemoryPartition> partitions;
    VirtualMemorySwap virtualSwapArea;

public:
    PhysicalAddress getFreeAddress();
    void handlePageFault(LogicalAddress missedAddress);
    const std::list<MemoryPartition>& getPartitions() const;
};

#endif /* MEMORYMANAGER_H */

