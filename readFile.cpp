#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void processCreature(string line) {
    // return creature
}

void processMap(string line) {
    // return creature
}

/* ================================================
*  READCSVFILE
*
* This reads in and processes a csv file into a
*     gameLevel object.
================================================ */
int ReadCSVFile(string filename) {
    string line;

    // Open the file for reading
    ifstream input_file(filename);

    // Check if the file was opened successfully
    if (input_file.is_open()) {
        // Read each line of the file
        while (std::getline(input_file, line)) {

            char id = line[0];

            if (id == 'C')
                processCreature(line);
            else if (id == 'M')
                processMap(line);

            // Process the line
            cout << line << endl; // Example: Print the line
        }

        // Close the file
        input_file.close();
    } else {
        cerr << "Error opening file: " << filename << endl;
    }

    return 0; // TODO  return a gameLevel object 
}
