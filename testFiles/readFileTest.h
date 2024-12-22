
/* ================================================
* Author: Calvin Bullock
*
* This is a testing file for readFile.h
================================================ */

#include "../readFile.h"
#include <cassert>
#include <iostream>
#include <string>
#include <vector>


/* ================================================
 * TEST STRING TO INT
 *
 * Lots of simple cases... x in, y out
================================================ */
inline int TestStringToInt() {
   if (StringToInt("1") != 1)
      return 1;

   if (StringToInt("10") != 10)
      return 1;

   if (StringToInt("44") != 44)
      return 1;

   return 0;
}

/* ================================================
*  TEST SPLIT LINE - SIMPLE
*
*  CASE: simple split
*  Input:  line = "M,tex/path,name"
*  Output: data = ["M", "tex/path", "name"]
================================================ */
inline int TestSplitLine_Simple() {
    // setup
    std::string line = "M,tex/path,name";
    vector<string> data = SplitLine(',', line);

    // check
    if (data[0] != "M") {
        cout << "fail" << data[0] << endl;
        return 1;
    }

    if (data[1] != "tex/path") {
        cout << "fail" << endl;
        return 1;
    }

    if (data[2] != "name") {
        cout << "fail" << endl;
        return 1;
    }

    return 0;
}

/* ================================================
*  TEST SPLIT LINE - LONG
*
*  CASE: Long split
*  Input:  line = "B,tex/path,name,yop,hop"
*  Output: data = [ "M", "tex/path", "name", "yop", "hop" ]
================================================ */
inline int TestSplitLine_Long() {
    // setup
    std::string line = "B,tex/path,name,yop,hop";
    vector<string> data = SplitLine(',', line);

    // check
    if (data[0] != "B") {
        cout << "fail" << data[0] << endl;
        return 1;
    }

    if (data[1] != "tex/path") {
        cout << "fail" << endl;
        return 1;
    }

    if (data[2] != "name") {
        cout << "fail" << endl;
        return 1;
    }

    if (data[3] != "yop") {
        cout << "fail" << endl;
        return 1;
    }

    if (data[4] != "hop") {
        cout << "fail" << endl;
        return 1;
    }

    return 0;
}


/* ================================================
 *
================================================ */
inline int TestProcessMap_Simple() {
   // *setup
   vector<string> lineData;
   lineData.push_back("M");
   lineData.push_back("../images/dungon-src.png");

   // length X width
   lineData.push_back("3");
   lineData.push_back("3");

   // tiles
   lineData.push_back("3");
   lineData.push_back("3");
   lineData.push_back("3");
   lineData.push_back(";");

   // passable
   lineData.push_back("3");
   lineData.push_back("3");
   lineData.push_back(";");

   // *do thing
   TileMap tm = ProcessMap(lineData);
   vector<int> passable = tm.GetPassableTiles();

   // *check
   if (passable.size() != 2)
      return 1;

   // *clean up
   return 0;
}

/* ================================================
 * RUN - READ FILE TESTS
 *
 * This is will run every test in this file. It
 *    is called from the testRunner file.
================================================ */
inline void Run_ReadFileTests() {
    if (TestSplitLine_Simple() == 1)
        cout << "TestSplitLine_Simple - Fail" << endl;

    if (TestSplitLine_Long() == 1)
        cout << "TestSplitLine_Long - Fail" << endl;

    if (TestStringToInt() == 1)
        cout << "TestStringToInt - Fail" << endl;

    if (TestProcessMap_Simple() == 1)
        cout << "TestProcessMap_Simple - Fail" << endl;

   cout << "Run_ReadFileTests - Pass" << endl;
}


