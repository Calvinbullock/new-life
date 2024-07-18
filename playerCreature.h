/* ================================================
* Author: Calvin Bullock
*
* This is the header for PlayerCreature. This is
*     where the player movement and all player stats
*     are stored. This class is a child of creature.
================================================ */

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

private:
    int moveAmt;
};
