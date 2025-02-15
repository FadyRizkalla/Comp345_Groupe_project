//
// Created by Elisa on 2025-02-04.
//
#pragma once //ensures header file is included only once during compilation
#ifndef TOWER_H
#define TOWER_H
#include <vector>

class Critter;

class Tower {


  protected:
    int cost;
    int refundValue;
    int range;
    int power;
    int rateOfFire;
    int level;
    int upgradeCost;

    public:
      Tower(); // default constructor
      Tower(int cost, int range, int power, int rateOfFire, int upgradeCost); //Parameterized Constructor
      Tower(const Tower& tower); //copy constructor

      virtual ~Tower(); //destructor
      virtual void upgrade(); //Upgrading and Selling functions to be overwritten in derived class
      virtual int sell();

      // each tower redefines its own attack methods
      virtual void attack(Critter* target) = 0; // method on how each tower attacks a critter
      bool isTargetInRange(Critter* target); // checking if the critter is in range
      Critter* acquireTarget(std::vector<Critter*>& enemies); // acquiring the critters to shoot at them

      int getRange() const; //Getters. Method is defined in the derived class
      int getLevel() const;
      int getCost() const;
      int getPower() const;
      int getRateOfFire() const;
      int getUpgradeCost() const;

      void setRange(int x); //Setters. Method is defined in the derived class
      void setLevel(int x);
      void setCost(int x);
      void setPower(int x);
      void setRateOfFire(int x);
      void setUpgradeCost(int x);

};


#endif //TOWER_H
