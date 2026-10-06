//
// Created by Nate Norrie on 2026-10-06.
//

#ifndef HOCKEYSIM_PLAYER_H
#define HOCKEYSIM_PLAYER_H
#include <string>

using namespace std;

class player {
private:
    std::string pName;
    int pNumber;

public:
    player(std::string iPName, int iPNumber);
    std::string getName() const;
    int getNumber() const;
};


#endif //HOCKEYSIM_PLAYER_H
