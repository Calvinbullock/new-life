#include "playerSprite.h"
#include <iostream> // DEBUGing

PlayerSprite::PlayerSprite(std::string texturePath, float x, float y) : texture(),
                                                                        sprite(),
                                                                        boundery()
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
    boundery = sprite.getGlobalBounds();

    return true;
}

void PlayerSprite::SetPlayerXY(float x, float y)
{
    sprite.setPosition(sf::Vector2f(x, y));
}

void PlayerSprite::PlayerMove(std::string texturePath, int xDelta, int yDelta)
{
    // colision logic.......
    //      tile colistion,
    //      item colistion,
    //      enemey colistion.
    //      Idea --- Have the tile enemey or item say what it is then a if tree
    //          here based on boundery type
    sf::FloatRect otherBoundery; // TODO how to find other boundery....

    if (boundery.intersects(otherBoundery))
        // move invalid....

        if (!texture.loadFromFile(texturePath))
            return;

    sprite.move(xDelta, yDelta);
}