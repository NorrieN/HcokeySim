//
// Created by Nate Norrie on 2026-10-06.
//

#include "Forward.h"
#include <random>
#include <cmath>


Forward::Forward() {

    std::vector<int> stats = randomStats();

}

static double smoothStddev(double mean, double stddev, int lowerBound, int upperBound) {
    double c = (lowerBound + upperBound) / 2.0;
    double h = (upperBound - lowerBound) / 2.0;
    double z = (mean - c) / h;
    double f = std::sqrt(std::max(0.0, 1.0 - z * z));
    return stddev * std::max(f, 0.25);
}


std::vector<int> Forward::randomStats(double mean, double stddev, int lowerBound, int upperBound) {
    int mean1 = -1;
    std::vector<int> playerStats;

    //==================================================================================================================
    //==================================================================================================================
    // start of first distribution

    static std::mt19937 gen(std::random_device{}());
    std::normal_distribution<double> firstDistribution(mean, stddev);
    while (mean1 < lowerBound || mean1 > upperBound) {
        mean1 = static_cast<int>(std::round(firstDistribution(gen)));
    }

    // end of first distribution
    //==================================================================================================================
    //==================================================================================================================
    // start of second distribution

    double catSD = smoothStddev(mean1, 6.2, lowerBound, upperBound);

    std::normal_distribution<double> offsetDistribution(0.0, catSD);
    double o = offsetDistribution(gen), d = offsetDistribution(gen), p = offsetDistribution(gen);
    double averageD = (o + d + p) / 3.0;

    double means[3] = {
        std::clamp(mean1 + (o-averageD), (double)lowerBound, (double)upperBound),
        std::clamp(mean1 + (d-averageD), (double)lowerBound, (double)upperBound),
        std::clamp(mean1 + (p-averageD), (double)lowerBound, (double)upperBound)
    };

    // end of second distribution
    //==================================================================================================================
    //==================================================================================================================
    // start of third distribution

    const double SQRT2 = std::sqrt(2.0);
    std::normal_distribution<double> oDistribution(means[0], smoothStddev(means[0], 4.2, lowerBound, upperBound));
    std::normal_distribution<double> dDistribution(means[1], smoothStddev(means[1], 4.2, lowerBound, upperBound));
    std::normal_distribution<double> pDistribution(means[2], smoothStddev(means[2], 4.2, lowerBound, upperBound));
    std::normal_distribution<double> oBlend(means[0], smoothStddev(means[0], 4.2, lowerBound, upperBound) * SQRT2);
    std::normal_distribution<double> dBlend(means[1], smoothStddev(means[1], 4.2, lowerBound, upperBound) * SQRT2);
    std::normal_distribution<double> pBlend(means[2], smoothStddev(means[2], 4.2, lowerBound, upperBound) * SQRT2);

    /* [0] vision (avg off and def), [1] hands (off), [2] offencive hockey iq (off), [3] shot (avg off and phy)
     * [4] defencive hockey iq (def), [5] physicality (avg def and phy)
     * [6] agility (phy), [7] speed (phy), [8] toughness (phy), [9] strength (phy), [10] motor (phy), [11] height (phy), [12] weight (phy). */

    while (playerStats.size() <= 3) {
        auto& dist = (playerStats.size() == 0 || playerStats.size() == 3) ? oBlend : oDistribution;
        int value = static_cast<int>(std::round(dist(gen)));
        if (value >= lowerBound && value <= upperBound) {
            playerStats.push_back(value);
        }
    }
    bool run = false;
    while (playerStats.size() > 3 && playerStats.size() <= 5) {
        auto& dist = (!run || playerStats.size() == 5) ? dBlend : dDistribution;
        int value = static_cast<int>(std::round(dist(gen)));
        if (value >= lowerBound && value <= upperBound) {
            if (run == false) {
                run = true;
                playerStats[0] = static_cast<int>(std::round((playerStats[0] + value) / 2.0));
                // maybe make it so that instead of taking the average, it keeps the larger of the two values and gets rid of the smaller
            }
            else{
                playerStats.push_back(value);
            }
        }

    }
    bool run1 = false, run2 = false;
    while (playerStats.size() > 5 && playerStats.size() <= 12) {
        auto& dist = (!run1 || !run2) ? pBlend : pDistribution;

        int value = static_cast<int>(std::round(dist(gen)));
        if (value >= lowerBound && value <= upperBound) {
            if (run1 == false) {
                run1 = true;
                playerStats[3] = static_cast<int>(std::round((playerStats[3] + value) / 2.0));
                // maybe make it so that instead of taking the average, it keeps the larger of the two values and gets rid of the smaller
            }
            else if (run2 == false) {
                run2 = true;
                playerStats[5] = static_cast<int>(std::round((playerStats[5] + value) / 2.0));
                // maybe make it so that instead of taking the average, it keeps the larger of the two values and gets rid of the smaller
            }
            else {
                playerStats.push_back(value);

                if (playerStats.size() == 12) {
                    double z = (value - 79.5) / 9.1;
                    playerStats[11] = std::clamp(static_cast<int>(std::round(186.9 + z * 6.0)), 168, 205);
                }
                else if (playerStats.size() == 13) {
                    double z = (value - 79.5) / 9.1;
                    playerStats[12] = std::clamp(static_cast<int>(std::round(91.2 + z * 8.4)), 75, 125);
                }
            }
        }
    }

    // end of third distribution
    //==================================================================================================================
    //==================================================================================================================

    return playerStats;
}

std::vector<int> Forward::getStats(int index) {
    if (index != -1) {
        std::vector<int> returnValue;
        returnValue.push_back(stats[index]);
        return returnValue;
    }
    return stats;
}



// stats: vision, hands, offencive hockey iq, defencive hockey iq, agility, speed, toughness, shot, strength, physicality, motor, age, height, weight

// player shooting percentage || hands, shot, offencive hockey iq
// percentage of shots a player takes that make it on net || shot, agility
// average number of shots per 60 minutes || offencive hockey iq, speed, motor
// offencive zone starts percentage || offencive hockey iq
// defencive zone starts percentage || defencive hockey iq
// power play time on ice per 60 minutes || strength, motor, offencive hockey iq
// penalty kill time on ice per 60 minutes || strength, motor, defencive hockey iq
// even strength time of ice per 60 minutes || strength, motor
// injury chance per 60 || strength, toughness, physicality, agility, age, height, weight
// High danger chances per 60 || offencive hockey iq, vision, agility, speed
// high danger setups per 60 || offencive hockey iq, vision, hands
// player physicality || toughness, strength, physicality, motor, height, weight, age

// skating speed || speed, motor, age
// skating acceleration || skating speed, motor, strength
