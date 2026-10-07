//
// Created by Nate Norrie on 2026-10-06.
//

#ifndef HOCKEYSIM_SKATER_H
#define HOCKEYSIM_SKATER_H
#include "Player.h"

using namespace std;


class Skater: public player {
    private:

    // baseline stats for individual player performance

    // player shooting percentage
    float shootingPer;
    // percentage of shots a player takes that make it on net
    float shotOnNetPer;
    // average number of shots per 60 minutes
    float shotsPer60;

    // baseline stats for player usage

    // offencive zone starts percentage
    float oZoneStartPer;
    // defencive zone starts percentage
    float dZoneStartPer;
    // time on ice per 60 minutes
    float toiPer60;
    // even strength time of ice per 60 minutes
    float esToiPer60;

    // seasonal stats for individual performance

    // player shooting percentage
    float sShootingPer;
    // percentage of shots a player takes that make it on net
    float sShotOnNetPer;
    // average number of shots per 60 minutes
    float sShotsPer60;

    // seasonal stats for player usage

    // offencive zone starts percentage
    float sOZoneStartPer;
    // defencive zone starts percentage
    float sDZoneStartPer;
    // time on ice per 60 minutes
    float sToiPer60;
    // even strength time of ice per 60 minutes
    float sEsToiPer60;


    public:
    float getShootingPer() const;
    float getShotOnNetPer() const;
    float getShotsPer60() const;

    float getOZoneStartPer() const;
    float getDZoneStartPer() const;
    float getToiPer60() const;
    float getEsToiPer60() const;

    float getSShootingPer() const;
    void setSShootingPer(float value) const;
    float getSShotOnNetPer() const;
    void setSShotOnNetPer(float value) const;
    float getSShotsPer60() const;
    void setSShotsPer60(float value);

    float getSOZoneStartsPer() const;
    void setSOZoneStartsPer(float value) const;
    float getSDZoneStartPer() const;
    void setSDZoneStartPer(float value) const;
    float getSToiPer60() const;
    void setSToiPer60(float value) const;
    float getSEsToiPer60() const;
    void setSEsToiPer60(float value) const;


    Skater();
};


#endif //HOCKEYSIM_SKATER_H
