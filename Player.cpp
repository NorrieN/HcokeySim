//
// Created by Nate Norrie on 2026-10-06.
//

#include "player.h"

#include <string>

#pragma once

using namespace std;

Player::Player(std::string iPName, int iPNumber)
    :  pName(iPName), pNumber(iPNumber){}


std::string Player::getName() const {
    return pName;
}

int Player::getNumber() const {
    return pNumber;
}

