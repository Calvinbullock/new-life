
#include "gameWorld.h"
#include <iostream> // DEBUGing

GameWorld::GameWorld() : gridLength(8),
                         tiles(),
                         exitPositions(1, 0),
                         plyaerPositions(gridLength - 1, gridLength - 1),
                         enemyPostions()
{
    setUpInitialState();
}

void GameWorld::setUpInitialState()
{
    // setUpEnomyPositions();
    setUpTiles();
}

void GameWorld::setUpEnomyPositions()
{
    enemyPostions.push_back(sf::Vector2i(0, 2));
    enemyPostions.push_back(sf::Vector2i(6, 0));
    enemyPostions.push_back(sf::Vector2i(2, 7));
}

void GameWorld::setUpTiles()
{
    // y = 0
    std::vector<GameTile *> firstRow;
    firstRow.push_back(new GameTile("images/rockWall.png", 0, 0, false, false));
    firstRow.push_back(new GameTile("images/stoneDoor.png", 50, 0, true, true));
    firstRow.push_back(new GameTile("images/rockWall.png", 100, 0, false, false));
    firstRow.push_back(new GameTile("images/rockWall.png", 150, 0, false, false));
    firstRow.push_back(new GameTile("images/rockWall.png", 200, 0, false, false));
    firstRow.push_back(new GameTile("images/rockWall.png", 250, 0, false, false));
    firstRow.push_back(new GameTile("images/rockWall.png", 300, 0, false, false));
    firstRow.push_back(new GameTile("images/rockWall.png", 350, 0, false, false));
    tiles.push_back(firstRow);

    // y = 50
    std::vector<GameTile *> secondRow;
    secondRow.push_back(new GameTile("images/rockWall.png", 0, 50, false, false));
    secondRow.push_back(new GameTile("images/rockPath.png", 50, 50, true, true));
    secondRow.push_back(new GameTile("images/rockPath.png", 100, 50, true, false));
    secondRow.push_back(new GameTile("images/rockPath.png", 150, 50, true, false));
    secondRow.push_back(new GameTile("images/rockPath.png", 200, 50, true, false));
    secondRow.push_back(new GameTile("images/rockPath.png", 250, 50, true, false));
    secondRow.push_back(new GameTile("images/rockPath.png", 300, 50, true, false));
    secondRow.push_back(new GameTile("images/rockPath.png", 350, 50, true, false));
    tiles.push_back(secondRow);

    // y = 100
    std::vector<GameTile *> thirdRow;
    thirdRow.push_back(new GameTile("images/rockWall.png", 0, 100, false, false));
    thirdRow.push_back(new GameTile("images/rockPath.png", 50, 100, true, true));
    thirdRow.push_back(new GameTile("images/rockPath.png", 100, 100, true, false));
    thirdRow.push_back(new GameTile("images/rockPath.png", 150, 100, true, false));
    thirdRow.push_back(new GameTile("images/rockPath.png", 200, 100, true, false));
    thirdRow.push_back(new GameTile("images/rockPath.png", 250, 100, true, false));
    thirdRow.push_back(new GameTile("images/rockPath.png", 300, 100, true, false));
    thirdRow.push_back(new GameTile("images/rockPath.png", 350, 100, true, false));
    tiles.push_back(thirdRow);

    // y = 150
    std::vector<GameTile *> fourthRow;
    fourthRow.push_back(new GameTile("images/rockWall.png", 0, 150, false, false));
    fourthRow.push_back(new GameTile("images/rockPath.png", 50, 150, true, true));
    fourthRow.push_back(new GameTile("images/rockPath.png", 100, 150, true, false));
    fourthRow.push_back(new GameTile("images/rockPath.png", 150, 150, true, false));
    fourthRow.push_back(new GameTile("images/rockPath.png", 200, 150, true, false));
    fourthRow.push_back(new GameTile("images/rockPath.png", 250, 150, true, false));
    fourthRow.push_back(new GameTile("images/rockPath.png", 300, 150, true, false));
    fourthRow.push_back(new GameTile("images/rockPath.png", 350, 150, true, false));
    tiles.push_back(fourthRow);

    // y = 200
    std::vector<GameTile *> fifthRow;
    fifthRow.push_back(new GameTile("images/rockWall.png", 0, 200, false, false));
    fifthRow.push_back(new GameTile("images/rockPath.png", 50, 200, true, true));
    fifthRow.push_back(new GameTile("images/rockPath.png", 100, 200, true, false));
    fifthRow.push_back(new GameTile("images/rockPath.png", 150, 200, true, false));
    fifthRow.push_back(new GameTile("images/rockPath.png", 200, 200, true, false));
    fifthRow.push_back(new GameTile("images/rockPath.png", 250, 200, true, false));
    fifthRow.push_back(new GameTile("images/rockPath.png", 300, 200, true, false));
    fifthRow.push_back(new GameTile("images/rockPath.png", 350, 200, true, false));
    tiles.push_back(fifthRow);

    // y = 250
    std::vector<GameTile *> sixthRow;
    sixthRow.push_back(new GameTile("images/rockWall.png", 0, 250, false, false));
    sixthRow.push_back(new GameTile("images/rockPath.png", 50, 250, true, true));
    sixthRow.push_back(new GameTile("images/rockPath.png", 100, 250, true, false));
    sixthRow.push_back(new GameTile("images/rockPath.png", 150, 250, true, false));
    sixthRow.push_back(new GameTile("images/rockPath.png", 200, 250, true, false));
    sixthRow.push_back(new GameTile("images/rockPath.png", 250, 250, true, false));
    sixthRow.push_back(new GameTile("images/rockPath.png", 300, 250, true, false));
    sixthRow.push_back(new GameTile("images/rockPath.png", 350, 250, true, false));
    tiles.push_back(sixthRow);

    // y = 300
    std::vector<GameTile *> seventhRow;
    seventhRow.push_back(new GameTile("images/rockWall.png", 0, 300, false, false));
    seventhRow.push_back(new GameTile("images/rockPath.png", 50, 300, true, true));
    seventhRow.push_back(new GameTile("images/rockPath.png", 100, 300, true, false));
    seventhRow.push_back(new GameTile("images/rockPath.png", 150, 300, true, false));
    seventhRow.push_back(new GameTile("images/rockPath.png", 200, 300, true, false));
    seventhRow.push_back(new GameTile("images/rockWall.png", 250, 300, true, false));
    seventhRow.push_back(new GameTile("images/rockPath.png", 300, 300, true, false));
    seventhRow.push_back(new GameTile("images/rockPath.png", 350, 300, true, false));
    tiles.push_back(seventhRow);

    // y = 350
    std::vector<GameTile *> eighthRow;
    eighthRow.push_back(new GameTile("images/rockWall.png", 0, 350, false, false));
    eighthRow.push_back(new GameTile("images/rockPath.png", 50, 350, true, true));
    eighthRow.push_back(new GameTile("images/rockPath.png", 100, 350, true, false));
    eighthRow.push_back(new GameTile("images/rockPath.png", 150, 350, true, false));
    eighthRow.push_back(new GameTile("images/rockPath.png", 200, 350, true, false));
    eighthRow.push_back(new GameTile("images/rockPath.png", 250, 350, true, false));
    eighthRow.push_back(new GameTile("images/rockPath.png", 300, 350, true, false));
    eighthRow.push_back(new GameTile("images/rockPath.png", 350, 350, true, false));
    tiles.push_back(eighthRow);
}

// -- quick vectore increment map
// 000 050 100 150 200 250 300 350
// 050
// 100
// 150
// 200
// 250
// 300
// 350