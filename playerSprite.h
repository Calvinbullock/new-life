#include "item.cpp"
#include "tileMap.cpp"
#include <SFML/Graphics.hpp>
#include <iostream>

#ifndef PLAYERSPRITE_H
#define PLAYERSPRITE_H

class PlayerSprite {

private:
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
    PlayerSprite(float startX, float startY, int baseHealth, 
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

    sf::Sprite GetSprite() { return sprite; }
    sf::FloatRect GetBoundery() { return playerBoundery; }

    bool SetUpSprite(std::string texturePath);
    void NpcCollistion(int dmg, std::vector<PlayerSprite> npcList);
    void PlayerMove(int moveAmt, TileMap map, std::vector<Item> items);

    void SetPlayerXY(float x, float y) {
        sprite.setPosition(sf::Vector2f(x, y));
    }
};

#endif
