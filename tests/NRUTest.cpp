/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   NRUTest.cpp
 * Author: giovani
 *
 * Created on 30/10/2016, 19:57:35
 */

#include "NRUTest.h"

#include "../Page.h"
#include "../NRU.h"
#include "../PageReplacementAlgorithm.h"
#include <algorithm>

CPPUNIT_TEST_SUITE_REGISTRATION(NRUTest);

NRUTest::NRUTest() {
}

NRUTest::~NRUTest() {
}

void NRUTest::setUp() {
    createPageTable();
}

void NRUTest::createPageTable() {
    int pageCount = Traits<Process>::maxAddressSpace / Traits<MemoryManager>::pageSize;
    Information addr = Traits<HW_MMU>::RAMsize - 1;
    pageTable = new PageTable(addr, pageCount);

    pageTable->setPageEntry(0, 0x0, 0x0, 0x0, true, true, true, true);
    pageTable->setPageEntry(1, 0x1, 0x0, 0x0, true, false, true, true);
    pageTable->setPageEntry(2, 0x2, 0x0, 0x0, true, false, true, true);
    pageTable->setPageEntry(3, 0x0, 0x0, 0x0, true, false, true, false);
    pageTable->setPageEntry(4, 0x0, 0x0, 0x0, true, false, true, false);
    pageTable->setPageEntry(5, 0x0, 0x0, 0x0, true, false, false, false);
    pageTable->setPageEntry(6, 0x0, 0x0, 0x0, true, false, false, false);
    pageTable->setPageEntry(7, 0x3, 0x0, 0x0, true, false, false, true);
    pageTable->setPageEntry(8, 0x4, 0x0, 0x0, true, true, false, true);
    pageTable->setPageEntry(9, 0x0, 0x0, 0x0, true, true, false, false);
    pageTable->setPageEntry(10, 0x5, 0x0, 0x0, true, true, false, true);
    pageTable->setPageEntry(11, 0x0, 0x0, 0x0, true, true, false, false);
    pageTable->setPageEntry(12, 0x0, 0x0, 0x0, true, true, false, false);
    pageTable->setPageEntry(13, 0x0, 0x0, 0x0, true, true, false, false);
}

void NRUTest::tearDown() {
    delete pageTable;
}

void NRUTest::testNRUChoosingPageInClass0() {
    pageTable->setM(10);
    pageTable->setM(8);
    pageTable->setR(8, 1);
    pageTable->setR(2, 1);
    pageTable->setR(7, 1);
    NRU nru;
    PageToBeReplaced page = nru.findPageToBeReplaced(pageTable);
    CPPUNIT_ASSERT_EQUAL(1, page.pageNumber);
    CPPUNIT_ASSERT_EQUAL(false, page.modified);
}

void NRUTest::testNRUChoosingPageInClass1() {
    pageTable->setM(8);
    pageTable->setM(10);
    pageTable->setR(10, 1);
    pageTable->setR(1, 1);
    pageTable->setR(2, 1);
    pageTable->setR(7, 1);
    NRU nru;
    PageToBeReplaced page = nru.findPageToBeReplaced(pageTable);
    CPPUNIT_ASSERT_EQUAL(8, page.pageNumber);
    CPPUNIT_ASSERT_EQUAL(true, page.modified);
}

void NRUTest::testNRUChoosingPageInClass2() {
    pageTable->setM(8);
    pageTable->setM(10);
    pageTable->setR(8, 1);
    pageTable->setR(10, 1);
    pageTable->setR(1, 1);
    pageTable->setR(2, 1);
    pageTable->setR(7, 1);
    NRU nru;
    PageToBeReplaced page = nru.findPageToBeReplaced(pageTable);
    CPPUNIT_ASSERT_EQUAL(1, page.pageNumber);
    CPPUNIT_ASSERT_EQUAL(false, page.modified);
}

void NRUTest::testNRUChoosingPageInClass3() {
    pageTable->setM(8);
    pageTable->setM(10);
    pageTable->setM(1);
    pageTable->setM(2);
    pageTable->setM(7);
    pageTable->setR(8, 1);
    pageTable->setR(10, 1);
    pageTable->setR(1, 1);
    pageTable->setR(2, 1);
    pageTable->setR(7, 1);
    NRU nru;
    PageToBeReplaced page = nru.findPageToBeReplaced(pageTable);
    CPPUNIT_ASSERT_EQUAL(1, page.pageNumber);
    CPPUNIT_ASSERT_EQUAL(true, page.modified);
}