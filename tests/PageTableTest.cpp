/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   PageTableTest.cpp
 * Author: giovani
 *
 * Created on 24/10/2016, 03:48:48
 */

#include "PageTableTest.h"
#include "../PageTable.h"
#include "../HW_Machine.h"
#include "../Page.h"
#include <iostream>

CPPUNIT_TEST_SUITE_REGISTRATION(PageTableTest);

PageTableTest::PageTableTest() {
}

PageTableTest::~PageTableTest() {
}

void PageTableTest::setUp() {
}

void PageTableTest::tearDown() {
}

void PageTableTest::testPageTable() {
    PhysicalAddress baseAddress = Traits<HW_MMU>::RAMsize-1;
    int pageCount = 2;
    PageTable pageTable(baseAddress, pageCount);
    for(int i = baseAddress; i > baseAddress-(pageCount*PAGESIZE); i--) {
        CPPUNIT_ASSERT_EQUAL(0U, HW_Machine::RAM()->read(i));
    }
}

void PageTableTest::testGetPageFrame() {
    PhysicalAddress baseAddress = Traits<HW_MMU>::RAMsize-1;
    int pageCount = 2;
    PageTable pageTable(baseAddress, pageCount);
    pageTable.setPageEntry(0, 0x1111, 0x1, 0x1, true, true, false);
    Information info = pageTable.getPageEntry(0);
    std::cout << "info: " << info << std::endl;
    unsigned int frameNumber = (info & HW_MMU_Paging::mask_Frame);
    bool isPageInMemory = (info & HW_MMU_Paging::mask_vality) > 0;
    bool isPageWrittable = (info & HW_MMU_Paging::mask_write) > 0;
    bool isPageReadable = (info & HW_MMU_Paging::mask_read) > 0;
    bool isPageExecutable = (info & HW_MMU_Paging::mask_exec) > 0;
    bool pageM = (info & HW_MMU_Paging::mask_M) > 0;
    bool pageR = (info & HW_MMU_Paging::mask_R) > 0;
    CPPUNIT_ASSERT_EQUAL(0x1111U, frameNumber);
    CPPUNIT_ASSERT_EQUAL(true, isPageInMemory);
    CPPUNIT_ASSERT_EQUAL(true, isPageWrittable);
    CPPUNIT_ASSERT_EQUAL(true, isPageReadable);
    CPPUNIT_ASSERT_EQUAL(false, isPageExecutable);
    CPPUNIT_ASSERT_EQUAL(true, pageM);
    CPPUNIT_ASSERT_EQUAL(true, pageR);
}

void PageTableTest::testSetPageEntry() {
    PhysicalAddress baseAddress = Traits<HW_MMU>::RAMsize-1;
    int pageCount = 2;
    PageTable pageTable(baseAddress, pageCount);
    pageTable.setPageEntry(0, 0x1111, 0x1, 0x1, true, true, false);
    Information info = HW_Machine::RAM()->read(baseAddress);
    std::cout << "info: " << info << std::endl;
    unsigned int frameNumber = (info & HW_MMU_Paging::mask_Frame);
    bool isPageInMemory = (info & HW_MMU_Paging::mask_vality) > 0;
    bool isPageWrittable = (info & HW_MMU_Paging::mask_write) > 0;
    bool isPageReadable = (info & HW_MMU_Paging::mask_read) > 0;
    bool isPageExecutable = (info & HW_MMU_Paging::mask_exec) > 0;
    bool pageM = (info & HW_MMU_Paging::mask_M) > 0;
    bool pageR = (info & HW_MMU_Paging::mask_R) > 0;
    CPPUNIT_ASSERT_EQUAL(0x1111U, frameNumber);
    CPPUNIT_ASSERT_EQUAL(true, isPageInMemory);
    CPPUNIT_ASSERT_EQUAL(true, isPageWrittable);
    CPPUNIT_ASSERT_EQUAL(true, isPageReadable);
    CPPUNIT_ASSERT_EQUAL(false, isPageExecutable);
    CPPUNIT_ASSERT_EQUAL(true, pageM);
    CPPUNIT_ASSERT_EQUAL(true, pageR);
    
    pageTable.setPageEntry(1, 0x0102, 0x0, 0x1, false, false, true);
    Information info1 = HW_Machine::RAM()->read(baseAddress-1);
    std::cout << "info1: " << info1 << std::endl;
    unsigned int frameNumber1 = (info1 & HW_MMU_Paging::mask_Frame);
    bool isPageInMemory1 = (info1 & HW_MMU_Paging::mask_vality) > 0;
    bool isPageWrittable1 = (info1 & HW_MMU_Paging::mask_write) > 0;
    bool isPageReadable1 = (info1 & HW_MMU_Paging::mask_read) > 0;
    bool isPageExecutable1 = (info1 & HW_MMU_Paging::mask_exec) > 0;
    bool pageM1 = (info1 & HW_MMU_Paging::mask_M) > 0;
    bool pageR1 = (info1 & HW_MMU_Paging::mask_R) > 0;
    CPPUNIT_ASSERT_EQUAL(0x0102U, frameNumber1);
    CPPUNIT_ASSERT_EQUAL(true, isPageInMemory1);
    CPPUNIT_ASSERT_EQUAL(false, isPageWrittable1);
    CPPUNIT_ASSERT_EQUAL(false, isPageReadable1);
    CPPUNIT_ASSERT_EQUAL(true, isPageExecutable1);
    CPPUNIT_ASSERT_EQUAL(false, pageM1);
    CPPUNIT_ASSERT_EQUAL(true, pageR1);
}

