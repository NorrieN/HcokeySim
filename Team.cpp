//
// Created by Nate Norrie on 2026-10-07.
//

#include "Team.h"
#include "Forward.h"
#include "Defence.h"
#include "Goalie.h"
#include <vector>

Team::Team(std::string pTeamName) {
    std::vector<Player> playerList;
    std::string teamName = pTeamName;

    addPlayersToTeam();
}


void Team::addPlayersToTeam() {
    playerList.clear();
    while (playerList.size() < 26) {
        playerList.push_back(Forward());
    }
    while (playerList.size() > 26 && playerList.size() < 40) {
        playerList.push_back(Defence());
    }
    while (playerList.size() > 40 && playerList.size() < 46) {
        playerList.push_back(Goalie());
    }
}
