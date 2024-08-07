
#include "playerCreature.h"

#include <iostream> // DEBUGing
#define DEBUG std::cout << " DEBUG: L" << __LINE__ << " "

/* ================================================
*  Handles sprite movements
================================================ */
void PlayerCreature::Move(TileMap map, std::vector<Item> items) {

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
        UpdatePostion(playerUpImg, 0, -moveAmt, map, dirUp);

    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        std::cout << "you pushed D" << std::endl;
        UpdatePostion(playerRightImg, moveAmt, 0, map, dirRight);

    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        std::cout << "you pushed S" << std::endl;
        UpdatePostion(playerDownImg, 0, moveAmt, map, dirDown);

    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        std::cout << "you pushed A" << std::endl;
        UpdatePostion(playerLeftImg, -moveAmt, 0, map, dirLeft);

    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
        for (int i = 0; i < (int)items.size(); i++) {
            items[i].ItemActionTest(GetBoundery());
        }
    }
}

void PlayerCreature::Attack(std::vector<Creature> npcList) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
        for (int i = 0; i < (int)npcList.size(); i++) {
          
            sf::FloatRect playerBound = sprite.getGlobalBounds();
            sf::FloatRect npcBound = npcList[i].GetSprite().getGlobalBounds();

            if (playerBound.intersects(npcBound)) {
                DEBUG << currentHealth << ", " << initialHealth << std::endl;
            }
        }
    }
}

// TODO tie this into PlayerMove - stop the player from moveing during a npc
//      colistion
/* ================================================
*  Checks for collisions between the NPC and
*     player sprites.
================================================ */
void PlayerCreature::NpcCollision(int dmg, std::vector<Creature> npcList) {
    int vectorLength = npcList.size();

    for (int i = 0; i < vectorLength; i++) {

        sf::FloatRect playerBound = sprite.getGlobalBounds();
        sf::FloatRect npcBound = npcList[i].GetSprite().getGlobalBounds();

        if (playerBound.intersects(npcBound)) {
            currentHealth = currentHealth - dmg;
            DEBUG << currentHealth << ", " << initialHealth << ", " << dmg
                  << std::endl;
        }
    }
}
