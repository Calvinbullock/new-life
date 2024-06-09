#include "tileMap.cpp"
#include <SFML/Graphics.hpp>

#ifndef PLAYERSPRITE_H
#define PLAYERSPRITE_H

class PlayerSprite {

private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::FloatRect playerBoundery;

    int initialHealth;
    int currentHealth;

    int faceDirection; // 0 north, 1 e, 2 s, 3 west

public:
    PlayerSprite(std::string texturePath,
                 float startX,
                 float startY,
                 int baseHealth);

    bool SetUpSprite(std::string texturePath);
    void PlayerMove(std::string texturePath,
                    int xDelta,
                    int yDelta,
                    TileMap map,
                    int faceDirectionIn);

    void SetPlayerXY(float x, float y) {
        sprite.setPosition(sf::Vector2f(x, y));
    }

    void NpcCollistion(int dmg, std::vector<PlayerSprite> npcList);
    sf::Sprite GetSprite() { return sprite; }
    sf::FloatRect GetBoundery() { return playerBoundery; }
};

#endif
