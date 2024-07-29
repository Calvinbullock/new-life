
/* ================================================
* Author: Calvin Bullock
*
* This is a child of the item class.
*
* This is what allows you to enter a door.
*
* ItemDoor is a child class of item.
*  This will be how you enter and exit doors.
*  it will be placed on the tile in front of
*  the door tile.
================================================ */

#include "../gameLevel.h"
#include "../item.h"

class DoorItem : public Item {

public:
    /*ItemDoor(std::string texturePath, float startX, float startY, bool
     * isLocked)*/
    /*    : Item(texturePath, startX, startY), isLocked(isLocked) {}*/

    DoorItem(std::string texturePath, float posX, float posY, bool isLocked)
        : Item(texturePath, posX, posY), isLocked(isLocked) {}

    void itemAction() {}

protected:
    bool isLocked;

    GameLevel side1;
    std::vector<int> posSide1;

    GameLevel side2;
    std::vector<int> posSide2;
};
