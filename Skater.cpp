//
// Created by Nate Norrie on 2026-10-06.
//

#include "Skater.h"
#include "Player.h"

Skater::Skater(std::string name, int number, const SkaterBaseline& b) : Player(std::move(name), number),
      shootingPer(b.shootingPer),
      shotOnNetPer(b.shotOnNetPer),
      shotsPer60(b.shotsPer60),
      oZoneStartPer(b.oZoneStartPer),
      dZoneStartPer(b.dZoneStartPer),
      toiPer60(b.toiPer60),
      esToiPer60(b.esToiPer60) {}