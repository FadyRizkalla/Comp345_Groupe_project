//
// Created by fadig on 2025-02-16.
//

#ifndef GOBLIN_CRITTER_H
#define GOBLIN_CRITTER_H



#ifndef CRITTER_H
#define CRITTER_H

#include <iostream>
#include "Critter.h"
using namespace std;

class Goblin_Critter:: public Critter {
private:
  int stealth;
public:
  // Constructor
  Goblin_Critter(int hp, int str, int spd, int lvl, int stl);

  // Additional behavior
  void ambush(); // Unique function for goblins

  // Getter for stealth
  int getStealth() const;
}



#endif //GOBLIN_CRITTER_H
