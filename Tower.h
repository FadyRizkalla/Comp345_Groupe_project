//
// Created by Elisa on 2025-02-04.
//
#pragma once //ensures header file is included only once during compilation
#ifndef TOWER_H
#define TOWER_H
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
    double playerFunds;

    public:
      Tower(); // default constructor
      Tower(double x, double y, double cost, int range, int power, int rateOfFire, double upgradeCost, int level, double refundValue); //Parameterized Constructor
      Tower(const Tower& tower); //copy constructor

      virtual ~Tower(); //destructor
      virtual void upgrade(); //Upgrading and Selling functions to be overwritten in derived class
      virtual double sell();

      // each tower redefines its own attack methods
      virtual void attack(Critter* critter) = 0; // method on how each tower attacks a critter
      bool isTargetInRange(Critter* Critter); // checking if the critter is in range
      Critter* acquireTarget(std::vector<Critter *>& targets); // Selecting the critters to attack

      //method to allow the user to input a tower in the map.
      bool isValidPlacement(int coX, int coY, const Map& map, const std::vector<Tower*>& towers);



      int getRange() const; //Getters. Method is defined in the derived class
      int getLevel() const;
      double getCost() const;
      int getPower() const;
      int getRateOfFire() const;
      double getUpgradeCost() const;
      double getPlayerFunds() const;

      void setRange(int x); //Setters. Method is defined in the derived class
      void setLevel(int x);
      void setCost(double x);
      void setPower(int x);
      void setRateOfFire(int x);
      void setUpgradeCost(double x);
      void setPlayerFunds(double x);

};


#endif //TOWER_H
