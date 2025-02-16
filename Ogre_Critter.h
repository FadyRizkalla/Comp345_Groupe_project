#ifndef OGRE_CRITTER_H
#define OGRE_CRITTER_H

#include "Critter.h"

class Ogre_Critter : public Critter {
private:
    int smashPower; // Represents the power of the ogre's smash attack.
    int defense;    // Represents the ogre's ability to absorb or deflect damage.

public:
    // Constructor with default values for smashPower (10) and defense (5)
    Ogre_Critter(int hp, int str, int spd, int lvl, int smash = 10, int def = 5);

    // Unique behaviors for an ogre
    void smashAttack();  // Performs a smash attack
    void defend();       // Performs a defensive action

    // Getters for the unique attributes
    int getSmashPower() const;
    int getDefense() const;
};

#endif // OGRE_CRITTER_H
