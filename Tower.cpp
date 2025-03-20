//
// Created by Elisa on 2025-02-04.
//

#include "Tower.h"
#include "TowerObserver.h"
#include "Critter.h"
#include <iostream>
#include <cmath>
#include "Map.h"
#include "Player.h"
#include <algorithm>

using namespace std;



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
  targetingStrategy = new NearestToTowerStrategy(); //default strategy

}

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
  targetingStrategy = new NearestToTowerStrategy();


}

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
  targetingStrategy = tower.targetingStrategy->clone(); //copy tower strategy

}

Tower::~Tower() {
  delete targetingStrategy;
}

void Tower::upgrade(Player &player){
  if (player.getPlayerFunds() >= upgradeCost) {
    player.subtractPlayerFunds(upgradeCost);
    level++;
    power += 10;
    range += 2;
    rateOfFire += 5;
    upgradeCost += 50;
    refundValue = cost * 0.6;

    std::cout << "Tower upgraded to level " << level << "!\n";

    notifyObservers();
  }
  else {
    std::cout << "Tower upgrade failed! Not enough funds.\n";
  }
}



double Tower::sell(Player &player){

  double sellValue = refundValue + (level * 10.4 );
  cout << "Tower selling " << sellValue << " gold! Approx. " << cost - refundValue << " less than initial cost." << endl;
  player.subtractPlayerFunds(sellValue);
  return sellValue;
}

void Tower::attack(Critter* critter) {

  for (int i = 0; i < rateOfFire; i++) {

    critter->takeDamage(power);
    cout << "Tower attacking!" << "Critter just lost " << power << " health." << endl;
    if(critter->getStrength() < 0) {
      cout << "Critter died!" << endl;
    }

  }

}

bool Tower::isTargetInRange(const Critter* critter) const {
  double distance = sqrt(pow(critter->x - x , 2) + pow(critter->y - y , 2));
  return distance <= range;

}

void Tower::setTargetingStrategy(TargetingStrategy* strategy) {
  delete targetingStrategy;
  targetingStrategy = strategy;
}

void Tower::acquireTarget(std::vector<Critter*>& targets) {
  if (Critter* target = targetingStrategy->selectTarget(this, targets)) {
    attack(target);
  }
}




bool Tower::isValidPlacement(int coX, int coY, const Map &map, const std::vector<Tower *> &towers) const
{
  if (!map.isWithinBounds(coX, coY))
  {
    cout << "Invalid placement: Tower is out of map bounds!" << endl;
    return false;
  }

  if (map.getCellType(coX, coY) != CellState::SCENERY)
  {
    cout << "Invalid placement: Tower can only be placed on SCENERY cells!" << endl;
    return false;
  }

  for (const Tower *tower : towers)
  {
    if (tower->x == coX && tower->y == coY)
    {
      cout << "Invalid placement: There is already a tower here!" << endl;
      return false;
    }
  }

  return true;
}

void Tower::placeTower(Map &map)
{
  if (map.getCellType(x, y) == CellState::SCENERY)
  {
    map.setCell(x, y, CellState::TOWER);
    cout << "Tower successfully placed at (" << x << ", " << y << ")" << endl;
  }
}


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
void Tower::setRange(int Range) { range = Range; notifyObservers(); }
void Tower::setLevel(int Level) { level = Level; notifyObservers(); }
void Tower::setCost(double Cost) { cost = Cost; notifyObservers(); }
void Tower::setPower(int Power) { power = Power; notifyObservers(); }
void Tower::setRateOfFire(int RateOfFire) { rateOfFire = RateOfFire; notifyObservers(); }
void Tower::setUpgradeCost(double UpgradeCost) { upgradeCost = UpgradeCost; notifyObservers(); }



void Tower::addObserver(TowerObserver *observer) {

  observers.push_back(observer);

}

void Tower::removeObserver(TowerObserver *observer) {
  observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void Tower::notifyObservers() {

  for (auto* observer : observers) {
    observer->update();
  }
}






