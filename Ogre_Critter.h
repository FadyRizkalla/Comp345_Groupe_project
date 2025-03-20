#ifndef OGRE_CRITTER_H
#define OGRE_CRITTER_H

#include "Critter.h"

class Ogre_Critter : public Critter
{
public:
    Ogre_Critter();
    double getDistanceToExit() const override;
};

#endif // OGRE_CRITTERS_H