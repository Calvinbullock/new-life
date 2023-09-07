#include <SFML/Graphics.hpp>

#ifndef PLAYERSPRITE_H
#define PLAYERSPRITE_H

class PlayerSprite
{
private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::FloatRect boundery;

public:
    PlayerSprite(std::string texturePath, float x, float y);
    bool SetUpSprite(std::string texturePath);
    void SetPlayerXY(float x, float y);
    void PlayerMove(std::string texturePath, int xDelta, int yDelta);

    sf::Sprite GetSprite()
    {
        return sprite;
    }

    sf::FloatRect GetBoundery()
    {
        return boundery;
    }
};

#endif