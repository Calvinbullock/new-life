
/* ================================================
* Author: Calvin Bullock
*
* This file handles reading all the level data
*     from CSV files and parses the into a
*     gameLevel object.
*
* NOTE: READ CSV FILE - this is the "main" function
*     for this file.
================================================ */

#pragma once
#include "creature.h"
#include "gameLevel.h"
#include "item.h"

#include <cassert>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

/* ================================================
 * STRING TO INT
 *
 * This function turns a number in a string into
 *    an int and returns it.
 *
 * Ex: "1" -> 1
================================================ */
inline int StringToInt(string stringInt) {
    int num = -1;
    try {
        num = std::stoi(stringInt);
    } catch (const std::invalid_argument &e) {
        std::cerr << "Error: Invalid string format for conversion to integer."
                  << std::endl;
    }

    assert(num != -1);
    return num;
}

/* ================================================
 * SPLIT LINE
 *
 * This function takes a line from a csv file
 *    and breaks it up into a vector of strings
 *    that is returned for use.
================================================ */
inline vector<string> SplitLine(char delimiter, string line) {
    string token;
    size_t start = 0;
    vector<string> data;

    while ((start = line.find(delimiter)) != string::npos) {
        token = line.substr(0, start);
        data.push_back(token);
        line.erase(0, start + 1);
    }

    // Add the last token after the loop (no delimiter after it)
    token = line;
    data.push_back(token);

    return data;
}

/* ================================================
 * PROCESS CREATURE
 *
================================================ */
inline Creature ProcessCreature(vector<string> lineData) {
    Creature creature;
    return creature;
}

/* ================================================
 * PROCESS MAP
 *
 * Read the map data and parse it into a tileMap
 *    Object.
================================================ */
inline TileMap ProcessMap(vector<string> lineData) {
    vector<int> tiles;
    vector<int> passableTiles;
    TileMap tileMap;
    int i = 4;

    string texturePath = lineData[1];
    int mapLength = StringToInt(lineData[2]);
    int mapWidth = StringToInt(lineData[3]);

    // all tiles
    while (lineData[i] != ";") {
        tiles.push_back(StringToInt(lineData[i]));
        i++;
    }

    // passable tiles
    i++; // move over end item
    while (lineData[i] != ";") {
        passableTiles.push_back(StringToInt(lineData[i]));
        i++;
    }

    // load / set up the tileMap object
    if (!tileMap.load(texturePath, sf::Vector2u(32, 32), tiles, mapLength,
                      mapWidth, passableTiles))
        assert(false); // if load fails, crash

    return tileMap;
}

/* ================================================
 * PROCESS ITEM
 *
 * Take a line containing item data and convert
 *    that line into a item object, then return
 *    that object.
================================================ */
inline Item ProcessItem(vector<string> lineData) {
    string texturePath = lineData[1];

    // start Position
    int x = StringToInt(lineData[2]);
    int y = StringToInt(lineData[3]);

    Item item = Item(texturePath, x, y);
    return item;
}

/* ================================================
*  READ CSV FILE
*
* NOTE: Think of this as the Main function of this file
*
* This reads in and processes a csv file into a
*     gameLevel object.
================================================ */
inline int ParseCSVFile(string filename) {
    string line;
    GameLevel gl;

    // Open the file for reading
    ifstream input_file(filename);

    if (input_file.is_open()) {

        // Read each line of the file
        while (std::getline(input_file, line)) {
            vector<string> lineData = SplitLine(',', line);
            char id = line[0];

            // sort each line for proper processing
            if (id == 'C') {
                Creature creature = ProcessCreature(lineData);
                gl.AddNPC(creature);

            } else if (id == 'I') {
                Item item = ProcessItem(lineData);
                gl.AddItem(item);

            } else if (id == 'M') {
                TileMap tileMap = ProcessMap(lineData);
                gl.SetTileMap(tileMap);
            }
        }

        input_file.close();
    } else {
        cerr << "Error opening file: " << filename << endl;
    }

    return 0; // TODO  return a gameLevel object
}
