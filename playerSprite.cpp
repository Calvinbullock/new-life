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
    /// TODO collision logic.......
    //      tile colistion,
    //      item colistion,
    //      enemey colistion.
    //      Idea --- Have the tile enemey or item say what it is then a if tree
    //          here based on boundery type

    std::vector<sf::FloatRect> bounderyList = map.GetBounderies();
    int length = bounderyList.size();

    for (int i = 0; i < length; i++)
    {
        sf::FloatRect otherBoundery = bounderyList[i];

        sf::Vector2f currentPoint = sprite.getPosition();
        float nextX = currentPoint.x + xDelta;
        float nextY = currentPoint.y + yDelta;
        sf::Vector2f nextPoint = sf::Vector2f(nextX, nextY);

        // BUG** - the other.Boundery is triggering to offten - find solotion
        std::cout << otherBoundery.contains(nextPoint) << ", i= " << i << std::endl;
        if (otherBoundery.contains(nextPoint) && map.TileIsPassable(i))
        {
            std::cout << "Impassable tile..." << std::endl;
            return;
        }
    }

    if (!texture.loadFromFile(texturePath))
        return;

    sprite.move(xDelta, yDelta);
}