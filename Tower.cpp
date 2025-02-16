//
// Created by Elisa on 2025-02-04.
//

#include "Tower.h"
#include "Critter.h"
#include <iostream>
#include <cmath>
#include "Map.h"
#include "Player.h"

#include "ArcherTower.h"
#include "CrossbowTower.h"
#include "SniperTower.h"
#include "IceWall.h"
#include "TurretTower.h"

using namespace std;


// Default constructor. Makes an instance of a default tower.
Tower::Tower() {

  level = 0;
  cost = 0;
  range = 0;
  power = 0;
  rateOfFire = 0;
  upgradeCost = 0;
  refundValue = 0;

}

// Parameritized constructor. It creates towers
Tower::Tower(double coX, double coY, double Cost, int Range, int Power, int RateOfFire, double UpgradeCost, int Level, double RefundValue) {

  x = coX;
  y = coY;
  cost = Cost;
  range = Range;
  power = Power;
  rateOfFire = RateOfFire;
  upgradeCost = UpgradeCost;
  level = Level;
  refundValue = RefundValue;


}

// initialize copy constructor. It makes an identical copy of a already made tower
Tower::Tower(const Tower& tower) {

  cost = tower.cost;
  range = tower.range;
  power = tower.power;
  rateOfFire = tower.rateOfFire;
  upgradeCost = tower.upgradeCost;
  level = tower.level;
  refundValue = tower.refundValue;

}

Tower::~Tower()= default;


// method for upgrading a tower
void Tower::upgrade(){

  Player player;
  if (player.getPlayerFunds() >= upgradeCost) {

    player.setPlayerFunds(player.getPlayerFunds() - upgradeCost);
    level++;
    power += 10;
    range += 2;
    rateOfFire += 5;
    upgradeCost += 50;
    refundValue = cost * 0.6;
    cout << "Tower upgraded to level " << level << "!" << endl;

  }
  else {
    cout << "Tower upgrade failed! Not enough funds" << endl;
  }

}


// you can sell an item for approx. the same amount as the refund value.
double Tower::sell(){
  Player player;
  double sellValue = refundValue + (level * 10.4 );
  cout << "Tower selling " << sellValue << " gold! Approx. " << cost - refundValue << " less than initial cost." << endl;
  player.setPlayerFunds(player.getPlayerFunds() - sellValue);
  return sellValue;
}

//towers attack critters
void Tower::attack(Critter* critter) {

  for (int i = 0; i < rateOfFire; i++) {

    critter->takeDamage(power);
    cout << "Tower attacking!" << "Critter just lost " << power << " health." << endl;
    if(critter->getStrength() < 0) {
      cout << "Critter died!" << endl;
    }

  }

}

//search for critters in range
bool Tower::isTargetInRange(Critter* critter) {
  double distance = sqrt(pow(critter->x - x , 2) + pow(critter->y - y , 2));
  return distance <= range;

}

//Get critters in range and attack them
Critter* Tower::acquireTarget(std::vector<Critter*>& targets) {

  for (Critter* critter : targets) {
    if(isTargetInRange(critter)) {
      attack(critter);
    }
  }

}

//place a tower on the map

bool Tower::isValidPlacement(int coX, int coY, const Map& map, const std::vector<Tower *> &towers) {

  if (!map.isWithinBounds(coX,coY)) {
    cout << "Invalid placement: Tower is out of map bounds!" << endl;
    return false;
  }

  if (map.getCellType(x,y) == CellType::PATH) {
    cout << "Invalid placement: Tower cannot be placed on the path!" << endl;
  }

  for(const Tower* tower : towers) {
    if (tower -> x == coX && tower -> y == coY) {

      cout << "Invalid placement: There is already a tower here" << endl;
      return false;
    }
  }

  cout << "Tower is placed in the following coordinates: (" << coX << ", " << coY << ")" << endl;
  x = coX;
  y = coY;
  return true;

}

//Method to choose a tower

void selectTowerType() {

  int k;
  Player player;
  vector<Tower*> towers;
  Tower* newTower = nullptr;

  do {
    cout << "Select a tower type:  "
            "\n1. Archer Tower (100 gold) "
            "\n2. CrossBow Tower (173 gold) "
            "\n3. Sniper Tower (210 gold) "
            "\n4. Ice Wall (275 gold) "
            "\n5. Turret Tower (500) "
            "\nEnter choice (1-5)" << endl;
    cin >> k;

    if (k > 5 || k < 1) {
      cout << "Invalid input, choose a tower type between 1 and 5!" << endl;
    }
    else {
      break;
    }
  }
  while (k > 5 || k < 1);


  double towerCost = 0;
  double x, y;
  cout << "Enter tower coordinates (x,y): ";
  cin >> x >> y;


  switch (k) {
    case 1:
      if (player.getPlayerFunds() >= 100) {
        cout << "You have chosen Archer Tower!" << endl;
        towerCost = 100;
      }
      else {
        cout << "You don't have enough funds!" << endl;
      }
      break;

    case 2:

      if (player.getPlayerFunds() >= 175) {
        cout << "You have chosen CrossBow Tower!" << endl;
        towerCost = 175;
      }
      else {
        cout << "You don't have enough funds!" << endl;
      }
    break;

    case 3:
      if (player.getPlayerFunds() >= 210) {
        cout << "You have chosen Sniper Tower!" << endl;
        towerCost = 210;
      }
      else {
        cout << "You don't have enough funds!" << endl;
      }
      break;

    case 4:
      if (player.getPlayerFunds() >= 275) {
        cout << "You have chosen the Ice Wall!" << endl;
        towerCost = 275;
      }
      else {
        cout << "You don't have enough funds!" << endl;
      }

      break;
    case 5:
      if (player.getPlayerFunds() >= 500) {
        cout << "You have chosen Turret Tower!" << endl;
        towerCost = 500;
      }
      else {
        cout << "You don't have enough funds!" << endl;
      }
      break;

    default:
      cout << "Invalid input, choose a tower type between 1 and 5!" << endl;

  }

  player.setPlayerFunds(player.getPlayerFunds() - towerCost);

}

// Getter (accessor methods)

int Tower::getRange() const{
  cout << "Tower's range of " << range << "!" << endl;
  return range;
 }

int Tower::getLevel() const{
  cout << "Tower's level " << level << "!" << endl;
  return level;
}

double Tower::getCost() const{
  cout << "Tower's cost " << cost << " gold!" << endl;
  return cost;

 }

 int Tower::getPower() const{
   cout << "Tower's power " << power <<  endl;
   return power;
 }

 int Tower::getRateOfFire() const{
   cout << "Tower's rate of fire " << rateOfFire << " projectiles per second" << endl;
   return rateOfFire;
 }

 double Tower::getUpgradeCost() const{
   cout << "Tower's upgrade cost " << upgradeCost << " gold!" << endl;
   return upgradeCost;
 }
 // Setters (setting methods)

 void Tower::setRange(int Range){

   range = Range;
 }

 void Tower::setLevel(int Level){
   level = Level;
 }


 void Tower::setCost(double Cost){
   cost = Cost;
 }

 void Tower::setPower(int Power){
   power = Power;
 }

 void Tower::setRateOfFire(int RateOfFire){
   rateOfFire = RateOfFire;
 }

 void Tower::setUpgradeCost(double UpgradeCost){
   upgradeCost = UpgradeCost;
 }








