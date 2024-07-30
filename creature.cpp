/* ================================================
* Author: Calvin Bullock
*
* This is the cpp for Creature. Where the
*     larger functions are implemented.
================================================ */

#include "creature.h"
#include <vector>

//#include <iostream> // DEBUGing
//#define DEBUG std::cout << " DEBUG: L" << __LINE__ << " "

/* ================================================
*  CONSTRUCTOR FOR PLAYER SPRITE
*
*    pathsToSpriteMovementTexturesIn:
*       should be four paths - {left, right, up, down}
================================================ */
Creature::Creature(float startX,
                   float startY,
                   int baseHealth,
                   int moveAmtIn,
                   std::string pathsToSpriteMovementTexturesIn[])
    : texture(), sprite(), playerBoundery(), moveAmt(), pathsToSpriteMovementTextures(),
      initialHealth(), currentHealth(), faceDirection() {

    initialHealth = baseHealth;
    currentHealth = baseHealth;
    moveAmt = moveAmtIn;

    // move sprite paths from passed in array to class array
    for (int i = 0; i < 4; i++) {
        pathsToSpriteMovementTextures[i] = pathsToSpriteMovementTexturesIn[i];
    }

    // grab the texture facing down and set it at game start
    if (!SetUpSprite(pathsToSpriteMovementTextures[2]))
        return;

    // set starting position of sprite
    sprite.setPosition(sf::Vector2f(startX, startY));
    playerBoundery = sprite.getGlobalBounds();
}

/* ================================================
* SET UP SPRITE
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
* UPDATE PLAYER POSITION
*  Handles movement updates to the player sprite
================================================ */
void Creature::UpdatePostion(std::string texturePath,
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
