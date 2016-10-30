/*
 * File:   MemoryManager.cpp
 * Authors: INSERT YOUR NAME HERE
 * Strategy: INSERT THE MEMORY MANAGEMENT SCHEMA HERE (THE ALGORITHM YOU ARE IMPLEMENTING -- RANDOMLY GENERATED BY MOODLE AS A VARIATION)
 *
 * Created on ...
 */


#include "Simul_Debug.h"
#include "Abstr_MemoryManager.h"
#include "Simulator.h"
#include "Traits.h"
#include "HW_Machine.h"
#include "OperatingSystem.h"

#include <iostream>

MemoryManager::MemoryManager() {
    _chunks = new std::list<MemoryChunk*>();
    MemoryPartition partition;
    partition.type = FREE;
    partition.baseAddress = 0;
    partition.pageCount = Traits<MemoryManager>::physicalMemorySize / Traits<MemoryManager>::pageSize;
    partitions.push_back(partition);
}

MemoryManager::MemoryManager(const MemoryManager& orig) {
}

MemoryManager::~MemoryManager() {
}

MemoryChunk* MemoryManager::allocateMemory(unsigned int size) {
    Debug::cout(Debug::Level::trace, "MemoryManager::allocateMemory(" + std::to_string(size) + ")");
    // INSERT YOUR CODE TO ALLOCATE MEMORY (A CHUNK) FOR THE PROCESS
    // ...

    return nullptr;
}

void MemoryManager::deallocateMemory(MemoryChunk* chunk) {
    Debug::cout(Debug::Level::trace, "MemoryManager::deallocateMemory(" + std::to_string(reinterpret_cast<unsigned long> (chunk)) + ")");
    // INSERT YOUR CODE TO DEALLOCATE MEMORY (A CHUNK) OF THE PROCESS
    // ...


}

unsigned int MemoryManager::getNumMemoryChunks() {
    // INSERT YOUR CODE TO RETURN THE QUANTITY OF ALLOCATED PARTITIONS
    // ...
    return 0; //_chunks->size();
}

MemoryChunk* MemoryManager::getMemoryChunk(unsigned int index) {
    // INSERT YOUR CODE TO RETURN THE PARTITION AT INDEX index
    // ...

    return nullptr; // CHANGE TO THE CORRET RETURN VALUE
}

void MemoryManager::showMemory() {
    // INSERT YOUR CODE TO SHOW THE MEMORY MAP, IN THE FOLLOWING FORMAT
    // <beginAddress>-<endAddress>: <FREE|ALLOCATED> <size> <process id>

    // Exemplo:
    /*
      0-1499:FREE 1500 0
      1500-1999:ALLOCATED 500 2
      2000-2999:ALLOCATED 1000 3
      3000-9999:FREE 7000 0 
      10000-19999:ALLOCATED 10000 7
      20000-1000000:FREE 800000 0 
     */
    //std::cout << "Memory Map:" << std::endl;

    // INSERT YOUR CODE TO SHOW THE MEMORY MAP
    // ...

}

void MemoryManager::handlePageFault(LogicalAddress missedAddress) {
    Page missedPage = virtualSwapArea.getPage(missedAddress);
    PhysicalAddress baseAddress = getFreeAddress();
    if (baseAddress == NO_FREE_ADDRESS) {
        //TODO: NRU;
    }
    for (int i = 0; i < PAGESIZE; i++) {
        HW_Machine::RAM()->write(baseAddress + i, missedPage.getValue(i));
    }
    OperatingSystem::MMU_Mediator()->updatePageTable(missedAddress, baseAddress, missedPage);
}

const std::list<MemoryPartition>& MemoryManager::getPartitions() const {
    return partitions;
}

PhysicalAddress MemoryManager::getFreeAddress() {
    if (partitions.size() == 1 && partitions.begin()->type == PROCESS) {
        return NO_FREE_ADDRESS;
    }

    for (List<MemoryPartition>::iterator freePartition = partitions.begin(); freePartition != partitions.end(); ++freePartition) {
        if (freePartition->type == FREE) {
            PhysicalAddress freeAddress;
            List<MemoryPartition>::iterator last = --partitions.end();
            if (freePartition == partitions.begin()) {
                MemoryPartition newPartition;
                newPartition.type = PROCESS;
                newPartition.baseAddress = freePartition->baseAddress;
                newPartition.pageCount = 1;
                partitions.insert(freePartition, newPartition);

                freePartition->pageCount--;
                freePartition->baseAddress += PAGESIZE;
                if (freePartition->pageCount == 0) {
                    partitions.erase(freePartition);
                }

                freeAddress = newPartition.baseAddress;
            } else if (freePartition == last) {
                List<MemoryPartition>::iterator previousPartition = --freePartition;
                freePartition++;
                previousPartition->pageCount++;

                freePartition->pageCount--;
                freePartition->baseAddress += PAGESIZE;
                if (freePartition->pageCount == 0) {
                    partitions.erase(freePartition);
                }

                freeAddress = previousPartition->baseAddress + (previousPartition->pageCount - 1) * PAGESIZE;
            } else {
                List<MemoryPartition>::iterator previousPartition = --freePartition;
                freePartition++;
                previousPartition->pageCount++;

                freePartition->pageCount--;
                freePartition->baseAddress += PAGESIZE;
                if (freePartition->pageCount == 0) {
                    List<MemoryPartition>::iterator nextPartition = ++freePartition;
                    freePartition--;
                    previousPartition->pageCount += nextPartition->pageCount;
                    partitions.erase(freePartition);
                    partitions.erase(nextPartition);
                }

                freeAddress = previousPartition->baseAddress + (previousPartition->pageCount - 1) * PAGESIZE;
            }
            return freeAddress;
        }
    }

    return NO_FREE_ADDRESS;
}