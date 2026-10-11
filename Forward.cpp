//
// Created by Nate Norrie on 2026-10-06.
//

#include "Forward.h"
#include <random>
#include <cmath>


Forward::Forward() {

}



std::vector<int> Forward::randomStats(double mean, double stddev, int lowerBound, int upperBound) {
    int mean1 = 0;
    std::vector<int> playerStats;
    std::vector<int> means;
    // int offenciveMean = 0;
    // int defenciveMean = 0;
    // int physicalMean = 0;
    // bool checking1 = true;
    // bool checking2 = true;

    static std::mt19937 gen(std::random_device{}());
    std::normal_distribution<double> firstDistribution(mean, stddev);
    while (mean1 >= lowerBound && mean1 <= upperBound) {
        mean1 = static_cast<int>(std::round(firstDistribution(gen)));
    }
    std::normal_distribution<double> secondDistribution(mean1, 6.2);

    while (means.size() < 3) {
        int value = static_cast<int>(std::round(secondDistribution(gen)));
        if (value >= lowerBound && value <= upperBound) {
            means.push_back(value);
        }
    }
    std::normal_distribution<double> oDistribution(means[0], 4.2);
    std::normal_distribution<double> dDistribution(means[1], 4.2);
    std::normal_distribution<double> pDistribution(means[2], 4.2);


    /*
     * [0] vision (avg off and def), [1] hands (off), [2] offencive hockey iq (off), [3] shot (avg off and phy)
     * [4] defencive hockey iq (def), [5] physicality (avg def and phy)
     * [6] agility (phy), speed (phy), [7] toughness (phy), [8] strength (phy), [9] motor (phy), [10] height (phy), [11] weight (phy).
     */

    while (playerStats.size() <= 3) {
        int value = static_cast<int>(std::round(oDistribution(gen)));
        if (value >= lowerBound && value <= upperBound) {
            playerStats.push_back(value);
        }
    }
    bool run = false;
    while (playerStats.size() > 3 && playerStats.size() <= 5) {
        int value = static_cast<int>(std::round(dDistribution(gen)));
        if (value >= lowerBound && value <= upperBound) {
            if (run == false) {
                run = true;
                playerStats[0] = std::round((playerStats[0] + value)/2.0);
                // maybe make it so that instead of taking the average, it keeps the larger of the two values and gets rid of the smaller
            }
            else{
                playerStats.push_back(value);
            }
        }
    }
    bool run1, run2 = false;
    while (playerStats.size() > 5 && playerStats.size() <= 11) {
        int value = static_cast<int>(std::round(pDistribution(gen)));
        if (value >= lowerBound && value <= upperBound) {
            if (run1 == false) {
                run1 = true;
                playerStats[3] = std::round((playerStats[3] + value)/2.0);
                // maybe make it so that instead of taking the average, it keeps the larger of the two values and gets rid of the smaller
            }
            else if (run2 == false) {
                run2 = true;
                playerStats[5] = std::round((playerStats[5] + value)/2.0);
                // maybe make it so that instead of taking the average, it keeps the larger of the two values and gets rid of the smaller
            }
            else {
                playerStats.push_back(value);
            }
        }
    }
    return playerStats;
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
