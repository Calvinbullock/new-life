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
    void PlayerMove(std::string texturePath, int xDelat, int yDelta);

    sf::Sprite GetSprite()
    {
        return sprite;
    }
};

#endif