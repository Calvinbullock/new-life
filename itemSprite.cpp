/* ================================================
* Author: Calvin Bullock
*
* Contains the implementations of ItemSprite 
*     functions.
================================================ */

#include "itemSprite.h"

#include <iostream> // DEBUGing
#define DEBUG std::cout << " DEBUG: L" << __LINE__ << " "

ItemSprite::ItemSprite(std::string texturePath, float startX, float startY)
    : texture(), sprite(), itemBoundery() {
    if (!SetUpSprite(texturePath))
        return;

    sprite.setPosition(sf::Vector2f(startX, startY));
    itemBoundery = sprite.getGlobalBounds();
}

bool ItemSprite::SetUpSprite(std::string texturePath) {
    if (!texture.loadFromFile(texturePath))
        return false;

    texture.setSmooth(true);
    sprite.setTexture(texture);

    return true;
}

void ItemSprite::SetItemXY(float x, float y) {
    sprite.setPosition(sf::Vector2f(x, y));
}
