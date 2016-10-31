/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   VirtualMemorySwapTest.cpp
 * Author: giovani
 *
 * Created on 23/10/2016, 04:13:55
 */

#include "VirtualMemorySwapTest.h"
#include "../VirtualMemorySwap.h"
#include "../Page.h"
#include "../DataMemoryChunk.h"
#include <algorithm>
#include <iostream>

CPPUNIT_TEST_SUITE_REGISTRATION(VirtualMemorySwapTest);

VirtualMemorySwapTest::VirtualMemorySwapTest() {
}

VirtualMemorySwapTest::~VirtualMemorySwapTest() {
}

void VirtualMemorySwapTest::setUp() {
}

void VirtualMemorySwapTest::tearDown() {
}

void VirtualMemorySwapTest::testFillSwapWithEmptyList() {
    std::vector<DataMemoryChunk> chunks;
    VirtualMemorySwap swap;
    swap.fillSwap(chunks);
    CPPUNIT_ASSERT(swap.getChunks().empty());
    Information* swapArea = swap.getSwapArea();
    bool isEmpty = std::all_of(swapArea, swapArea+SWAPAREASIZE, [swapArea](int x){ return x==0; });
    CPPUNIT_ASSERT(isEmpty);
}

void VirtualMemorySwapTest::testFillSwapWithSingleChunk() {
    std::vector<DataMemoryChunk> chunks;
    DataMemoryChunk chunk(0, true, false, false);
    chunk.setValue(3, 123);
    chunks.push_back(chunk);
    
    VirtualMemorySwap swap;
    swap.fillSwap(chunks);
    CPPUNIT_ASSERT(!swap.getChunks().empty());
    Information* swapArea = swap.getSwapArea();
    bool isEmpty = std::all_of(swapArea, swapArea+SWAPAREASIZE, [swapArea](int x){ return x==0; });
    CPPUNIT_ASSERT(!isEmpty);
    
    Page page = swap.getPage(3);
    CPPUNIT_ASSERT(page.isIsExecutable());
    CPPUNIT_ASSERT(!page.isIsReadable());
    CPPUNIT_ASSERT(!page.isIsWritable());
    CPPUNIT_ASSERT_EQUAL(page.getValue(3), (Information)123);
}

void VirtualMemorySwapTest::testFillSwapWithFullChunks() {
    std::vector<DataMemoryChunk> chunks;
    int j = 0;
    int pageCount = SWAPAREASIZE/PAGESIZE;
    for(int i = 0; i < pageCount; i++) {
        DataMemoryChunk chunk(j, true, false, false);
        chunk.setValue(0, i);
        chunks.push_back(chunk);
        j += PAGESIZE;
    }
   
    VirtualMemorySwap swap;
    swap.fillSwap(chunks);
    CPPUNIT_ASSERT(!swap.getChunks().empty());
    Information* swapArea = swap.getSwapArea();
    bool isEmpty = std::all_of(swapArea, swapArea+SWAPAREASIZE, [swapArea](int x){ return x==0; });
    CPPUNIT_ASSERT(!isEmpty);
    for(int i = 0; i < pageCount; i++) {
        Page page = swap.getPage(i*Traits<MemoryManager>::pageSize);
        CPPUNIT_ASSERT(page.isIsExecutable());
        CPPUNIT_ASSERT(!page.isIsReadable());
        CPPUNIT_ASSERT(!page.isIsWritable());
        CPPUNIT_ASSERT_EQUAL(page.getValue(i*PAGESIZE), (Information)(i));
    }
}

