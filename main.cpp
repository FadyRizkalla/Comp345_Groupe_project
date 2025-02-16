#include "map.h"
#include "Player.h"
#include "Tower.h"
#include "ArcherTower.h"
#include "CrossbowTower.h"
#include "SniperTower.h"
#include "IceWall.h"
#include "TurretTower.h"

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

    // User Towers
    vector<Tower*> towers;
    int choice;

    do{
    cout << "Place your tower on the map!\n"
             "Select a tower type:  \n"
            "\n1. Archer Tower (100 gold) "
            "\n2. CrossBow Tower (173 gold) "
            "\n3. Sniper Tower (210 gold) "
            "\n4. Ice Wall (275 gold) "
            "\n5. Turret Tower (500) "
            "\nEnter choice (1-5)" << endl;
    cin >> choice;
    }while(choice <= 1 || choice >= 5);


    double towerCost = 0;
    double x, y;
    Tower tempTower;
    do{

    cout << "Enter tower coordinates (x,y): " << endl;
    cin >> x >> y;
    }
    while(!tempTower.isValidPlacement(x, y, gameMap, towers));

    switch (choice){
      case 1:
          if (player.getPlayerFunds() >= 100) {
                towers.push_back(new ArcherTower(x, y));
              cout << "You have chosen Archer Tower!" << endl;
              towerCost = 100;
          }
          else {
              cout << "Insufficient funds!" << endl;
          }
          break;
      case 2:
          if (player.getPlayerFunds() >= 173) {
              towers.push_back(new CrossbowTower(x, y));
              cout << "You have chosen CrossBow Tower!" << endl;
              towerCost = 173;
          }
          else {
              cout << "Insufficient funds!" << endl;
          }
        break;
      case 3:
          if (player.getPlayerFunds() >= 210) {
              towers.push_back(new SniperTower(x, y));
              cout << "You have chosen Sniper Tower!" << endl;
              towerCost = 210;
          }
          else {
              cout << "Insufficient funds!" << endl;
          }
        break;
      case 4:
          if (player.getPlayerFunds() >= 275) {
              towers.push_back(new IceWall(x, y));
              cout << "You have chosen Ice Wall!" << endl;
              towerCost = 275;
          }
          else {
              cout << "Insufficient funds!" << endl;
          }
        break;
      case 5:
          if (player.getPlayerFunds() >= 500) {
              towers.push_back(new TurretTower(x, y));
              cout << "You have chosen Turret Tower!" << endl;
              towerCost = 500;
          }
          else {
              cout << "Insufficient funds!" << endl;
          }
        break;
      default:
        cout << "Invalid Choice!" << endl;
    }











    return 0;
}
