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

protected:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::FloatRect playerBoundery;
    std::string pathsToSpriteMovementTextures[4];

    int initialHealth;
    int currentHealth;

    int faceDirection; // 0 north, 1 e, 2 s, 3 west

    /* ================================================
    *  Private Methods
    ================================================ */
    void UpdatePlayerPostion(std::string texturePath,
                             int xDelta,
                             int yDelta,
                             TileMap map,
                             int faceDirectionIn);

public:
    /* ================================================
    *  Constructor for playerSprite
    *
    *    pathsToSpriteMovementTexturesIn:
    *       should be four paths - {left, right, up, down}
    ================================================ */
    // clang-format off
    Creature(float startX, float startY, int baseHealth, 
                  std::string pathsToSpriteMovementTexturesIn[])
                  : texture(), sprite(), playerBoundery(), 
                    pathsToSpriteMovementTextures(), initialHealth(), 
                    currentHealth(), faceDirection() {
        // clang-format on

        initialHealth = baseHealth;
        currentHealth = baseHealth;

        // move sprite paths from passed in array to class array
        for (int i = 0; i < 4; i++) {
            pathsToSpriteMovementTextures[i] =
                pathsToSpriteMovementTexturesIn[i];
        }

        // grab the texture facing down and set it at game start
        if (!SetUpSprite(pathsToSpriteMovementTextures[2]))
            return;

        // set starting position of sprite
        sprite.setPosition(sf::Vector2f(startX, startY));
        playerBoundery = sprite.getGlobalBounds();
    }

    // destruct-er
    virtual ~Creature() {}

    // clang-format off
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

    sf::Sprite GetSprite() { return sprite; }
    sf::FloatRect GetBoundery() { return playerBoundery; }

    bool SetUpSprite(std::string texturePath);
    void SetPlayerXY(float x, float y) {
        sprite.setPosition(sf::Vector2f(x, y));
    }

    // TODO  FIX warnings
    //    cuntinue moveing this into the playerCreature
   
   
    // TODO move to new playerSprite.h
    void NpcCollision(int dmg, std::vector<Creature> npcList);
    virtual void Move(int moveAmtIn, TileMap map, std::vector<Item> items) {}
};
