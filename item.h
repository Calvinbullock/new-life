/* ================================================
* Author: Calvin Bullock
*
* This is the header file for item. Item is the
*     parent class for game items with abilities.
*     Ex: keys, doors, weapons, etc.
================================================ */

#include <SFML/Graphics.hpp>

#ifndef ITEM_H
#define ITEM_H

class Item {

public:
    Item(std::string texturePath, float startX, float startY);

    sf::Sprite GetSprite() { return sprite; }
    sf::FloatRect GetBoundery() { return itemBoundery; }

    void SetItemXY(float x, float y) { sprite.setPosition(sf::Vector2f(x, y)); }

    // This will be overiden for diffrent (child) items, so that each item
    // can achive its unique action.
    void itemAction();
    void ItemActionTest(sf::FloatRect playerBoundery);

private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::FloatRect itemBoundery;

    bool SetUpSprite(std::string texturePath);
};

#endif
