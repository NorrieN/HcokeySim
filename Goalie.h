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
    float goalsSavedAboveX;

    float sSavePer;
    float sGAA;
    float sGoalsSavedAboveX;
    float sTimeOnIce;

    public:

    float getSavePer() const;
    float getGAA() const;
    float getGoalsSavedAboveX() const;
    float getSSavePer() const;
    void setSSavePer(float value);
    float getSGAA() const;
    void setSGAA(float value);
    float getSGoalsSavedAboveX() const;
    void setSGoalsSavedAboveX(float value);
    float getTimeOnIce() const;
    void setTimeOnIce(float value);




    Goalie();
};


#endif //HOCKEYSIM_GOALIE_H
