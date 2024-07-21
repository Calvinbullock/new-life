/* ================================================
* Author: Calvin Bullock
*
* This is the header for PlayerCreature. This is
*     where the player movement and all player stats
*     are stored. This class is a child of creature.
================================================ */

#pragma once
#include "creature.h"

class PlayerCreature : public Creature {

public:
    PlayerCreature(float startX,
                   float startY,
                   int baseHealth,
                   std::string pathsToSpriteMovementTexturesIn[],
                   int moveAmtIn)
        : Creature(startX, startY, baseHealth, pathsToSpriteMovementTexturesIn),
          moveAmt(moveAmtIn) {}

    void Move(TileMap map, std::vector<Item> items);

    // TODO  FIX warnings -- left off here
    //    cuntinue moveing this into the playerCreature
    void NpcCollision(int dmg, std::vector<Creature> npcList);

private:
    int moveAmt;
};
