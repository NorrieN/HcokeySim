//
// Created by Nate Norrie on 2026-10-07.
//

#include "HockeyLeagueManager.h"
#include "Team.h"

#include <vector>
#include <string>
#include <tuple>

std::vector<std::tuple<char, char, char, std::string>> HockeyLeagueManager::teamNames;
std::vector<std::tuple<char, Team>> HockeyLeagueManager::teamList;

void HockeyLeagueManager::addNewTeamName(std::tuple<char, char, char, std::string> teamTuple) {
    teamNames.push_back(teamTuple);
}

void HockeyLeagueManager::addNewTeam(std::tuple<char, Team> teamTuple) {
    teamList.push_back(teamTuple);
}

bool HockeyLeagueManager::checkCityID(char cityID) {
    for (const auto& team : teamNames) {
        if (cityID == std::get<0>(team)) {
            return false;
        }
    }
    return true;
}

bool HockeyLeagueManager::checkNameID(char nameID) {
    for (const auto& team : teamNames) {
        if (nameID == std::get<1>(team)) {
            return false;
        }
    }
    return true;
}

bool HockeyLeagueManager::checkTeamID(char teamID) {
    for (const auto& team : teamNames) {
        if (teamID == std::get<2>(team)) {
            return false;
        }
    }
    return true;
}

const std::vector<std::tuple<char, char, char, std::string>>& HockeyLeagueManager::getTeamNames() {
    return teamNames;
}

const std::vector<std::tuple<char, Team>>& HockeyLeagueManager::getTeamList() {
    return teamList;
}
