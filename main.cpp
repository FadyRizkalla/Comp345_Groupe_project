#include "Map.h"
#include "Player.h"
#include "Tower.h"
#include "ArcherTower.h"
#include "CrossbowTower.h"
#include "SniperTower.h"
#include "IceWall.h"
#include "TurretTower.h"
#include "Ogre_Critter.h"
#include "Goblin_Critter.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int main()
{
    Player player;
    player.setPlayerFunds(500);

    Map gameMap(5, 5);

    gameMap.setCell(0, 0, CellType::ENTRY);
    gameMap.setCell(4, 4, CellType::EXIT);
    gameMap.setCell(0, 1, CellType::PATH);
    gameMap.setCell(1, 1, CellType::PATH);
    gameMap.setCell(1, 2, CellType::PATH);
    gameMap.setCell(2, 2, CellType::PATH);
    gameMap.setCell(3, 2, CellType::PATH);
    gameMap.setCell(4, 2, CellType::PATH);
    gameMap.setCell(4, 3, CellType::PATH);

    cout << "\nGenerated Map:\n";
    gameMap.displayMap();

    if (gameMap.validateMap())
    {
        cout << "The map is valid!\n";
    }
    else
    {
        cout << "The map is not valid!\n";
    }

    // Place all types of towers on SCENERY cells
    vector<Tower *> towers;

    towers.push_back(new ArcherTower(1, 0));
    towers.push_back(new CrossbowTower(2, 1));
    towers.push_back(new SniperTower(4, 1));
    towers.push_back(new IceWall(3, 3));
    towers.push_back(new TurretTower(0, 4));

    for (Tower *tower : towers)
    {
        tower->placeTower(gameMap);
    }


    cout << "\nFinal Map with Towers:\n";
    gameMap.displayMap();

    cout << "All tower types have been placed on the grid!" << endl;

    vector<Critter *> critters;

    // Creating different Ogre and Goblin critters
    critters.push_back(new Ogre_Critter());
    critters.push_back(new Goblin_Critter());

    cout << "\nDisplaying Critter Stats:\n";
    cout << "Critter Type: Ogre\n";
    cout << "Hit Points: " << critters[0]->getHitPoints() << "\n";
    cout << "Strength: " << critters[0]->getStrength() << "\n";
    cout << "Speed: " << critters[0]->getSpeed() << "\n";
    cout << "Level: " << critters[0]->getLevel() << "\n";
    cout << "Reward: " << critters[0]->getReward() << "\n";
    cout << "-----------------------------\n";

    cout << "Critter Type: Goblin\n";
    cout << "Hit Points: " << critters[1]->getHitPoints() << "\n";
    cout << "Strength: " << critters[1]->getStrength() << "\n";
    cout << "Speed: " << critters[1]->getSpeed() << "\n";
    cout << "Level: " << critters[1]->getLevel() << "\n";
    cout << "Reward: " << critters[1]->getReward() << "\n";
    cout << "-----------------------------\n";

    return 0;
}
