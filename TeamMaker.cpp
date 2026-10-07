//
// Created by Nate Norrie on 2026-10-07.
//
#include <fstream>
#include <iostream>
#include <random>
#include <stdexcept>
#include <vector>
#include <nlohmann/json.hpp>
#include <algorithm>

#include "TeamMaker.h"
#include "HockeyLeagueManager.h"

using json = nlohmann::json;

using NameEntry = std::pair<char, std::string>;

static std::vector<NameEntry> loadNames(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open " + path);
    }

    json data = json::parse(file);

    std::vector<NameEntry> result;
    for (const auto& entry : data) {
        result.emplace_back(entry.at("id").get<char>(),
                            entry.at("name").get<std::string>());
    }
    return result;
}


Team TeamMaker::generateNewTeam(std::string teamName) {
    char cityID = -1;
    char nameID = -1;

    if (teamName == "$$") {

        static const auto cities  = loadNames("NameSegmentFiles/TeamCitySegments.json");
        static const auto mascots = loadNames("NameSegmentFiles/TeamNameSegments.json");
        static std::minstd_rand nameRng{std::random_device{}()};

        std::string cityName;
        std::string mascotName;

        while (cityName.empty()) {
            const auto& pick = cities[std::uniform_int_distribution<size_t>(0, cities.size() - 1)(nameRng)];

            if (HockeyLeagueManager::checkCityID(pick.first)) {

                cityID = pick.first;
                cityName = pick.second;
            }
        }

        while (mascotName.empty()) {
            const auto& pick = mascots[std::uniform_int_distribution<size_t>(0, mascots.size() - 1)(nameRng)];

            if (HockeyLeagueManager::checkNameID(pick.first)) {

                nameID = pick.first;
                mascotName = pick.second;
            }
        }

        teamName = cityName + " " + mascotName;
    }
    else {
        int next = 51;
        for (const auto& t : HockeyLeagueManager::teamNames) {
            next = std::max({next, std::get<0>(t) + 1, std::get<1>(t) + 1});
        }
        cityID = next;
        nameID = next;
    }

    Team newTeam = Team(teamName);
    HockeyLeagueManager::addNewTeam(std::make_tuple(cityID, nameID, teamName));

    return newTeam;
}