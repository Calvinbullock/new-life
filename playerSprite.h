#include <SFML/Graphics.hpp>

#ifndef PLAYERSPRITE_H
#define PLAYERSPRITE_H

class PlayerSprite
{
private:
    int moveAmt = 10; // the amount of pixels the player moves with each key press.

    sf::Vector2f positions;
    sf::Texture texture;
    sf::Sprite sprite;

public:
    PlayerSprite(std::string texturePath, float x, float y, int moveAmt);
    bool SetUpSprite(std::string texturePath);
    void SetPlayerXY(float x, float y);
    void UpdateTexture(std::string texturePath);

    sf::Sprite GetSprite()
    {
        return sprite;
    }
};

#endif