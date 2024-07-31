
#include "readFileTest.h"
#include "testCreature.h"

#include <iostream>

/* ================================================
* TEST RUNNER
*  
* Runs all the test files.
================================================ */
inline void TestRunner() {
   Run_ReadFileTests();

   TestCreature tc;
   tc.Run_TestCreatures();

   std::cout << "All Tests Passed" << std::endl;
   std::cout << "-------------------------------\n" << std::endl;
}
