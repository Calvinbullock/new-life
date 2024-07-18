
#include "playerCreature.h"

/* ================================================
*  Handles sprite movements
================================================ */
void PlayerCreature::Move(int moveAmtIn,
                              TileMap map,
                              std::vector<Item> items) {

    int dirUp = 0;
    int dirRight = 1;
    int dirDown = 2;
    int dirLeft = 3;

    // PLayer sprite direction textures
    std::string playerUpImg = pathsToSpriteMovementTextures[dirUp];
    std::string playerRightImg = pathsToSpriteMovementTextures[dirRight];
    std::string playerDownImg = pathsToSpriteMovementTextures[dirDown];
    std::string playerLeftImg = pathsToSpriteMovementTextures[dirLeft];

    // the 0s in the UpdatePlayerPostion calls are the axis they don't move in
    //   the last int in the call is the direction they face 0 = up, 1 = left
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        std::cout << "you pushed W" << std::endl;
        UpdatePlayerPostion(playerUpImg, 0, -moveAmtIn, map, dirUp);

    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        std::cout << "you pushed D" << std::endl;
        UpdatePlayerPostion(playerRightImg, moveAmtIn, 0, map, dirRight);

    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        std::cout << "you pushed S" << std::endl;
        UpdatePlayerPostion(playerDownImg, 0, moveAmtIn, map, dirDown);

    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        std::cout << "you pushed A" << std::endl;
        UpdatePlayerPostion(playerLeftImg, -moveAmtIn, 0, map, dirLeft);

    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
        for (int i = 0; i < (int)items.size(); i++) {
            items[i].ItemActionTest(GetBoundery());
        }
    }
}
