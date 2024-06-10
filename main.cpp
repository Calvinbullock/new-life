e "playerSprite.h"
#include "tileMap.cpp"
#include <SFML/Graphics.hpp>

#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream> // DEBUGing
#include <vector>

/*
TODOS
- Make a function that will take a tile index and find the x,y postion for more
easy of use
- creat a function to turn the map array into a vector
*/

/* ================================================
*  Game Class
================================================ */
class Game {

public:
    Game(int windowWidthIn,
         int windowHeightIn,
         int moveAmtIn,
         PlayerSprite playerIn)
        : windowWidth(windowWidthIn), windowHeight(windowHeightIn),
          moveAmt(moveAmtIn), player(playerIn), npcList(), itemsList() {}

    /* ================================================
    *
    ================================================ */
    void GameLoop(TileMap *map,
                  std::vector<Item> *itemList,
                  std::vector<PlayerSprite> *npcListIn) {

        sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight),
                                "NewLife");
        while (window.isOpen()) {
            sf::Event event;

            // checks for input / game events
            while (window.pollEvent(event)) {
                player.NpcCollistion(10, *npcListIn); // TODO add npc list

                // check for user input
                if (event.type == sf::Event::Closed) {
                    window.close();
                } else if (event.type == sf::Event::KeyPressed) {
                    // Player key entry
                    player.PlayerMove(moveAmt, *map, *itemList);
                }
            }

            window.clear();
            window.draw(*map);
            window.draw(player.GetSprite());

            // draw all NPC sprites
            // window->draw(npcSlime.GetSprite());
            DrawNPCSpriteVector(*npcListIn, &window);

            // draw all item sprites
            // TODO uncoment when you have items ready
            // DrawItemSpriteVector(items, window);

            window.display();
        }
    }

private:
    float windowWidth;
    float windowHeight;
    int moveAmt; // Amount of pixels the player moves with each key press.

    PlayerSprite player;
    std::vector<PlayerSprite> npcList;
    std::vector<Item> itemsList;

    /* ================================================
    *  draws the items in Item vector
    ================================================ */
    void DrawItemSpriteVector(std::vector<Item> spriteVec,
                              sf::RenderWindow *windowIn) {
        for (int i = 0; i < (int)spriteVec.size(); i++) {
            windowIn->draw(spriteVec[i].GetSprite());
        }
    }

    /* ================================================
    *  draws the NPC sprites
    *  TODO  think about merging this and the DrawItemSpriteVector func
    ================================================ */
    void DrawNPCSpriteVector(std::vector<PlayerSprite> spriteVec,
                             sf::RenderWindow *windowIn) {
        for (int i = 0; i < (int)spriteVec.size(); i++) {
            windowIn->draw(spriteVec[i].GetSprite());
        }
    }
};

/* ================================================
*  Main Function
================================================ */
int main() {
    /* ================================================
    *  Create Game const
    ================================================ */
    float windowWidth = 512;
    float windowHeight = 256;
    int moveAmt = 16; // Amount of pixels the player moves with each key press.

    // PLayer sprite direction textures
    std::string playerSpriteMovementPaths[4] = {
        "images/protagUp.png",
        "images/protagRight.png",
        "images/protagDown.png",
        "images/protagLeft.png",
    };

    std::string slimeSpriteMovementPaths[4] = {
        "images/slimeUp.png",
        "images/slimeRight.png",
        "images/slimeDown.png",
        "images/slimeLeft.png",
    };

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "NewLife");
    PlayerSprite player1 = PlayerSprite(52, 52, 100, playerSpriteMovementPaths);
    PlayerSprite npcSlime = PlayerSprite(83, 83, 100, slimeSpriteMovementPaths);
    Game game = Game(512, 256, 16, player1);

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
    // clang-format off
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
    // clang-format on

    std::vector<int> cave(arr, arr + sizeof(arr) / sizeof(arr[0]));

    // TODO Moved / cleaned up MapObject 2/2
    // if the int in cave[] matches one of these (cavePassable) then it is
    // passable
    //      by the player sprite.
    std::vector<int> cavePassable;
    cavePassable.push_back(5);
    cavePassable.push_back(4);

    // Set tile map textures
    if (!caveMap.load("images/dungon-src.png", sf::Vector2u(32, 32), cave, 16, 8,
                      cavePassable))
        return -1;

    // game.GameLoop(&caveMap, &items, &npcList);

    // Main event / game loop
    while (window.isOpen()) {
        sf::Event event;

        // checks for input / game events
        while (window.pollEvent(event)) {
            player1.NpcCollistion(10, npcList); // TODO add npc list

            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::KeyPressed) { // Player key entry
                player1.PlayerMove(moveAmt, caveMap, items);
            }
        }

        window.clear();
        window.draw(caveMap);
        window.draw(player1.GetSprite());
        window.draw(npcSlime.GetSprite());

        for (int i = 0; i < (int)items.size(); i++) {
            // TODO uncoment when you have items ready
            // window.draw(items[i].GetSprite());
        }

        window.display();
    }

    return 0;
}

// Refrances used:
//      -- gameTile / gameWorld
//      https://www.youtube.com/watch?v=aEDP7uhaiJc&list=PLnEt5PBXuAmvPHLXnYzjR4eP65VsxCQRV&index=9
//      https://www.youtube.com/watch?v=A60oYZK_ptk&list=PLnEt5PBXuAmvPHLXnYzjR4eP65VsxCQRV&index=7
//
//      -- tileMap
//      https://www.sfml-dev.org/tutorials/2.6/graphics-vertex-array.php
//
