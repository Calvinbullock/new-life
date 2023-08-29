#include "playerSprite.h"

PlayerSprite::PlayerSprite(std::string texturePath, float x, float y, int moveAmt) : moveAmt(moveAmt),
                                                                                     positions(sf::Vector2f(x, y)),
                                                                                     texture(),
                                                                                     sprite()
{
    if (!SetUpSprite(texturePath))
        return;
    sprite.setPosition(positions);
}

bool PlayerSprite::SetUpSprite(std::string texturePath)
{
    if (!texture.loadFromFile(texturePath))
        return false;
}

void PlayerSprite::SetPlayerXY(float x, float y)
{
    // positions(sf::Vector2f(x, y));
}

void PlayerSprite::PlayerMove(std::string texturePath, int xDelta, int yDelta)
{
    if (!texture.loadFromFile(texturePath))
        return;
}