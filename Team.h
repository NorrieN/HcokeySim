//
// Created by Nate Norrie on 2026-10-07.
//

#ifndef HOCKEYSIM_TEAM_H
#define HOCKEYSIM_TEAM_H
#include <list>
#include "player.h"

using namespace std;

class Team {
    private:
    std::list<player> playerList;
    std::string teamName;

    public:

    void addPlayer(player player);
    void removePlayer(player player);
    void getPlayerByNumber(int number);
    void getTeamName();

    Team(std::string teamName);
};


#endif //HOCKEYSIM_TEAM_H
