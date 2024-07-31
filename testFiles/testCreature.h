/* ================================================
* Author: Calvin Bullock
*
* This is a test file for the creature class.
================================================ */

#pragma once

#include "../creatures/creature.h"
#include <cassert>
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
        TestUpdateHealth_hp10();
        std::cout << "Run_TestCreatures - Pass" << std::endl;
    }

private:
    /* ================================================
     * Test Update Health - hp 10
     *
     * input:
     *   health  = 10, isAlive = true, updateHealth = -10
     *
     * Output:
     *   health  = 0, isAlive = false
    ================================================ */
    void TestUpdateHealth_hp10() {
      // set up
      Creature c;
      c.isAlive = true;
      c.currentHealth = 10;

      // action
      c.UpdateHealth(-10);

      // check
      assert(c.currentHealth == 0);
      assert(c.isAlive == false);

      // clean up
   }
};
