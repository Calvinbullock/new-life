#include <SFML/Graphics.hpp>
#include "playerSprite.cpp"
#include "tileMap.cpp"
#include "item.cpp"

#include <iostream> // DEBUGing

/*
TODOS
- Make a function that will take a tile index and find the x,y postion for more easy of use
- creat a function to turn the map array into a vector 
*/

int main()
{
    float windowWidth = 512;
    float windowHeight = 256;
    int moveAmt = 16; // the amount of pixels the player moves with each key press.

    // PLayer sprite direction textures
    std::string playerUpImg = "images/protag-up.png";
    std::string playerDownImg = "images/protag-down.png";
    std::string playerLeftImg = "images/protag-left.png";
    std::string playerRightImg = "images/protag-right.png";

    std::string slimeUp = "images/slimeBack.png";
    std::string slimeDown = "images/slimeFront.png";
    std::string slimeLeft = "images/slimeLeft.png";
    std::string slimeRight = "images/slimeRight.png";

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "NewLife");
    PlayerSprite player1 = PlayerSprite(playerDownImg, 52, 52, 100);
    PlayerSprite npcSlime = PlayerSprite(slimeDown, 83, 83, 100);

    // List of all the npcs in a level
    std::vector<PlayerSprite> npcList;
    npcList.push_back(npcSlime);

    TileMap caveMap;

    Item sword = Item("images/temp-sword.png", 99, 99);
    Item topDoor = Item("", 64, 0);

    // TODO this needs to be moved / cleaned up MapObject 2/2
    std::vector<Item> items;
    items.push_back(topDoor);
    items.push_back(sword);

    // TODO rename this array 
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
    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5

    std::vector<int> cave(arr, arr + sizeof(arr) / sizeof(arr[0]));

    // TODO Moved / cleaned up MapObject 2/2
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
            player1.NpcColistion(10, npcList); // TODO add npc list 

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
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                {
                    std::cout << "you pushed A" << std::endl;
                    player1.PlayerMove(playerLeftImg, -moveAmt, 0, caveMap, 1);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                {
                    std::cout << "you pushed S" << std::endl;
                    player1.PlayerMove(playerDownImg, 0, moveAmt, caveMap, 2);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {
                    std::cout << "you pushed D" << std::endl;
                    player1.PlayerMove(playerRightImg, moveAmt, 0, caveMap, 3);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
                {
                    for (int i = 0; i < (int)items.size(); i++)
                    {
                        items[i].itemActionTest(player1.GetBoundery());
                    }
                }
            }
        }

        window.clear();
        window.draw(caveMap);
        window.draw(player1.GetSprite());
        window.draw(npcSlime.GetSprite());

        for (int i = 0; i < (int)items.size(); i++)
        {
            // TODO uncoment when you have items ready
            // window.draw(items[i].GetSprite());
        }

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


// Compile command:
// rm -f newLifeEXE && g++ -ansi -pedantic -Wall -Wextra -Wshadow -Weffc++ main.cpp -o newLifeEXE -lsfml-graphics -lsfml-window -lsfml-system

// Run:
// ./newLifeEXE 
