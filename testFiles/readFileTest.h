
/* ================================================
* Author: Calvin Bullock
*
* This is a testing file for readFile.h
================================================ */

#include "../readFile.h"
#include <iostream>
#include <string>
#include <vector>

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

inline void Run_ReadFileTests() {
    if (TestSplitLine_Simple() == 1)
        cout << "TestSplitLine_Simple - fail" << endl;

    if (TestSplitLine_Long() == 1)
        cout << "TestSplitLine_Long - fail" << endl;
}


