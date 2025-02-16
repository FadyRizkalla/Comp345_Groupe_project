#include "Goblin_Critter.h"
#include <iostream>

using namespace std;

// Constructor, calls the base class constructor
Goblin_Critter::Goblin_Critter(int hp, int str, int spd, int lvl, int stl)
    : Critter(hp, str, spd, lvl), stealth(stl) {}

// Unique function for goblins
void Goblin_Critter::ambush() {
    cout << "The Goblin Critter ambushes its enemy using stealth level " << stealth << "!\n";
}

// Getter for stealth
int Goblin_Critter::getStealth() const {
    return stealth;
}
