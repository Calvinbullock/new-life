/* ================================================
* Author: Calvin Bullock
*
* ItemDoor is a child class of item.
*  This will be how you enter and exit doors.
*  it will be placed on the tile in front of
*  the door tile.
================================================ */
#include "item.h"
#include "tileMap.cpp"
#include <vector>
// #include "GameLevel.h" // NOTE Not implemented yet

class ItemDoor : Item {
public:
    ItemDoor(std::string texturePath, float startX, float startY, bool isLocked)
        : Item(texturePath, startX, startY), isLocked(isLocked) {}


    void ItemAction() {
        // check if player is on right tile pos
        // check if locked, if yes does player have key?
        // check what is the current level side1 or side2,
        //    send to the other level
    }

private:
    bool isLocked;
    // GameLevel side1;
    std::vector<int> posSide1;
    // GameLevel side2;
    std::vector<int> posSide2;
};
