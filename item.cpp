/* ================================================
* Author: Calvin Bullock
*
* This is the cpp file for item. Item is the
*     parent class for game items with abilities.
*     Ex: keys, doors, weapons, etc.
================================================ */

#include "item.h"
#include <SFML/Graphics.hpp>

#include <iostream> // DEBUGing
#define DEBUG std::cout << " DEBUG: L" << __LINE__ << " "

Item::Item(std::string texturePath, float startX, float startY)
    : texture(), sprite(), itemBoundery() {
    if (!SetUpSprite(texturePath))
        return;

    sprite.setPosition(sf::Vector2f(startX, startY));
    itemBoundery = sprite.getGlobalBounds();
}

void Item::ItemActionTest(sf::FloatRect playerBoundery) {
    if (playerBoundery.intersects(itemBoundery)) {
        std::cout << "CONTACT" << std::endl;
    }
}

bool Item::SetUpSprite(std::string texturePath) {
    if (!texture.loadFromFile(texturePath))
        return false;

    texture.setSmooth(true);
    sprite.setTexture(texture);

    return true;
}
