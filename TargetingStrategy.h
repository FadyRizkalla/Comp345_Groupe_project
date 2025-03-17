//
// Created by Elisa on 2025-03-17.
//

#ifndef TARGETING_STRATEGY_H
#define TARGETING_STRATEGY_H

#include <vector>
#include "Critter.h"

class Tower;

class TargetingStrategy {
public:
    virtual ~TargetingStrategy() = default;
    virtual Critter* selectTarget(const Tower* tower, std::vector<Critter*>& targets) = 0;

    TargetingStrategy * clone();
};

class NearestToTowerStrategy : public TargetingStrategy {
public:
    Critter* selectTarget(const Tower* tower, std::vector<Critter*>& targets) override;
};

class NearestToExitStrategy : public TargetingStrategy {
public:
    Critter* selectTarget(const Tower* tower, std::vector<Critter*>& targets) override;
};

class StrongestCritterStrategy : public TargetingStrategy {
public:
    Critter* selectTarget(const Tower* tower, std::vector<Critter*>& targets) override;
};

class WeakestCritterStrategy : public TargetingStrategy {
public:
    Critter* selectTarget(const Tower* tower, std::vector<Critter*>& targets) override;
};

#endif //TARGETINGSTRATEGY_H
