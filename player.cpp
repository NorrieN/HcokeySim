//
// Created by Nate Norrie on 2026-10-06.
//

#include "player.h"

#include <string>

#pragma once

using namespace std;

player::player(std::string iPName, int iPNumber)
    :  pName(iPName), pNumber(iPNumber){}


std::string player::getName() const {
    return pName;
}

int player::getNumber() const {
    return pNumber;
}
