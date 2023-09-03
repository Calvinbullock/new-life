#include "playerSprite.h"
#include <iostream> // DEBUGing

PlayerSprite::PlayerSprite(std::string texturePath, float x, float y) : positions(sf::Vector2f(x, y)),
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

    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, 400, 400));
    
    return true;
}

void PlayerSprite::SetPlayerXY(float x, float y)
{
    // positions(sf::Vector2f(x, y));
    positions.x = x;
    positions.y = y;
}

void PlayerSprite::PlayerMove(std::string texturePath, int xDelta, int yDelta)
{
    if (!texture.loadFromFile(texturePath))
        return;
    std::cout << positions.y << ", " << positions.x << std::endl;
    positions.x += xDelta;
    positions.y += yDelta;
    
}