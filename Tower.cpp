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
#include <fstream>

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
  for (TowerObserver* observer : observers) {
    delete observer; //clear up observers
  }
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

    std::ofstream("Logs.txt", std::ios::app) << "Tower upgraded to level " << level << "!\n";

    notifyObservers();
  }
  else {
    std::ofstream("Logs.txt", std::ios::app) << "Tower upgrade failed! Not enough funds.\n";
  }
}



double Tower::sell(Player &player){

  double sellValue = refundValue + (level * 10.4 );
  ofstream("Logs.txt", std::ios::app) << "Tower selling " << sellValue << " gold! Approx. " << cost - refundValue << " less than initial cost." << endl;
  player.subtractPlayerFunds(sellValue);
  return sellValue;
}

void Tower::attack(Critter* critter) {
  for (int i = 0; i < rateOfFire; i++) {
    critter->takeDamage(power);
    std::ofstream("Logs.txt", std::ios::app) << "Tower at (" << x << ", " << y << ") attacked! Critter lost " << power << " HP, now at " << critter->getHitPoints() << "\n";
    if (critter->isDead()) {
      std::ofstream("Logs.txt", std::ios::app) << "Critter died!\n";
    }
  }
}



bool Tower::isTargetInRange(const Critter* critter) const {
    // Calculate the "Manhattan distance" or "Chebyshev distance" between the tower and the critter.
    // This is done by taking the maximum of the absolute differences of the x and y coordinates.

    int dx = std::abs(critter->x - x);
    int dy = std::abs(critter->y - y);

    // Check if the critter is within the tower's range in terms of grid cells.
    bool isInRange = (std::max(dx, dy) <= range);

    // Logging for debugging purposes
    std::ofstream("Logs.txt", std::ios::app) << "Tower at (" << x << ", " << y << ") checking target at ("
              << critter->x << ", " << critter->y << "): dx = " << dx
              << ", dy = " << dy << ", range = " << range << " -> In Range: "
              << isInRange << std::endl;

    return isInRange;
}



void Tower::setTargetingStrategy(TargetingStrategy* strategy) {
  if (targetingStrategy) {
    delete targetingStrategy; //clear targetting strategy
  }
  targetingStrategy = strategy;
}

void Tower::acquireTarget(std::vector<Critter*>& targets) {
  if (Critter* target = targetingStrategy->selectTarget(this, targets)) {
    std::ofstream("Logs.txt", std::ios::app) << "Tower at (" << x << ", " <<  y <<  ") is attacking. \n";
    attack(target);
  }
  else {
    std::ofstream("Logs.txt", std::ios::app) << "Tower at (" << x << ", " <<  y <<  ") found no valid target. \n";
  }
}

TargetingStrategy* Tower::getTargetingStrategy() const{
  return targetingStrategy;  //return current targeting strategy
}




bool Tower::isValidPlacement(int coX, int coY, const Map &map, const std::vector<Tower *> &towers) const
{
  if (!map.isWithinBounds(coX, coY))
  {
    ofstream("Logs.txt", std::ios::app) << "Invalid placement: Tower is out of map bounds!" << endl;
    return false;
  }

  if (map.getCellType(coX, coY) != CellType::SCENERY)
  {
    ofstream("Logs.txt", std::ios::app) << "Invalid placement: Tower can only be placed on SCENERY cells!" << endl;
    return false;
  }

  for (const Tower *tower : towers)
  {
    if (tower->x == coX && tower->y == coY)
    {
      ofstream("Logs.txt", std::ios::app) << "Invalid placement: There is already a tower here!" << endl;
      return false;
    }
  }

  return true;
}

void Tower::placeTower(Map &map)
{
  if (map.getCellType(x, y) == CellType::SCENERY)
  {
    map.setCell(x, y, CellType::TOWER);
    ofstream("Logs.txt", std::ios::app) << "Tower successfully placed at (" << x << ", " << y << ")" << endl;
  }
}


int Tower::getRange() const{
  ofstream("Logs.txt", std::ios::app) << "Tower's range of " << range << "!" << endl;
  return range;
 }

int Tower::getLevel() const{
  ofstream("Logs.txt", std::ios::app) << "Tower's level " << level << "!" << endl;
  return level;
}

double Tower::getCost() const{
  ofstream("Logs.txt", std::ios::app) << "Tower's cost " << cost << " gold!" << endl;
  return cost;

 }

 int Tower::getPower() const{
   ofstream("Logs.txt", std::ios::app) << "Tower's power " << power <<  endl;
   return power;
 }

 int Tower::getRateOfFire() const{
   ofstream("Logs.txt", std::ios::app) << "Tower's rate of fire " << rateOfFire << " projectiles per second" << endl;
   return rateOfFire;
 }

 double Tower::getUpgradeCost() const{
   ofstream("Logs.txt", std::ios::app) << "Tower's upgrade cost " << upgradeCost << " gold!" << endl;
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






