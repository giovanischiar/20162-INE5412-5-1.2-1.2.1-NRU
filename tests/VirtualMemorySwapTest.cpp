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
    std::list<DataMemoryChunk> chunks;
    VirtualMemorySwap swap;
    swap.fillSwap(chunks);
    CPPUNIT_ASSERT(swap.getChunks().empty());
    Information* swapArea = swap.getSwapArea();
    bool isEmpty = std::all_of(swapArea, swapArea+SWAPAREASIZE, [swapArea](int x){ return x==0; });
    CPPUNIT_ASSERT(isEmpty);
}

void VirtualMemorySwapTest::testFillSwapWithSingleChunk() {
    std::list<DataMemoryChunk> chunks;
    DataMemoryChunk chunk(0, 2*PAGESIZE, true, false, false);
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
    std::list<DataMemoryChunk> chunks;
    std::cout << "PAGE SIZE: " << PAGESIZE << std::endl;
    int j = 0;
    int pageCount = SWAPAREASIZE/PAGESIZE;
    for(int i = 0; i < pageCount/2; i++) {
        DataMemoryChunk chunk(j, 2*PAGESIZE, true, false, false);
        chunk.setValue(0, i);
        chunk.setValue(PAGESIZE, i);
        chunks.push_back(chunk);
        j += 2*PAGESIZE;
    }
   
    VirtualMemorySwap swap;
    swap.fillSwap(chunks);
    CPPUNIT_ASSERT(!swap.getChunks().empty());
    Information* swapArea = swap.getSwapArea();
    bool isEmpty = std::all_of(swapArea, swapArea+SWAPAREASIZE, [swapArea](int x){ return x==0; });
    CPPUNIT_ASSERT(!isEmpty);
    j = 0;
    for(int i = 0; i < pageCount; i+=2) {
        Page page = swap.getPage(i*PAGESIZE);
        Page page1 = swap.getPage((i*PAGESIZE)+PAGESIZE);
        CPPUNIT_ASSERT(page.isIsExecutable());
        CPPUNIT_ASSERT(!page.isIsReadable());
        CPPUNIT_ASSERT(!page.isIsWritable());
        CPPUNIT_ASSERT(page1.isIsExecutable());
        CPPUNIT_ASSERT(!page1.isIsReadable());
        CPPUNIT_ASSERT(!page1.isIsWritable());
        CPPUNIT_ASSERT_EQUAL(page.getValue(i*PAGESIZE), (Information)(j));
        CPPUNIT_ASSERT_EQUAL(page1.getValue((i*PAGESIZE)+PAGESIZE), (Information)(j));
        j++;
    }
}

