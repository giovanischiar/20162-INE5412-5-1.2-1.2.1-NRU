/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   MemoryManagerTest.cpp
 * Author: giovani
 *
 * Created on 24/10/2016, 01:08:43
 */

#include "MemoryManagerTest.h"
#include "../Abstr_MemoryManager.h"
#include "../Traits.h"
#include "../Page.h"

CPPUNIT_TEST_SUITE_REGISTRATION(MemoryManagerTest);

MemoryManagerTest::MemoryManagerTest() {
}

MemoryManagerTest::~MemoryManagerTest() {
}

void MemoryManagerTest::setUp() {
}

void MemoryManagerTest::tearDown() {
}

void MemoryManagerTest::testGetFreeAddressWithOneMemoryPartitionRequest() {
    MemoryManager memoryManager;
    const List<MemoryPartition>& partitions = memoryManager.getPartitions();
    CPPUNIT_ASSERT(partitions.size() == 1);
    PhysicalAddress result = memoryManager.getFreeAddress();
    CPPUNIT_ASSERT(partitions.size() == 2);
    CPPUNIT_ASSERT_EQUAL((PhysicalAddress)PAGESIZE_IN_WORDS, result);
    CPPUNIT_ASSERT_EQUAL((PhysicalAddress)PAGESIZE_IN_WORDS, partitions.begin()->baseAddress);
    CPPUNIT_ASSERT_EQUAL(1U, partitions.begin()->pageCount);
    CPPUNIT_ASSERT_EQUAL(PartitionType::PROCESS, partitions.begin()->type);
    MemoryPartition nextPartition = *(++partitions.begin());
    CPPUNIT_ASSERT_EQUAL((PhysicalAddress)(2*PAGESIZE_IN_WORDS), nextPartition.baseAddress);
    CPPUNIT_ASSERT_EQUAL((Traits<HW_MMU>::RAMsize / Traits<MemoryManager>::pageSize) - OS_PARTITION_SIZE - PAGETABLE_PARTITION - 1, nextPartition.pageCount);
    CPPUNIT_ASSERT_EQUAL(PartitionType::FREE, nextPartition.type);
}

void MemoryManagerTest::testGetFreeAddressWithLotsOfMemoryPartitionRequest() {
    MemoryManager memoryManager;
    unsigned int count = 3;
    PhysicalAddress result[count];
    for (int i = 0; i < count; i++) {
        result[i] = memoryManager.getFreeAddress();
    }
    const List<MemoryPartition>& partitions = memoryManager.getPartitions();
    CPPUNIT_ASSERT(partitions.size() == 2);
    for (int i = 0; i < count; i++) {
        CPPUNIT_ASSERT_EQUAL((PhysicalAddress) PAGESIZE_IN_WORDS * (i+1), result[i]);
    }
    CPPUNIT_ASSERT_EQUAL((PhysicalAddress) PAGESIZE_IN_WORDS, partitions.begin()->baseAddress);
    CPPUNIT_ASSERT_EQUAL(count, partitions.begin()->pageCount);
    CPPUNIT_ASSERT_EQUAL(PartitionType::PROCESS, partitions.begin()->type);
    MemoryPartition nextPartition = *(++partitions.begin());
    CPPUNIT_ASSERT_EQUAL((PhysicalAddress) ((partitions.begin()->pageCount+1) * PAGESIZE_IN_WORDS), nextPartition.baseAddress);
    CPPUNIT_ASSERT_EQUAL((Traits<HW_MMU>::RAMsize / Traits<MemoryManager>::pageSize) - OS_PARTITION_SIZE - PAGETABLE_PARTITION - count, nextPartition.pageCount);
    CPPUNIT_ASSERT_EQUAL(nextPartition.type, PartitionType::FREE);
}

void MemoryManagerTest::testGetFreeAddressWithFullMemoryPartitionRequest() {
    MemoryManager memoryManager;
    unsigned int count = 5;
    PhysicalAddress result[count];
    for (int i = 0; i < count; i++) {
        result[i] = memoryManager.getFreeAddress();
    }
    const List<MemoryPartition>& partitions = memoryManager.getPartitions();
    CPPUNIT_ASSERT(partitions.size() == 1);
    for (int i = 0; i < count; i++) {
        CPPUNIT_ASSERT_EQUAL((PhysicalAddress) PAGESIZE_IN_WORDS * (i+1), result[i]);
    }
    CPPUNIT_ASSERT_EQUAL((PhysicalAddress) PAGESIZE_IN_WORDS, partitions.begin()->baseAddress);
    CPPUNIT_ASSERT_EQUAL((Traits<HW_MMU>::RAMsize / Traits<MemoryManager>::pageSize) - OS_PARTITION_SIZE - PAGETABLE_PARTITION, partitions.begin()->pageCount);
    CPPUNIT_ASSERT_EQUAL(PartitionType::PROCESS, partitions.begin()->type);
}

void MemoryManagerTest::testGetFreeAddressWithNoFreeAddressMemoryPartitionRequest() {
    MemoryManager memoryManager;
    unsigned int count = 5;
    for (int i = 0; i < count; i++) {
        memoryManager.getFreeAddress();
    }
    CPPUNIT_ASSERT_EQUAL(memoryManager.getFreeAddress(), NO_FREE_ADDRESS);
}