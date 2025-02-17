//
// Created by Elisa on 2025-02-04.
//
#pragma once //ensures header file is included only once during compilation
#ifndef TOWER_H
#define TOWER_H
#include <Player.h>
#include <vector>
#include "Map.h"
#include "Critter.h"


class Critter;

class Tower {


  protected:

    int x, y;
    double cost;
    int range;
    int power;
    int rateOfFire;
    int level;
    double upgradeCost;
    double refundValue;

    public:
      Tower(); // default constructor
      Tower(double x, double y, double cost, int range, int power, int rateOfFire, double upgradeCost, int level, double refundValue); //Parameterized Constructor
      Tower(const Tower& tower); //copy constructor

      virtual ~Tower(); //destructor
      virtual void upgrade(Player &player); //Upgrading and Selling functions to be overwritten in derived class
      virtual double sell(Player &player);

      // each tower redefines its own attack methods
      virtual void attack(Critter* critter); // method on how each tower attacks a critter
      bool isTargetInRange(const Critter* Critter) const; // checking if the critter is in range
      void acquireTarget(std::vector<Critter *>& targets); // Selecting the critters to attack

      //method to allow the user to input a tower in the map.
      bool isValidPlacement(int coX, int coY, const Map& map, const std::vector<Tower*>& towers) const;

      int getRange() const; //Getters. Method is defined in the derived class
      int getLevel() const;
      double getCost() const;
      int getPower() const;
      int getRateOfFire() const;
      double getUpgradeCost() const;

      void setRange(int x); //Setters. Method is defined in the derived class
      void setLevel(int x);
      void setCost(double x);
      void setPower(int x);
      void setRateOfFire(int x);
      void setUpgradeCost(double x);

};


#endif //TOWER_H
