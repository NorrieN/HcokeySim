//
// Created by Nate Norrie on 2026-10-07.
//

#include "HockeyLeagueManager.h"

#include <list>
#include <string>
#include <tuple>

std::list<std::tuple<char, char, std::string>> HockeyLeagueManager::teamNames;

HockeyLeagueManager::HockeyLeagueManager() {
}

void HockeyLeagueManager::addNewTeam(std::tuple<char, char, std::string> teamTuple) {
    teamNames.push_back(teamTuple);
}

bool HockeyLeagueManager::checkCityID(char cityID) {
    //for each city id in list teamNames make sure city id doesnt match and return true if no matches

    return true;
}

bool HockeyLeagueManager::checkNameID(char nameID) {
    //for each name id in list teamNames make sure mname id doesnt match and return true if no matches

    return true;
}
