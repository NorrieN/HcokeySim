//
// Created by Nate Norrie on 2026-10-07.
//

#ifndef HOCKEYSIM_HOCKEYLEAGUEMANAGER_H
#define HOCKEYSIM_HOCKEYLEAGUEMANAGER_H
#include <string>
#include <tuple>
#include <vector>

#include "team.h"

class HockeyLeagueManager {
    public:
    static const std::vector<std::tuple<char, char, char, std::string>>& getTeamNames();
    static const std::vector<std::tuple<char, Team>>& getTeamList();
    static void addNewTeamName(std::tuple<char, char, char, std::string> teamTuple);
    static void addNewTeam(std::tuple<char, Team> teamTuple);
    static bool checkNameID(char NameID);
    static bool checkCityID(char cityID);
    static bool checkTeamID(char teamID);

    private:
    static std::vector<std::tuple<char, char, char, std::string>> teamNames;
    static std::vector<std::tuple<char, Team>> teamList;

    HockeyLeagueManager() = delete;
};


#endif //HOCKEYSIM_HOCKEYLEAGUEMANAGER_H
