//
// Created by Elisa on 2025-02-04.
//

#include "Tower.h"
#include "Critter.h"
#include <iostream>
#include <cmath>
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
Tower::Tower(double x, double y, double cost, int range, int power, int rateOfFire, double upgradeCost, int level, double refundValue) {

  x = x;
  y = y;
  cost = cost;
  range = range;
  power = power;
  rateOfFire = rateOfFire;
  upgradeCost = upgradeCost;
  level = level;

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

  level++;
  power += 10;
  range += 2;
  rateOfFire += 5;
  upgradeCost += 50;
  refundValue = cost * 0.6;
  cout << "Tower upgraded to level " << level << "!" << endl;

}


// you can sell an item for approx. the same amount as the refund value.
double Tower::sell(){
  double sellValue = refundValue + (level * 10.4 );
  cout << "Tower selling " << sellValue << " gold! Approx. " << cost - refundValue << " less than initial cost." << endl;
  playerFunds += sellValue;
  return sellValue;
}

//towers attack critters
void attack(Critter* critter) {

  for (int i = 0; i < rateOfFire; i++) {

    critter->takeDamage(power);
    cout << "Tower attacking!" << "Critter just lost " << power << " health." << endl;
    if(critter->getStrength() < 0) {
      cout << "Critter died!" << endl;
    }

  }

}

//search for critters in range
bool isTargetInRange(Critter* critter) {
  double distance = sqrt(pow(critter->x - x , 2) + pow(critter->y - y , 2));
  return distance <= range;

}

//Get critters in range and attack them
Critter* acquireTarget(std::vector<Critter*> targets) {

  for (Critter* critter : targets) {
    if(isTargetInRange(critter)) {
      attack(critter);
    }
  }

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

int Tower::getCost() const{
  cout << "Tower's cost " << cost << " gold!" << endl;
  return cost;

 }

 int Tower::getPower() const{
   cout << "Tower's power " << power << endl;
   return power;
 }

 int Tower::getRateOfFire() const{
   cout << "Tower's rateOfFire " << rateOfFire << endl;
   return rateOfFire;
 }

 int Tower::getUpgradeCost() const{
   cout << "Tower's upgradeCost " << upgradeCost << " gold!" << endl;
   return upgradeCost;
 }


 // Setters (setting methods)

 void Tower::setRange(int range){

   range = range;
 }

 void Tower::setLevel(int level){
   level = level;
 }


 void Tower::setCost(double cost){
   cost = cost;
 }

 void Tower::setPower(int power){
   power = power;
 }

 void Tower::setRateOfFire(int rateOfFire){
   rateOfFire = rateOfFire;
 }

 void Tower::setUpgradeCost(double upgradeCost){
   upgradeCost = upgradeCost;
 }

 void Tower::setPlayerFunds(double x) {
  playerFunds = x;

}






