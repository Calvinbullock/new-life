/* ================================================
* Author: Calvin Bullock
*
* This file contains the Main function and gameloop.
*
* References used:
*    -- gameTile / gameWorld
*....-https://www.youtube.com/watch?v=aEDP7uhaiJc&list=PLnEt5PBXuAmvPHLXnYzjR4eP65VsxCQRV&index=9
*....-https://www.youtube.com/watch?v=A60oYZK_ptk&list=PLnEt5PBXuAmvPHLXnYzjR4eP65VsxCQRV&index=7
*
*    -- tileMap
*    https://www.sfml-dev.org/tutorials/2.6/graphics-vertex-array.php
================================================ */

#include "creature.h"
#include "playerCreature.h"
#include "tileMap.cpp"

#include <SFML/Graphics.hpp>
#include <cassert>
#include <string>
#include <vector>

// #include <iostream> // DEBUGing

/* TODO:

-  NOTE: have dad read this over, ask for suggestions on formating, nameing etc

- read gameLevel data from json file then
   - Move gameLevel class to own file

- NPC classes.

- Make a function that will take a tile index and find the x,y
   position for more easy of use.

                     ----- BUGs-------

-  BUG: if player is against a wall and facing away from it they
   can not turn the sprite to face it.

*/

/* ================================================
* GET CAVE MAP
*     This is a placeHolder func this should all
*           be moved a text/json/other file to be read
*           in.
*
*   NOTE: This should all be read in from a file.
*   TODO: parts of this can be moved into level class..
================================================ */
TileMap getCaveMap() {
    // TODO rename this array
    // define the level with an array of tile indices
    // clang-format off
    // (0, 0) is the top left
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

    TileMap caveMap;
    std::vector<int> cave(arr, arr + sizeof(arr) / sizeof(arr[0]));

    // if the int in cave[] matches one of these (cavePassable) then it is
    //      passable by the player sprite.
    std::vector<int> cavePassable;
    cavePassable.push_back(5);
    cavePassable.push_back(4);

    // load all the parts to create a tile map
    if (!caveMap.load("images/dungon-src.png", sf::Vector2u(32, 32), cave, 16, 8,
                      cavePassable))
        assert(false); // if load fails, crash

    return caveMap;
}

/* ================================================
 * GAMELOOP
 *
 * Runs the main gameLoop
 * - Draws window
 * - Key events
 * - Collisions
================================================ */
void GameLoop(sf::RenderWindow &window,
              GameLevel &level,
              PlayerCreature &player) {
    // Main event / game loop
    while (window.isOpen()) {
        sf::Event event;

        // checks for input / game events
        while (window.pollEvent(event)) {
            level.CheckCollision(player);

            if (event.type == sf::Event::Closed) {
                window.close();

            } else if (event.type == sf::Event::KeyPressed) { // Player key entry
                level.PlayerMove(player);
            }
        }

        // draw updated frame
        window.clear();
        level.DrawMap(window);
        window.draw(player.GetSprite());

        level.DrawNPCs(window);
        level.DrawItems(window);

        window.display();
    }
}

/* ================================================
*  Main Function
================================================ */
int main() {
    float windowWidth = 512;
    float windowHeight = 256;
    int moveAmt = 16; // Amount of pixels the player moves with each key press.
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "NewLife");

    // NOTE: how to clean this up??
    // PLayer sprite direction textures
    std::string playerSpriteMovementPaths[4] = {
        "images/protagUp.png",
        "images/protagRight.png",
        "images/protagDown.png",
        "images/protagLeft.png",
    };
    PlayerCreature player =
        PlayerCreature(52, 52, 100, playerSpriteMovementPaths, moveAmt);

    // TODO: get this into the GetMap
    // -- {
    std::string slimeSpriteMovementPaths[4] = {
        "images/slimeUp.png",
        "images/slimeRight.png",
        "images/slimeDown.png",
        "images/slimeLeft.png",
    };
    Creature npcSlime = Creature(83, 83, 100, slimeSpriteMovementPaths);

    TileMap caveMap = getCaveMap();
    Item topDoor = Item("", 64, 0);

    GameLevel cave = GameLevel(caveMap);
    cave.AddItem(topDoor);
    cave.AddNPC(npcSlime);
    // -- }

    GameLoop(window, cave, player);

    return 0;
}
