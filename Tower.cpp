//
// Created by Elisa on 2025-02-04.
//

#include "Tower.h"
#include <iostream>
using namespace std;

Tower::Tower() {

  cost = 0;
  range = 0;
  power = 0;
  rateOfFire = 0;
  upgradeCost = 0;

}

Tower::Tower(int cost, int range, int power, int rateOfFire, int upgradeCost) {

  cost = cost;
  range = range;
  power = power;
  rateOfFire = rateOfFire;
  upgradeCost = upgradeCost;

}

void Tower::Upgrade() {

  level++;
  power += 10;
  range += 2;
  upgradeCost += 50;
  refundValue = cost * 0.6;
  cout << "Tower upgraded to level " << level << "!" << endl;

}

int Tower::sell(){
  cout << "Tower selling " << refundValue << " gold! Approx. " << cost - refundValue << " less than initial cost." << endl;
  return refundValue;

}

int Tower::getRange(){
  cout << "Tower's range of " << range << "!" << endl;
  return range;
 }

int Tower::getLevel(){
  cout << "Tower's level " << level << "!" << endl;
  return level;
}

int Tower::getCost(){
  cout << "Tower's cost " << cost << " gold!" << endl;
  return cost;

 }

 int Tower::getPower(){
   cout << "Tower's power " << power << endl;
   return power;
 }

 int Tower::getRateOfFire(){
   cout << "Tower's rateOfFire " << rateOfFire << endl;
   return rateOfFire;
 }

 int Tower::getUpgradeCost(){
   cout << "Tower's upgradeCost " << upgradeCost << " gold!" << endl;
   return upgradeCost;
 }






