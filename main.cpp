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

-  NOTE: have dad read this over and ask for suggestions on formating, nameing
etc

- NPC classes.

- Make a function that will take a tile index and find the x,y
   position for more easy of use.

----- -------

-  BUG: if player is against a wall and facing away from it they
   can not turn the sprite to face it.

*/

// WARN  --- WORKING HERE --- Untested
/* WARN: - Encapsulate?
   - items / tileMap - they should be clearly part of each other
   - draw items / tileMap - one func call
   - maybe NPC list as well?
   - look for MapObject notes 1/2 & 2/2
   - a diagram showing the maps (0, 0) start is top left.
   */

/* ================================================
 * TODO:
================================================ */
class GameLevel {

public:
    GameLevel(TileMap tilmapIn,
              std::vector<Creature> newNpcList,
              std::vector<Item> newItemsList)
        : tileMap(tilmapIn), npcList(), itemsList() {}

    // Get-ers
    TileMap getTileMap() { return tileMap; }

    // Modifiers
    void addItem(Item &item) { itemsList.push_back(item); }
    void addNPC(Creature &npc) { npcList.push_back(npc); }

    // draw functions
    void drawItems(sf::RenderWindow &window) {
        for (int i = 0; i < (int)itemsList.size(); i++) {
            window.draw(itemsList[i].GetSprite());
        }
    }
    void drawNPCs(sf::RenderWindow &window) {
        for (int i = 0; i < (int)npcList.size(); i++) {
            window.draw(npcList[i].GetSprite());
        }
    }

    // void checkCollision(Creature &player) {} // TODO:

    // TODO: read data in from a file
    void readLevelData() {}

private:
    TileMap tileMap;
    std::vector<Creature> npcList;
    std::vector<Item> itemsList;
};

/* ================================================
* getCaveMap
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
*  Main Function
*     contains the main game loop
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
    PlayerCreature player1 =
        PlayerCreature(52, 52, 100, playerSpriteMovementPaths, moveAmt);

    std::string slimeSpriteMovementPaths[4] = {
        "images/slimeUp.png",
        "images/slimeRight.png",
        "images/slimeDown.png",
        "images/slimeLeft.png",
    };
    Creature npcSlime = Creature(83, 83, 100, slimeSpriteMovementPaths);

    // NOTE -- All part of map? {
    // List of all the npcs in a level
    std::vector<Creature> npcList;
    npcList.push_back(npcSlime);

    // NOTE  this needs to be moved / cleaned up MapObject 2/2
    //    Other is the tileMap
    Item topDoor = Item("", 64, 0);
    // Item sword = Item("images/temp-sword.png", 99, 99);

    std::vector<Item> items;
    items.push_back(topDoor);
    // items.push_back(sword);

    TileMap caveMap = getCaveMap();
    // -- }

    // Main event / game loop
    while (window.isOpen()) {
        sf::Event event;

        // checks for input / game events
        while (window.pollEvent(event)) {
            player1.NpcCollision(10, npcList); // TODO add npc list

            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::KeyPressed) { // Player key entry
                player1.Move(caveMap, items);
            }
        }

        // draw updated frame
        window.clear();
        window.draw(caveMap);
        window.draw(player1.GetSprite());

        // Draw NPCs
        for (int i = 0; i < (int)npcList.size(); i++) {
            window.draw(npcList[i].GetSprite());
        }

        // Draw Items
        for (int i = 0; i < (int)items.size(); i++) {
            // TODO uncoment when you have items ready
            window.draw(items[i].GetSprite());
        }

        window.display();
    }

    return 0;
}
