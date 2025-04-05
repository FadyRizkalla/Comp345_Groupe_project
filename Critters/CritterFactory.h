// CritterFactory.h
#ifndef CRITTER_FACTORY_H
#define CRITTER_FACTORY_H

#include "Critter.h"
#include "Goblin_Critter.h"
#include "Ogre_Critter.h"
#include <vector>
#include <utility> // for std::pair

class CritterFactory {
public:
    // Creates a wave of critters based on the wave number, entry, and exit points.
    static std::vector<Critter*> createCritters(int waveNumber, std::pair<int, int> entryPoint, std::pair<int, int> exitPoint, std::vector<std::pair<int, int>>& path);

private:
};

#endif // CRITTER_FACTORY_H
