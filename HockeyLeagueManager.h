//
// Created by Nate Norrie on 2026-10-07.
//

#ifndef HOCKEYSIM_HOCKEYLEAGUEMANAGER_H
#define HOCKEYSIM_HOCKEYLEAGUEMANAGER_H
#include <string>
#include <tuple>
#include <list>


class HockeyLeagueManager {
    public:
    static std::list<std::tuple<char, char, std::string>> teamNames;
    static void addNewTeam(std::tuple<char, char, std::string> teamTuple);
    static bool checkNameID(char NameID);
    static bool checkCityID(char cityID);

    private:

    HockeyLeagueManager();
};


#endif //HOCKEYSIM_HOCKEYLEAGUEMANAGER_H
