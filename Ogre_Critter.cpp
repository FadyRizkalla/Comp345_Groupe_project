#include "Ogre_Critter.h"

Ogre_Critter::Ogre_Critter() : Critter(50, 10, 1, 2) {}

double Ogre_Critter::getDistanceToExit() const {
    return Critter::getDistanceToExit();
}