#include <SFML/Graphics.hpp>
#include "gameWorld.cpp"
#include "gameTile.cpp"

#include <iostream> // DEBUGING

int main()
{
    float windowWidth = 400;
    float windowHeight = 400;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "NewLife");

    GameWorld gameWorld = GameWorld();

    // Main event / game loop
    while (window.isOpen())
    {
        sf::Event event;
        // checks for input / game events
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
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

        window.display();
    }

    return 0;
}

// Compile command
// g++ *FILE-NAME*.cpp -o *EXACUTABLE-NAME* -lsfml-graphics -lsfml-window -lsfml-system

// -ansi -pedantic -Wall -Wextra -Wshadow -Weffc++

// g++ main.cpp -o newLifeEXE -lsfml-graphics -lsfml-window -lsfml-system
