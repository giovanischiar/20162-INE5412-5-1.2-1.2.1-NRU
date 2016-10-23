/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   VirtualMemorySwapTest.h
 * Author: giovani
 *
 * Created on 23/10/2016, 04:13:54
 */

#ifndef VIRTUALMEMORYSWAPTEST_H
#define VIRTUALMEMORYSWAPTEST_H

#include <cppunit/extensions/HelperMacros.h>

class VirtualMemorySwapTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(VirtualMemorySwapTest);

//    CPPUNIT_TEST(testFillSwapWithEmptyList);
//    CPPUNIT_TEST(testFillSwapWithSingleChunk);
    CPPUNIT_TEST(testFillSwapWithFullChunks);

    CPPUNIT_TEST_SUITE_END();

public:
    VirtualMemorySwapTest();
    virtual ~VirtualMemorySwapTest();
    void setUp();
    void tearDown();

private:
    void testFillSwapWithEmptyList();
    void testFillSwapWithSingleChunk();
    void testFillSwapWithFullChunks();
};

#endif /* VIRTUALMEMORYSWAPTEST_H */

