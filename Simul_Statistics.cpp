/* 
 * File:   Statistics.cpp
 * Author: cancian
 * 
 * Created on September 27, 2015, 11:56 AM
 */

#include "Simul_Statistics.h"
#include "Simul_Debug.h"

void Statistics::clearStatistics() {
    countPagesReplaced = 0;
    countPageFault = 0;
    countPageHit = 0;
}

void Statistics::incrementPageFault() {
    Debug::cout(Debug::Level::trace, "Page Fault!");
    ++countPageFault;
}

void Statistics::incrementPageHit() {
    Debug::cout(Debug::Level::trace, "Page Hit!");
    ++countPageHit;
}

void Statistics::incrementPagesReplaced() {
    Debug::cout(Debug::Level::trace, "Page Replaced!");
    ++countPagesReplaced;
}

float Statistics::pageFaultRate() const {
    return ((float) countPageFault) / (countPageFault + countPageHit);
}

int Statistics::pagesReplaced() const {
    return countPagesReplaced;
}
