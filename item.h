#include <SFML/Graphics.hpp>

#ifndef ITEM_H
#define ITEM_H

class Item
{

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