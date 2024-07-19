
/* ================================================
* Author: Calvin Bullock
*
* This file handles reading all the level data
*     from CSV files and parses the into a
*     gameLevel object.
================================================ */

#include "item.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* ================================================
 * TODO
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

inline void ProcessCreature(string line) {
    SplitLine(',', line);
    // return creature
}

inline void ProcessMap(string line) {
    SplitLine(',', line);
    // return tilemap
}

inline void ProcessItem(string line) {
    SplitLine(',', line);
    // return item
    // Item item = Item();
}

// TODO  write tests!

/* ================================================
*  READ-CSV-FILE
*
* This reads in and processes a csv file into a
*     gameLevel object.
================================================ */
inline int ReadCSVFile(string filename) {
    string line;

    // Open the file for reading
    ifstream input_file(filename);

    if (input_file.is_open()) {
        // Read each line of the file
        while (std::getline(input_file, line)) {

            char id = line[0];

            // sort each line for proper processing
            if (id == 'C')
                ProcessCreature(line);
            else if (id == 'M')
                ProcessMap(line);
            else if (id == 'I')
                ProcessItem(line);
        }

        // Close the file
        input_file.close();
    } else {
        cerr << "Error opening file: " << filename << endl;
    }

    return 0; // TODO  return a gameLevel object
}
