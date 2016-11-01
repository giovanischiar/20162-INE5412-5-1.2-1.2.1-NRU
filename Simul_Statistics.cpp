/* 
 * File:   Statistics.cpp
 * Author: cancian
 * 
 * Created on September 27, 2015, 11:56 AM
 */

#include "Simul_Statistics.h"
#include "Simul_Debug.h"
#include "Simulator.h"
#include <cstring>
#include <sys/time.h>

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

void Statistics::startHandlingPageFault() {
    startPageFault = now();
}

void Statistics::endHandlingPageFault() {
    pageFaultTimes.push_back(now() - startPageFault);
}

double Statistics::averagePageFaultHandlingTime() {
    double sum = 0;
    for (auto it = pageFaultTimes.cbegin(); it != pageFaultTimes.cend(); ++it) {
        sum += *it;
    }
    return sum / pageFaultTimes.size();
}

void Statistics::startPageReplacementAlgorithm() {
    startPageReplacement = now();
}

void Statistics::endPageReplacementAlgorithm() {
    pageReplacementTimes.push_back(now() - startPageReplacement);
}

double Statistics::averagePageReplacementTime() {
    double sum = 0;
    for (auto it = pageReplacementTimes.cbegin(); it != pageReplacementTimes.cend(); ++it) {
        sum += *it;
    }
    return sum / pageReplacementTimes.size();
}

double Statistics::now() {
    struct timeval tp;
    gettimeofday(&tp, NULL);
    long int microseconds = tp.tv_sec * 1000000 + tp.tv_usec;
    return microseconds;
}
