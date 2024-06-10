/* ================================================
* Author: Calvin Bullock
*
* Contains the item sprite, including:
*  Boundaries
*  Texture
*  and sprite
================================================ */

#include <SFML/Graphics.hpp>

// TODO ?
// Not sure if I should just add functions to player and make it more generic
//      or make this class and playerSprite a child of a new entity class or
//      someting else entierly....
//
// This might make the collision logic / function make more sense.... ?

#ifndef ITEMSPRITE_H
#define ITEMSPRITE_H

class ItemSprite {

private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::FloatRect itemBoundery;

public:
    ItemSprite(std::string texturePath, float startX, float startY);
    bool SetUpSprite(std::string texturePath);
    void SetItemXY(float x, float y);
    void ItemMove(std::string texturePath, int xDelta, int yDelta);

    sf::Sprite GetSprite() { return sprite; }

    sf::FloatRect GetBoundery() { return itemBoundery; }
};

#endif
