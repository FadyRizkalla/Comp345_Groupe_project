//
// Created by Elisa on 2025-02-04.
//

#include "Tower.h"
#include <iostream>
using namespace std;

// Default constructor. Makes an instance of a Tower, without any features
Tower::Tower() {

  cost = 0;
  range = 0;
  power = 0;
  rateOfFire = 0;
  upgradeCost = 0;

}

// Parameritized constructor.
Tower::Tower(int cost, int range, int power, int rateOfFire, int upgradeCost) {

  cost = cost;
  range = range;
  power = power;
  rateOfFire = rateOfFire;
  upgradeCost = upgradeCost;

}

// method for upgrading a tower
void Tower::upgrade(){

  level++;
  power += 10;
  range += 2;
  upgradeCost += 50;
  refundValue = cost * 0.6;
  cout << "Tower upgraded to level " << level << "!" << endl;

}


// you can sell an item for approx. the same amount as the refund value.
int Tower::sell(){
  cout << "Tower selling " << refundValue + (level * 10.4 ) << " gold! Approx. " << cost - refundValue << " less than initial cost." << endl;
  return refundValue;

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


 void Tower::setCost(int cost){
   cost = cost;
 }

 void Tower::setPower(int power){
   power = power;
 }

 void Tower::setRateOfFire(int rateOfFire){
   rateOfFire = rateOfFire;
 }

 void Tower::setUpgradeCost(int upgradeCost){
   upgradeCost = upgradeCost;
 }





