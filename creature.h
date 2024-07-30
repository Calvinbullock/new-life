/* ================================================
* Author: Calvin Bullock
*
* This is the header for Creature. This is
*     where the base class for the npc and the player
*     will be laid out.
================================================ */

// TODO Need to clean up mentions of player in this
//    file and in the cpp
//
// Remove sprite from the class name

#pragma once

#include "item.h"
#include "tileMap.cpp"
#include <SFML/Graphics.hpp>
#include <iostream> // for DEBUGING

class Creature {

public:
    /* ================================================
    *  Constructor for playerSprite
    *  Note: pathsToSpriteMovementTexturesIn:
    *       should be four paths in this arr - {left, right, up, down}
    ================================================ */
    Creature(float startX,
             float startY,
             int baseHealth,
             std::string pathsToSpriteMovementTexturesIn[]);

    Creature() {}

    // Copy constructor
    // WARN  compiler no like
    /*Creature(Creature &pSprite)*/
    /*              : texture(pSprite.texture), sprite(pSprite.sprite), */
    /*                playerBoundery(pSprite.playerBoundery),*/
    /*                pathsToSpriteMovementTextures{*/
    /*                    pSprite.pathsToSpriteMovementTextures[0], */
    /*                    pSprite.pathsToSpriteMovementTextures[1],*/
    /*                    pSprite.pathsToSpriteMovementTextures[2],*/
    /*                    pSprite.pathsToSpriteMovementTextures[3]*/
    /*                },*/
    /*                initialHealth(pSprite.initialHealth), */
    /*                currentHealth(pSprite.currentHealth), */
    /*                faceDirection(pSprite.faceDirection) {}*/
    // clang-format on

    // destruct-er
    virtual ~Creature() {}

    sf::Sprite GetSprite() { return sprite; }
    sf::FloatRect GetBoundery() { return playerBoundery; }

    bool SetUpSprite(std::string texturePath);
    void SetPlayerXY(float x, float y) {
        sprite.setPosition(sf::Vector2f(x, y));
    }

    virtual void Move(TileMap map, std::vector<Item> items) {}

protected:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::FloatRect playerBoundery;
    std::string pathsToSpriteMovementTextures[4];

    // add a clean position var
    int initialHealth;
    int currentHealth;

    int faceDirection; // 0 north, 1 e, 2 s, 3 west

    /* ================================================
    *  Private Methods
    ================================================ */
    void UpdatePostion(std::string texturePath,
                             int xDelta,
                             int yDelta,
                             TileMap map,
                             int faceDirectionIn);
};
