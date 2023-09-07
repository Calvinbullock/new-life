#include "playerSprite.h"
#include "tileMap.cpp"
#include <vector>

#include <iostream> // DEBUGing

PlayerSprite::PlayerSprite(std::string texturePath, float x, float y) : texture(),
                                                                        sprite(),
                                                                        boundery()
{
    if (!SetUpSprite(texturePath))
        return;

    sprite.setPosition(sf::Vector2f(x, y));
    boundery = sprite.getGlobalBounds();
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

void PlayerSprite::PlayerMove(std::string texturePath, int xDelta, int yDelta, TileMap map)
{
    // collision logic.......
    //      tile colistion,
    //      item colistion,
    //      enemey colistion.
    //      Idea --- Have the tile enemey or item say what it is then a if tree
    //          here based on boundery type

    std::vector<sf::FloatRect> bounderyList = map.GetBounderies();
    int length = bounderyList.size();
    /// VV**TODO**VV need to be able to get this(isPassable) info for a tile
    bool isPassable; 

    for (int i = 0; i < length; i++)
    {
        sf::FloatRect otherBoundery = bounderyList[i];

        std::cout << "collision checking..." << std::endl;
        if (boundery.intersects(otherBoundery))
        {
            std::cout << "hit impassable tile" << std::endl;
            // return;
        }
    }

    if (!texture.loadFromFile(texturePath))
        return;

    sprite.move(xDelta, yDelta);
}