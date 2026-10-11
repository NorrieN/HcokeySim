//
// Created by Nate Norrie on 2026-10-06.
//

#ifndef HOCKEYSIM_PLAYER_H
#define HOCKEYSIM_PLAYER_H
#include <string>

class Player {
    //TODO: stats for player height, weight, right vs left handed, age

private:
    std::string pName;
    int pNumber;
    int goals;
    int assists;
    int points;
    int gamesPlayed;
    float pointsPerGame;
    float goalsPerGame;
    float assistsPerGame;

public:
    Player(std::string iPName, int iPNumber);
    std::string getName() const;
    int getNumber() const;
    int getGoals() const;
    void setGoals(int value);
    int getAssists() const;
    void setAssists(int value);
    int getPoints() const;
    int getGamesPlayed() const;
    void setGamesPlayed(int value);
    int getPointsPerGame() const;
    int getGoalsPerGame() const;
    int getAssistsPerGame() const;

};


#endif //HOCKEYSIM_PLAYER_H
