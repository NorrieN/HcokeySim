//
// Created by Nate Norrie on 2026-10-07.
//

#ifndef HOCKEYSIM_TEAMMAKER_H
#define HOCKEYSIM_TEAMMAKER_H
#include "Team.h"


class TeamMaker {
    public:

    Team generateNewTeam(std::string teamName = std::string("$$"));

    TeamMaker();
};


#endif //HOCKEYSIM_TEAMMAKER_H
