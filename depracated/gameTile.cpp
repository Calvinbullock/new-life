#include "gameTile.h"
#include <iostream> // DEBUGING only

GameTile::GameTile(std::string texturePath, float x, float y, bool passable, bool exit) : isPassable(passable),
                                                                                          isExit(exit),
                                                                                          positions(sf::Vector2f(x, y)),
                                                                                          texture(),
                                                                                          sprite()
{
    /*=================================================*\
    || Constructs a game map tile.                     ||
    ||                                                 ||
    \*=================================================*/
    if (!SetUpSprite(texturePath))
    {
        return;
    }
    sprite.setPosition(positions);
}

bool GameTile::SetUpSprite(std::string texturePath)
{
    /*=================================================*\
    || Sets and stores the sprites and textures.       ||
    ||                                                 ||
    \*=================================================*/
    if (!texture.loadFromFile(texturePath))
    {
        return false;
    }

    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, 50, 50));

    return true;
}