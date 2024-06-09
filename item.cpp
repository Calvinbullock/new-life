#include <SFML/Graphics.hpp>

#include <iostream> // DEBUGing
#define DEBUG std::cout << " DEBUG: L" << __LINE__ << " "

class Item {

public:
    Item(std::string texturePath, float startX, float startY)
        : texture(), sprite(), itemBoundery() {
        if (!SetUpSprite(texturePath))
            return;

        sprite.setPosition(sf::Vector2f(startX, startY));
        itemBoundery = sprite.getGlobalBounds();
    }

    sf::Sprite GetSprite() { return sprite; }

    void itemActionTest(sf::FloatRect playerBoundery) {
        if (playerBoundery.intersects(itemBoundery)) {
            std::cout << "CONTACT" << std::endl;
        }
    }

    // This will be overiden for diffrent (child) items, so that each item
    // can achive its unique action.
    void itemAction();

private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::FloatRect itemBoundery;

    bool SetUpSprite(std::string texturePath) {
        if (!texture.loadFromFile(texturePath))
            return false;

        texture.setSmooth(true);
        sprite.setTexture(texture);

        return true;
    }
};
