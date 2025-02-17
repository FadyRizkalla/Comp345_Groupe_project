#include "Ogre_Critter.h"
#include <iostream>

using namespace std;

// Constructor that initializes the base Critter class and the unique Ogre attributes.
Ogre_Critter::Ogre_Critter(int hp, int str, int spd, int lvl, int smash, int def)
    : Critter(hp, str, spd, lvl), smashPower(smash), defense(def) {}

// Executes a smash attack, showcasing the ogre's smashPower.
void Ogre_Critter::smashAttack() {
    cout << "The Ogre Critter performs a smash attack with power " << smashPower << "!" << endl;
}

// Executes a defensive action, showcasing the ogre's defense.
void Ogre_Critter::defend() {
    cout << "The Ogre Critter defends itself with a defense rating of " << defense << "!" << endl;
}

// Returns the smash power.
int Ogre_Critter::getSmashPower() const {
    return smashPower;
}

// Returns the defense rating.
int Ogre_Critter::getDefense() const {
    return defense;
}
