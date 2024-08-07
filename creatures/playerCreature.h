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
                   int baseHealthIn,
                   int moveAmtIn,
                   int atkDmgIn,
                   std::string pathsToSpriteMovementTexturesIn[])
        : Creature(startX, startY, baseHealthIn, moveAmtIn, atkDmgIn, pathsToSpriteMovementTexturesIn) {}

    void Move(TileMap map, std::vector<Item> items);
    void Attack(std::vector<Creature> creatureList);
    void NpcCollision(int dmg, std::vector<Creature> npcList);

private:
};
