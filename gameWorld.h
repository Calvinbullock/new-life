#include <SFML/Graphics.hpp>
#include "gameTile.h"
#include <vector>

#ifndef GAMEWORLD_H
#define GAMEWORLD_H

class GameWorld
{

public:
    int gridLength; // TODO replace calls to this with the geter
    std::vector<std::vector<GameTile *> > tiles;

    GameWorld();

    int getGridLength()
    {
        return gridLength;
    }

private:
    sf::Vector2i exitPositions;
    sf::Vector2i plyaerPositions;
    std::vector<sf::Vector2i> enemyPostions;

    void setUpInitialState();
    void setUpEnomyPositions();
    void setUpTiles();
};

#endif