// CritterFactory.cpp
#include "CritterFactory.h"
#include <cstdlib> // For rand()
#include <iostream>

std::vector<Critter*> CritterFactory::createCritters(int waveNumber, std::pair<int, int> entryPoint, std::pair<int, int> exitPoint, std::vector<std::pair<int, int>>& path) {
    std::vector<Critter*> critters;

    // Difficulty increases with the wave number, adjust stats accordingly
    for (int i = 0; i < waveNumber * 2; i++) { // Increase number of critters with each wave
        Critter* critter = nullptr;
        int type = rand() % 2; // Randomly choose between Goblin and Ogre

        // Difficulty scaling based on wave
        if (type == 0) {
            critter = new Goblin_Critter();
            critter->setHitPoint(100 + waveNumber * 10); // Goblins get stronger with each wave
            critter->setSpeed(2.0f + waveNumber * 0.1f); // Speed increases with each wave
        } else {
            critter = new Ogre_Critter();
            critter->setHitPoint(150 + waveNumber * 15); // Ogres get stronger with each wave
            critter->setSpeed(1.5f + waveNumber * 0.05f); // Speed increases with each wave
        }

        critter->setPosition(entryPoint.first, entryPoint.second);
        critter->setPath(path); // Path is generated based on the map
        critter->setExit(exitPoint.first, exitPoint.second);
        critters.push_back(critter);
    }

    return critters;
}
