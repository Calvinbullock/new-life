#include "playerSprite.h"
#include <iostream> // DEBUGing

PlayerSprite::PlayerSprite(std::string texturePath, float x, float y) : texture(),
                                                                        sprite()
{
    if (!SetUpSprite(texturePath))
        return;

    sprite.setPosition(sf::Vector2f(x, y));
}

bool PlayerSprite::SetUpSprite(std::string texturePath)
{
    if (!texture.loadFromFile(texturePath))
        return false;

    texture.setSmooth(true);
    sprite.setTexture(texture);

    return true;
}

void PlayerSprite::SetPlayerXY(float x, float y)
{
    sprite.setPosition(sf::Vector2f(x, y));
}

void PlayerSprite::PlayerMove(std::string texturePath, int xDelta, int yDelta)
{
    if (!texture.loadFromFile(texturePath))
        return;

    sprite.move(xDelta, yDelta);
}