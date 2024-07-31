/* ================================================
* Author: Calvin Bullock
*
* This is a test file for the creature class.
================================================ */

#pragma once

#include "../creatures/creature.h"
#include <iostream>
#include <iterator>

class TestCreature {

public:
   TestCreature() {}

    /* ================================================
     * RUN TEST CREATURES
     *
     * Think of this like main
    ================================================ */
    void Run_TestCreatures() {
        TestUpdateHealth();
        std::cout << "Run_TestCreatures - Pass" << std::endl;
    }

private:
    void TestUpdateHealth() {}
};
