//
// Created by Elisa on 2025-03-17.
//
#include "TargetingStrategy.h"
#include "Tower.h"
#include <cmath>
#include <algorithm>

Critter* NearestToTowerStrategy::selectTarget(const Tower* tower, std::vector<Critter*>& targets) {
    Critter* closest = nullptr;
    double minDistance = std::numeric_limits<double>::max();

    for (Critter* critter : targets) {
        if (tower->isTargetInRange(critter)) {
            double distance = std::sqrt(std::pow(critter->x - tower->getX(), 2) +
                                      std::pow(critter->y - tower->getY(), 2));
            if (distance < minDistance) {
                minDistance = distance;
                closest = critter;
            }
        }
    }
    return closest;
}

Critter* NearestToExitStrategy::selectTarget(const Tower* tower, std::vector<Critter*>& targets) {
    Critter* nearestToExit = nullptr;
    double minDistanceToExit = std::numeric_limits<double>::max();

    // Assuming Critter has a method getDistanceToExit() or similar
    for (Critter* critter : targets) {
        if (tower->isTargetInRange(critter)) {
            double distanceToExit = critter->getDistanceToExit(); // Implement in Critter class
            if (distanceToExit < minDistanceToExit) {
                minDistanceToExit = distanceToExit;
                nearestToExit = critter;
            }
        }
    }
    return nearestToExit;
}

Critter* StrongestCritterStrategy::selectTarget(const Tower* tower, std::vector<Critter*>& targets) {
    Critter* strongest = nullptr;
    int maxStrength = -1;

    for (Critter* critter : targets) {
        if (tower->isTargetInRange(critter)) {
            if (critter->getStrength() > maxStrength) {
                maxStrength = critter->getStrength();
                strongest = critter;
            }
        }
    }
    return strongest;
}

Critter* WeakestCritterStrategy::selectTarget(const Tower* tower, std::vector<Critter*>& targets) {
    Critter* weakest = nullptr;
    int minStrength = std::numeric_limits<int>::max();

    for (Critter* critter : targets) {
        if (tower->isTargetInRange(critter)) {
            if (critter->getStrength() < minStrength) {
                minStrength = critter->getStrength();
                weakest = critter;
            }
        }
    }
    return weakest;
}