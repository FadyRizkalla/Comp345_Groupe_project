//
// Created by Elisa on 2025-02-04.
//
#pragma once //ensures header file is only included only once during compilation
#ifndef TOWER_H
#define TOWER_H
#include <vector>

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

      int getRange() const; //Getters for the Range and t he level. Method is defined in the derived class
      int getLevel() const;

};



#endif //TOWER_H
