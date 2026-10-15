//
// Created by Nate Norrie on 2026-10-06.
//

#ifndef HOCKEYSIM_FORWARD_H
#define HOCKEYSIM_FORWARD_H
#include "Skater.h"
#include <vector>


class Forward : public Skater {
private:
    std::vector<int> stats;

    public:
    using Skater::Skater;
    std::vector<int> randomStats(double mean = 79.5, double stddev = 6.8, int lowerBound = 50, int upperBound = 100);
    std::vector<int> getStats(int index = -1);


    Forward();
};


#endif //HOCKEYSIM_FORWARD_H
