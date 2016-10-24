/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   MemoryManagerTest.h
 * Author: giovani
 *
 * Created on 24/10/2016, 01:08:43
 */

#ifndef MEMORYMANAGERTEST_H
#define MEMORYMANAGERTEST_H

#include <cppunit/extensions/HelperMacros.h>

class MemoryManagerTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(MemoryManagerTest);

    CPPUNIT_TEST(testGetFreeAddress);

    CPPUNIT_TEST_SUITE_END();

public:
    MemoryManagerTest();
    virtual ~MemoryManagerTest();
    void setUp();
    void tearDown();

private:
    void testGetFreeAddress();

};

#endif /* MEMORYMANAGERTEST_H */

