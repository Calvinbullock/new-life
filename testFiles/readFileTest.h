
#include "../readFile.h"
#include <iostream>
#include <string>
#include <vector>

/* ================================================
*  TESTSPLITLINE
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
    if (data[0] != "M")
        cout << "fail" << data[0] << endl;

    if (data[1] != "tex/path")
        cout << "fail" << endl;

    if (data[2] != "name")
        cout << "fail" << endl;

    return 0;
}

inline void Run_ReadFileTests() {
   if (TestSplitLine_Simple() == 1)
      cout << "TestSplitLine_Simple - fail" << endl; 

} 
