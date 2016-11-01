/* 
 * File:   Statistics.h
 * Author: cancian
 *
 * Created on September 27, 2015, 11:56 AM
 */

#ifndef STATISTICS_H
#define STATISTICS_H

class Statistics {
public:

    static Statistics& getInstance() {
        static Statistics instance;
        return instance;
    }
private:

    Statistics() {
        clearStatistics();
    }

public:
    Statistics(Statistics const&) = delete;
    void operator=(Statistics const&) = delete;

    void clearStatistics();

    void incrementPagesReplaced(int pageClass);
    int pagesReplacedFromClass(int pageClass) const;

    void incrementPageFault();
    void incrementPageHit();
    float pageFaultRate() const;

private:
    int countPagesReplaced[4];
    int countPageFault;
    int countPageHit;
};

#endif /* STATISTICS_H */

