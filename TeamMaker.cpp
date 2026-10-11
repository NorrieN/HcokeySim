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

template <typename IsFree>
static const NameEntry& pickUnused(const std::vector<NameEntry>& names,
                                   IsFree isFree,
                                   std::minstd_rand& rng) {
    std::vector<const NameEntry*> available;
    for (const auto& n : names) {
        if (isFree(n.first)) {
            available.push_back(&n);
        }
    }

    if (available.empty()) {
        throw std::runtime_error("No unused names left");
    }

    return *available[std::uniform_int_distribution<size_t>(0, available.size() - 1)(rng)];
}

Team TeamMaker::generateNewTeam(std::string teamName) {
    char cityID = -1;
    char nameID = -1;

    if (teamName == "$$") {

        static const auto cities  = loadNames("NameSegmentFiles/TeamCitySegments.json");
        static const auto mascots = loadNames("NameSegmentFiles/TeamNameSegments.json");
        static std::minstd_rand nameRng{std::random_device{}()};

        const NameEntry& city   = pickUnused(cities,  HockeyLeagueManager::checkCityID, nameRng);
        const NameEntry& mascot = pickUnused(mascots, HockeyLeagueManager::checkNameID, nameRng);

        cityID   = city.first;
        nameID   = mascot.first;
        teamName = city.second + " " + mascot.second;
    }
    else {
        int next = 51;
        for (const auto& t : HockeyLeagueManager::getTeamNames()) {
            next = std::max({next, std::get<0>(t) + 1, std::get<1>(t) + 1});
        }
        cityID = static_cast<char>(next);
        nameID = static_cast<char>(next);
    }

    char teamID = 0;
    while (!HockeyLeagueManager::checkTeamID(teamID)) {
        teamID++;
    }

    Team newTeam = Team(teamName);
    HockeyLeagueManager::addNewTeamName(std::make_tuple(cityID, nameID, teamID, teamName));


    return newTeam;
}
