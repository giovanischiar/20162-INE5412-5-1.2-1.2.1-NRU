/* 
 * File:   Statistics.cpp
 * Author: cancian
 * 
 * Created on September 27, 2015, 11:56 AM
 */

#include "Simul_Statistics.h"
#include "Simul_Debug.h"
#include <cstring>

void Statistics::clearStatistics() {
    memset(countPagesReplaced, 0, 4);
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

void Statistics::incrementPagesReplaced(int pageClass) {
    Debug::cout(Debug::Level::trace, "Page Replaced from Class " + std::to_string(pageClass) + "!");
    ++countPagesReplaced[pageClass];
}

float Statistics::pageFaultRate() const {
    return ((float) countPageFault) / (countPageFault + countPageHit);
}

int Statistics::pagesReplacedFromClass(int pageClass) const {
    return countPagesReplaced[pageClass];
}
