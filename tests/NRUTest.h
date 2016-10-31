/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   NRUTest.h
 * Author: giovani
 *
 * Created on 30/10/2016, 19:57:35
 */

#ifndef NRUTEST_H
#define NRUTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "../PageTable.h"
#include <list>

class NRUTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(NRUTest);

    CPPUNIT_TEST(testNRUChoosingPageInClass0);
    CPPUNIT_TEST(testNRUChoosingPageInClass1);
    CPPUNIT_TEST(testNRUChoosingPageInClass2);
    CPPUNIT_TEST(testNRUChoosingPageInClass3);

    CPPUNIT_TEST_SUITE_END();

public:
    NRUTest();
    virtual ~NRUTest();
    void setUp();
    void tearDown();

private:
    void createPageTable();

    void testNRUChoosingPageInClass0();
    void testNRUChoosingPageInClass1();
    void testNRUChoosingPageInClass2();
    void testNRUChoosingPageInClass3();

    PageTable* pageTable;

};

#endif /* NRUTEST_H */

