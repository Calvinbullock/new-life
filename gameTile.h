#include <SFML/Graphics.hpp>

#ifndef GAMETILE_H
#define GAMETILE_H

class GameTile {
public:
    bool isPassable;
    bool isExit;

    sf::Vector2f positions;
    sf::Texture texture;
    sf::Sprite sprite;

    GameTile(std::string, float, float, bool, bool);
    bool SetUpSprite(std::string);
};

#endif