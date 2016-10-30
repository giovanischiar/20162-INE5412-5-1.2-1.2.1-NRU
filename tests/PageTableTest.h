/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   PageTableTest.h
 * Author: giovani
 *
 * Created on 24/10/2016, 03:48:48
 */

#ifndef PAGETABLETEST_H
#define PAGETABLETEST_H

#include <cppunit/extensions/HelperMacros.h>

class PageTableTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(PageTableTest);

    CPPUNIT_TEST(testPageTable);
    CPPUNIT_TEST(testGetPageFrame);
    CPPUNIT_TEST(testSetPageEntry);

    CPPUNIT_TEST_SUITE_END();

public:
    PageTableTest();
    virtual ~PageTableTest();
    void setUp();
    void tearDown();

private:
    void testPageTable();
    void testGetPageFrame();
    void testSetPageEntry();
};

#endif /* PAGETABLETEST_H */

