
/* ================================================
 * GAME LEVEL CLASS
 *
 * This reads-in and holds the data for a given gameLevel.
 *    - NPCs, Items, TileMap
 * Also draws the NPC, items, and TileMap
 *
 * Note: tileMap's origin(0, 0) is in the top left.
================================================ */

#pragma once

#include "creature.h"
#include "playerCreature.h"
#include "tileMap.cpp"

class GameLevel {

public:
    GameLevel(TileMap tileMapIn) : tileMap(tileMapIn), npcList(), itemsList() {}

    GameLevel() : tileMap(), npcList(), itemsList() {}

    // Get-ers
    TileMap GetTileMap() { return tileMap; }
    std::vector<Item> GetItemsList() { return itemsList; }

    // Modifiers
    void SetTileMap(TileMap &tileMapIn) { tileMap = tileMapIn; }
    void AddItem(Item &item) { itemsList.push_back(item); }
    void AddNPC(Creature &npc) { npcList.push_back(npc); }

    // draw functions
    void DrawItems(sf::RenderWindow &window) {
        for (int i = 0; i < (int)itemsList.size(); i++) {
            window.draw(itemsList[i].GetSprite());
        }
    }
    void DrawNPCs(sf::RenderWindow &window) {
        for (int i = 0; i < (int)npcList.size(); i++) {
            window.draw(npcList[i].GetSprite());
        }
    }
    void DrawMap(sf::RenderWindow &window) { window.draw(tileMap); }

    // level actions
    void CheckCollision(PlayerCreature &player) {
        // TODO add npc list
        player.NpcCollision(10, npcList);
    }
    void PlayerMove(PlayerCreature &player) { player.Move(tileMap, itemsList); }

private:
    // TODO: read data in from a file
    void ReadLevelData(std::string fileName) {}

    TileMap tileMap;
    std::vector<Creature> npcList;
    std::vector<Item> itemsList;
};
