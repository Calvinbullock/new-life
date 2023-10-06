#include <SFML/Graphics.hpp>
#include "tileMap.cpp"

#ifndef PLAYERSPRITE_H
#define PLAYERSPRITE_H

class PlayerSprite
{
private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::FloatRect playerBoundery;

    int initialHealth;
    int currentHealth;

    int faceDirection; // 0 north, 1 e, 2 s, 3 west

public:
    PlayerSprite(std::string texturePath, float startX, float startY);
    bool SetUpSprite(std::string texturePath);
    void SetPlayerXY(float x, float y);
    void PlayerMove(std::string texturePath, int xDelta, int yDelta, TileMap map, int faceDirectionIn);

    sf::Sprite GetSprite()
    {
        return sprite;
    }

    sf::FloatRect GetBoundery()
    {
        return playerBoundery;
    }
};

#endif