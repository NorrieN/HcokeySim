//
// Created by Nate Norrie on 2026-10-06.
//

#ifndef HOCKEYSIM_FORWARD_H
#define HOCKEYSIM_FORWARD_H
#include "Skater.h"
#include <vector>


class Forward : public Skater {
    public:
    using Skater::Skater;
    std::vector<int> randomStats(double mean = 80.0, double stddev = 7.0, int lowerBound = 50, int upperBound = 100);


    Forward();
};


#endif //HOCKEYSIM_FORWARD_H
