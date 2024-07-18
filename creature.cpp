/* ================================================
* Author: Calvin Bullock
*
* This is the cpp for Creature. Where the 
*     larger functions are implemented.
================================================ */

#include "creature.h"
#include <vector>

#include <iostream> // DEBUGing
#define DEBUG std::cout << " DEBUG: L" << __LINE__ << " "

/* ================================================
*  Sets and stores the player sprite.
================================================ */
bool Creature::SetUpSprite(std::string texturePath) {
    if (!texture.loadFromFile(texturePath))
        return false;

    texture.setSmooth(true);
    sprite.setTexture(texture);

    return true;
}

/* ================================================
*  Handles movement updates to the player sprite
================================================ */
void Creature::UpdatePlayerPostion(std::string texturePath,
                                       int xDelta,
                                       int yDelta,
                                       TileMap map,
                                       int faceDirectionIn) {
    Creature::faceDirection = faceDirectionIn;

    // checks if player sprite is in window bounds
    if (sprite.getPosition().x < 0 || sprite.getPosition().y < 0)
        return; // TODO tie in window height and width from main.

    std::vector<sf::FloatRect> bounderyList = map.GetBounderies();
    int length = bounderyList.size();

    // postion change of Player sprite
    sprite.move(xDelta, yDelta);
    playerBoundery = sprite.getGlobalBounds();

    // Checks for collision with impassable map tiles.
    for (int i = 0; i < length; i++) {
        sf::FloatRect otherBoundery = bounderyList[i];
        bool notPassable = !map.TileIsPassable(i);

        if (playerBoundery.intersects(otherBoundery) && notPassable) {
            sprite.move(-xDelta, -yDelta);
            return;
        }
    }

    if (!texture.loadFromFile(texturePath))
        return; // BUG this return might cause a bug
}

// TODO tie this into PlayerMove - stop the player from moveing during a npc
//      colistion
/* ================================================
*  Checks for collisions between the NPC and
*     player sprites.
================================================ */
void Creature::NpcCollision(int dmg, std::vector<Creature> npcList) {
    int vectorLength = npcList.size();

    for (int i = 0; i < vectorLength; i++) {

        sf::FloatRect playerBound = sprite.getGlobalBounds();
        sf::FloatRect npcBound = npcList[i].GetSprite().getGlobalBounds();

        if (playerBound.intersects(npcBound)) {
            currentHealth = currentHealth - dmg;
            DEBUG << currentHealth << ", " << initialHealth << ", " << dmg
                  << std::endl;
        }
    }
}
