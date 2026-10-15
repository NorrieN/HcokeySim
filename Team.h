//
// Created by Nate Norrie on 2026-10-07.
//

#ifndef HOCKEYSIM_TEAM_H
#define HOCKEYSIM_TEAM_H
#include <list>
#include <vector>
#include "Player.h"

using namespace std;

class Team {
    private:
    std::vector<Player> playerList;
    std::string teamName;
    void addPlayersToTeam();

    public:

    void addPlayer(Player player);
    void removePlayer(Player player);
    void getPlayerByNumber(int number);
    void getTeamName();

    Team(std::string teamName);
};


#endif //HOCKEYSIM_TEAM_H
