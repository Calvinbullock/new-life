#include "playerSprite.h"
#include "tileMap.cpp"
#include <vector>

#include <iostream> // DEBUGing
#define DEBUG std::cout << " DEBUG: L" << __LINE__ << " "

PlayerSprite::PlayerSprite(std::string texturePath, float startX, float startY) : texture(),
                                                                                  sprite(),
                                                                                  playerBoundery(),
                                                                                  initialHealth(),
                                                                                  currentHealth(),
                                                                                  faceDirection()
{
    if (!SetUpSprite(texturePath))
        return;

    sprite.setPosition(sf::Vector2f(startX, startY));
    playerBoundery = sprite.getGlobalBounds();
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

void PlayerSprite::PlayerMove(
    std::string texturePath,
    int xDelta,
    int yDelta,
    TileMap map,
    int faceDirectionIn)
{
    PlayerSprite::faceDirection = faceDirectionIn;

    // checks if player sprite is in window bounds
    if (sprite.getPosition().x < 0 || sprite.getPosition().y < 0)
        return; // TODO tie in window height and width from main.

    std::vector<sf::FloatRect> bounderyList = map.GetBounderies();
    int length = bounderyList.size();

    // postion change of Player sprite
    sprite.move(xDelta, yDelta);
    playerBoundery = sprite.getGlobalBounds();

    // Checks for colistion with impassable map tiles.
    for (int i = 0; i < length; i++)
    {
        sf::FloatRect otherBoundery = bounderyList[i];
        bool notPassable = !map.TileIsPassable(i);

        if (playerBoundery.intersects(otherBoundery) && notPassable)
        {
            // NOT FULLY BUG FREE......
            DEBUG << "Impassable tile..." << std::endl;
            DEBUG << "PLayer x = " << sprite.getPosition().x << std::endl;
            DEBUG << "Player y = " << sprite.getPosition().y << std::endl;
            DEBUG << "i = " << i << std::endl;
            std::cout << std::endl;

            sprite.move(-xDelta, -yDelta);
            // return;
        }
    }

    if (!texture.loadFromFile(texturePath))
        return; // this return might cause a bug
}