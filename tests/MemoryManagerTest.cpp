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
    CPPUNIT_ASSERT_EQUAL(result, (PhysicalAddress)0);
    CPPUNIT_ASSERT_EQUAL(partitions.begin()->baseAddress, (PhysicalAddress)0);
    CPPUNIT_ASSERT_EQUAL(partitions.begin()->pageCount, 1U);
    CPPUNIT_ASSERT_EQUAL(partitions.begin()->type, PartitionType::PROCESS);
    MemoryPartition nextPartition = *(++partitions.begin());
    CPPUNIT_ASSERT_EQUAL(nextPartition.baseAddress, (PhysicalAddress)PAGESIZE);
    CPPUNIT_ASSERT_EQUAL(nextPartition.pageCount, Traits<MemoryManager>::physicalMemorySize / Traits<MemoryManager>::pageSize - 1);
    CPPUNIT_ASSERT_EQUAL(nextPartition.type, PartitionType::FREE);
}

void MemoryManagerTest::testGetFreeAddressWithLotsOfMemoryPartitionRequest() {
    MemoryManager memoryManager;
    unsigned int count = 3;
    PhysicalAddress result[count];
    for(int i = 0; i < count; i++) {
        result[i] = memoryManager.getFreeAddress();
    }
    const List<MemoryPartition>& partitions = memoryManager.getPartitions();
    CPPUNIT_ASSERT(partitions.size() == 2);
    for(int i = 0; i < count; i++) {
         CPPUNIT_ASSERT_EQUAL(result[i], (PhysicalAddress)PAGESIZE*i);   
    }
    CPPUNIT_ASSERT_EQUAL(partitions.begin()->baseAddress, (PhysicalAddress)0);
    CPPUNIT_ASSERT_EQUAL(partitions.begin()->pageCount, count);
    CPPUNIT_ASSERT_EQUAL(partitions.begin()->type, PartitionType::PROCESS);
    MemoryPartition nextPartition = *(++partitions.begin());
    CPPUNIT_ASSERT_EQUAL(nextPartition.baseAddress, (PhysicalAddress)(partitions.begin()->pageCount*PAGESIZE));
    CPPUNIT_ASSERT_EQUAL(nextPartition.pageCount, Traits<MemoryManager>::physicalMemorySize / Traits<MemoryManager>::pageSize - count);
    CPPUNIT_ASSERT_EQUAL(nextPartition.type, PartitionType::FREE);
}

void MemoryManagerTest::testGetFreeAddressWithFullMemoryPartitionRequest() {
    MemoryManager memoryManager;
    unsigned int count = 4;
    PhysicalAddress result[count];
    for(int i = 0; i < count; i++) {
        result[i] = memoryManager.getFreeAddress();
    }
    const List<MemoryPartition>& partitions = memoryManager.getPartitions();
    CPPUNIT_ASSERT(partitions.size() == 1);
    for(int i = 0; i < count; i++) {
         CPPUNIT_ASSERT_EQUAL(result[i], (PhysicalAddress)PAGESIZE*i);   
    }
    CPPUNIT_ASSERT_EQUAL(partitions.begin()->baseAddress, (PhysicalAddress)0);
    CPPUNIT_ASSERT_EQUAL(partitions.begin()->pageCount, Traits<MemoryManager>::physicalMemorySize / Traits<MemoryManager>::pageSize);
    CPPUNIT_ASSERT_EQUAL(partitions.begin()->type, PartitionType::PROCESS);
}

void MemoryManagerTest::testGetFreeAddressWithNoFreeAddressMemoryPartitionRequest() {
    MemoryManager memoryManager;
    unsigned int count = 4;
    for(int i = 0; i < count; i++) {
        memoryManager.getFreeAddress();
    }
    CPPUNIT_ASSERT_EQUAL(memoryManager.getFreeAddress(), NO_FREE_ADDRESS);
}
