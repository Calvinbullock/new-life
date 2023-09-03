#include <SFML/Graphics.hpp>
#include "gameWorld.cpp"
#include "gameTile.cpp"
#include "playerSprite.cpp"
#include "tileMap.cpp"

#include <iostream> // DEBUGing

int main()
{
    float windowWidth = 400;
    float windowHeight = 400;
    int moveAmt = 10; // the amount of pixels the player moves with each key press.

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "NewLife");

    PlayerSprite player1 = PlayerSprite("images/protag-up-stand.png", 0, 0);
    TileMap map;
    
    // define the level with an array of tile indices
    const int level[] =
    {
        0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
        1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
        0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
        0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
        0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
        2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
        0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
    };
    
    // Set tile map textures
    if (!map.load("images/tilemap-src.png", sf::Vector2u(32, 32), level, 16, 8))
        return -1;

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
                    player1.PlayerMove("images/protag-up-stand.png", 0, moveAmt);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                {
                    std::cout << "you pushed A" << std::endl;
                    player1.PlayerMove("images/protag-left-stand.png", moveAmt, 0);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                {
                    std::cout << "you pushed S" << std::endl;
                    player1.PlayerMove("images/protag-down-stand.png", -moveAmt, 0);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {
                    std::cout << "you pushed D" << std::endl;
                    player1.PlayerMove("images/protag-right-stand.png", -moveAmt, 0);
                }
            }
        }

        window.clear();
        window.draw(map);
        window.draw(player1.GetSprite());
        window.display();
    }

    return 0;
}

// Compile command
//      g++ *FILE-NAME*.cpp -o *EXACUTABLE-NAME* -lsfml-graphics -lsfml-window -lsfml-system
//  
// Other compile options and flags
//      -ansi -pedantic -Wall -Wextra -Wshadow -Weffc++
//      g++ main.cpp -o newLifeEXE -lsfml-graphics -lsfml-window -lsfml-system
// 
// Refrance videos used:
//      https://www.youtube.com/watch?v=aEDP7uhaiJc&list=PLnEt5PBXuAmvPHLXnYzjR4eP65VsxCQRV&index=9
//      https://www.youtube.com/watch?v=A60oYZK_ptk&list=PLnEt5PBXuAmvPHLXnYzjR4eP65VsxCQRV&index=7
