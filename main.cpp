#include <SFML/Graphics.hpp>
#include "playerSprite.cpp"
#include "tileMap.cpp"
#include "item.cpp"

#include <iostream> // DEBUGing

int main()
{
    float windowWidth = 512;
    float windowHeight = 256;
    int moveAmt = 10; // the amount of pixels the player moves with each key press.

    // PLayer sprite direction textures
    std::string playerUpImg = "images/protag-up-stand.png";
    std::string playerDownImg = "images/protag-down-stand.png";
    std::string playerLeftImg = "images/protag-left-stand.png";
    std::string playerRightImg = "images/protag-right-stand.png";

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "NewLife");
    PlayerSprite player1 = PlayerSprite("images/protag-up-stand.png", 52, 52);
    TileMap caveMap;

    Item sword = Item("images/temp-sword.png", 99, 99);
    
    // **TODO rename this array 
    // define the level with an array of tile indices
    int arr[] = {
        2, 3, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0,
        2, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0,
        2, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0,
        2, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0,
        2, 5, 5, 5, 4, 5, 5, 5, 5, 5, 3, 5, 5, 5, 5, 0,
        2, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0,
        2, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0,
        2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
    };
    std::vector<int> cave(arr, arr + sizeof(arr) / sizeof(arr[0]));

    // if the int in cave[] matches one of these (cavePassable) then it is passable 
    //      by the player sprite. 
    std::vector<int> cavePassable;
    cavePassable.push_back(5);
    cavePassable.push_back(4); 

    // Set tile map textures
    if (!caveMap.load("images/dungon-src.png", sf::Vector2u(32, 32), cave, 16, 8, cavePassable))
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
                    player1.PlayerMove(playerUpImg, 0, -moveAmt, caveMap, 0);
                    sword.itemActionTest(player1.GetBoundery());
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                {
                    std::cout << "you pushed A" << std::endl;
                    player1.PlayerMove(playerLeftImg, -moveAmt, 0, caveMap, 1);
                    sword.itemActionTest(player1.GetBoundery());
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                {
                    std::cout << "you pushed S" << std::endl;
                    player1.PlayerMove(playerDownImg, 0, moveAmt, caveMap, 2);
                    sword.itemActionTest(player1.GetBoundery());
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {
                    std::cout << "you pushed D" << std::endl;
                    player1.PlayerMove(playerRightImg, moveAmt, 0, caveMap, 3);
                    sword.itemActionTest(player1.GetBoundery());
                }
            }
        }

        window.clear();
        window.draw(caveMap);
        window.draw(player1.GetSprite());
        window.draw(sword.GetSprite());
        window.display();
    }

    return 0;
}

// Compile command / flags
//      g++ *FILE-NAME*.cpp -o *EXACUTABLE-NAME* -lsfml-graphics -lsfml-window -lsfml-system
//  
// Other compile options and flags
//      -ansi -pedantic -Wall -Wextra -Wshadow -Weffc++
//      g++ main.cpp -o newLifeEXE -lsfml-graphics -lsfml-window -lsfml-system
// 
// Refrances used:
//      -- gameTile / gameWorld
//      https://www.youtube.com/watch?v=aEDP7uhaiJc&list=PLnEt5PBXuAmvPHLXnYzjR4eP65VsxCQRV&index=9
//      https://www.youtube.com/watch?v=A60oYZK_ptk&list=PLnEt5PBXuAmvPHLXnYzjR4eP65VsxCQRV&index=7
// 
//      -- tileMap
//      https://www.sfml-dev.org/tutorials/2.6/graphics-vertex-array.php