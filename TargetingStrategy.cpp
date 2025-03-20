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

TargetingStrategy* NearestToTowerStrategy::clone() const {
    return new NearestToTowerStrategy(*this);
}

Critter* NearestToExitStrategy::selectTarget(const Tower* tower, std::vector<Critter*>& targets) {
    Critter* nearestToExit = nullptr;
    double minDistanceToExit = std::numeric_limits<double>::max();
    for (Critter* critter : targets) {
        if (tower->isTargetInRange(critter)) {
            double distanceToExit = critter->getDistanceToExit();
            if (distanceToExit < minDistanceToExit) {
                minDistanceToExit = distanceToExit;
                nearestToExit = critter;
            }
        }
    }
    return nearestToExit;
}

TargetingStrategy* NearestToExitStrategy::clone() const {
    return new NearestToExitStrategy(*this);
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

TargetingStrategy* StrongestCritterStrategy::clone() const {
    return new StrongestCritterStrategy(*this);
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

TargetingStrategy* WeakestCritterStrategy::clone() const {
    return new WeakestCritterStrategy(*this);
}