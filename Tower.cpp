//
// Created by Elisa on 2025-02-04.
//

#include "Tower.h"
#include "Critter.h"
#include <iostream>
#include <cmath>
#include "Map.h"
#include "Player.h"

using namespace std;


// Default constructor. Makes an instance of a default tower.
Tower::Tower() {

  x = 0;
  y = 0;
  level = 0;
  cost = 0;
  range = 0;
  power = 0;
  rateOfFire = 0;
  upgradeCost = 0;
  refundValue = 0;

}

// Parameterized constructor. It creates towers
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

// initialize copy constructor. It makes an identical copy of an already made tower
Tower::Tower(const Tower& tower) {

  x = tower.x;
  y = tower.y;
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

  Player player{};
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
  Player player{};
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
bool Tower::isTargetInRange(const Critter* critter) const {
  double distance = sqrt(pow(critter->x - x , 2) + pow(critter->y - y , 2));
  return distance <= range;

}

//Get critters in range and attack them
void Tower::acquireTarget(std::vector<Critter*>& targets) {

  for (Critter* critter : targets) {
    if(isTargetInRange(critter)) {
      attack(critter);
    }
  }

}

//place a tower on the map

bool Tower::isValidPlacement(int coX, int coY, const Map& map, const std::vector<Tower*>& towers) const {

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
  return true;

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








