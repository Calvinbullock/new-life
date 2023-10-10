#include <SFML/Graphics.hpp>

#ifndef ITEM_H
#define ITEM_H

class Item
{

public:
    Item(std::string texturePath, float startX, float startY) : texture(),
                                                                sprite(),
                                                                itemBoundery()
    {
        if (!SetUpSprite(texturePath))
            return;

        sprite.setPosition(sf::Vector2f(startX, startY));
        itemBoundery = sprite.getGlobalBounds();
    }

    void itemAction() {
        // This will be overiden for diffrent (child) items, so that each item can
        //      achive its unique action.
    }

private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::FloatRect itemBoundery;

    bool SetUpSprite(std::string texturePath)
    {
        if (!texture.loadFromFile(texturePath))
            return false;

        texture.setSmooth(true);
        sprite.setTexture(texture);

        return true;
    }
};

#endif