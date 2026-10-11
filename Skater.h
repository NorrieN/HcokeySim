//
// Created by Nate Norrie on 2026-10-06.
//

#ifndef HOCKEYSIM_SKATER_H
#define HOCKEYSIM_SKATER_H
#include "Player.h"

struct SkaterBaseline {
    float shootingPer = 0.0f;
    float shotOnNetPer = 0.0f;
    float shotsPer60 = 0.0f;
    float oZoneStartPer = 0.0f;
    float dZoneStartPer = 0.0f;
    float toiPer60 = 0.0f;
    float esToiPer60 = 0.0f;
};

class Skater: public Player {
    private:
    //TODO: stats for speed, endurance, fatigue type stuff. faceoff percentage, physicality,

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
    float sShootingPer = 0.0f;
    // percentage of shots a player takes that make it on net
    float sShotOnNetPer = 0.0f;
    // average number of shots per 60 minutes
    float sShotsPer60 = 0.0f;

    // seasonal stats for player usage

    // offencive zone starts percentage
    float sOZoneStartPer = 0.0f;
    // defencive zone starts percentage
    float sDZoneStartPer = 0.0f;
    // time on ice per 60 minutes
    float sToiPer60 = 0.0f;
    // even strength time of ice per 60 minutes
    float sEsToiPer60 = 0.0f;


    public:

    Skater(std::string name, int number, const SkaterBaseline& baseline);

    float getShootingPer();
    float getShotOnNetPer();
    float getShotsPer60();

    float getOZoneStartPer();
    float getDZoneStartPer();
    float getToiPer60();
    float getEsToiPer60();

    float getSShootingPer();
    void setSShootingPer(float value);
    float getSShotOnNetPer();
    void setSShotOnNetPer(float value);
    float getSShotsPer60();
    void setSShotsPer60(float value);

    float getSOZoneStartsPer();
    void setSOZoneStartsPer(float value);
    float getSDZoneStartPer();
    void setSDZoneStartPer(float value);
    float getSToiPer60();
    void setSToiPer60(float value);
    float getSEsToiPer60();
    void setSEsToiPer60(float value);


    Skater();
};


#endif //HOCKEYSIM_SKATER_H
