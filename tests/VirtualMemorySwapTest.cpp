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
    chunk.setValue(50, 123);
    chunks.push_back(chunk);
    
    VirtualMemorySwap swap;
    swap.fillSwap(chunks);
    CPPUNIT_ASSERT(!swap.getChunks().empty());
    Information* swapArea = swap.getSwapArea();
    bool isEmpty = std::all_of(swapArea, swapArea+SWAPAREASIZE, [swapArea](int x){ return x==0; });
    CPPUNIT_ASSERT(!isEmpty);
    
    Page page = swap.getPage(50);
    CPPUNIT_ASSERT(page.isIsExecutable());
    CPPUNIT_ASSERT(!page.isIsReadable());
    CPPUNIT_ASSERT(!page.isIsWritable());
    CPPUNIT_ASSERT_EQUAL(page.getData()[50], (Information)123);
}

