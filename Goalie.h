//
// Created by Nate Norrie on 2026-10-06.
//

#ifndef HOCKEYSIM_GOALIE_H
#define HOCKEYSIM_GOALIE_H
#include "Player.h"


class Goalie : public player {
    private:

    float savePer;
    float gaa;

    float sSavePer;
    float sGAA;
    float sGoalsSavedAboveX;

    public:


    Goalie();
};


#endif //HOCKEYSIM_GOALIE_H
