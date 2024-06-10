/* ================================================
* Author: Calvin Bullock
*
* This is the header file for item. Item is the 
*     parent class for game items with abilities.
*     Ex: keys, doors, weapons, etc
================================================ */

#include <SFML/Graphics.hpp>

#ifndef ITEM_H
#define ITEM_H

class Item {

public:
    Item(std::string texturePath, float startX, float startY);
    sf::Sprite GetSprite();

    void itemActionTest(sf::FloatRect playerBoundery);

    void itemAction();

private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::FloatRect itemBoundery;

    bool SetUpSprite(std::string texturePath);
};

#endif
