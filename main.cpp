#include <SFML/Graphics.hpp>
#include "gameWorld.cpp"
#include "gameTile.cpp"

#include <iostream> // DEBUGing

int main()
{
    float windowWidth = 400;
    float windowHeight = 400;
    int playerX = -200;
    int playerY = -50;
    int moveAmt = 10; // the amount of pixels the player moves with each key press.

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "NewLife");

    GameWorld gameWorld = GameWorld();
    sf::Texture playerTexture;
    sf::Sprite playerSprite;

    // Main event / game loop
    while (window.isOpen())
    {
        sf::Event event;
        // checks for input / game events
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed) // Player key entry.
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                {
                    std::cout << "you pushed W" << std::endl;
                    playerY += moveAmt;
                    if (!playerTexture.loadFromFile("images/protag-up-stand.png"))
                        return -1;
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                {
                    std::cout << "you pushed A" << std::endl;
                    playerX += moveAmt;
                    if (!playerTexture.loadFromFile("images/protag-left-stand.png"))
                        return -1;
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                {
                    std::cout << "you pushed S" << std::endl;
                    playerY -= moveAmt;
                    if (!playerTexture.loadFromFile("images/protag-down-stand.png"))
                        return -1;
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {
                    std::cout << "you pushed D" << std::endl;
                    playerX -= moveAmt;
                    if (!playerTexture.loadFromFile("images/protag-right-stand.png"))
                        return -1;
                }
                // set the sprite for the directional texture.
                playerSprite.setTexture(playerTexture);
            }
        }

        window.clear();

        // Draws gameWorld / game map to window buffer
        for (int x = 0; x < gameWorld.gridLength; x++)
        {
            for (int y = 0; y < gameWorld.gridLength; y++)
            {
                window.draw(gameWorld.tiles[x][y]->sprite);
            }
        }

        window.draw(playerSprite);
        playerSprite.setTextureRect(sf::IntRect(playerX, playerY, 500, 400));
        window.display();
        // std::cout << "redraw" << std::endl;
    }

    return 0;
}

// Compile command
// g++ *FILE-NAME*.cpp -o *EXACUTABLE-NAME* -lsfml-graphics -lsfml-window -lsfml-system

// -ansi -pedantic -Wall -Wextra -Wshadow -Weffc++

// g++ main.cpp -o newLifeEXE -lsfml-graphics -lsfml-window -lsfml-system
