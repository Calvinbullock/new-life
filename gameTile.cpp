#include "gameTile.h"

GameTile::GameTile(std::string textureName, float x, float y, bool passable, bool exit)
{
    /*=================================================*\
    || Constructs a game map tile.                     ||
    ||                                                 ||
    \*=================================================*/
    if (!SetUpSprite(textureName))
    {
        return;
    }

    pos = sf::Vector2f(x, y);
    sprite.setPosition(pos);
    isPassable = passable;
    isExit = exit;
}

bool GameTile::SetUpSprite(std::string textureName)
{
    /*=================================================*\
    || Sets and stores the sprites and textures        ||
    ||                                                 ||
    \*=================================================*/
    sf::Texture texture;
    
    if (!texture.loadFromFile(textureName))
    {
        return false;
    }
    
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
    
    return true;
}