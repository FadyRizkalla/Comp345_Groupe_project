//
// Created by Elisa on 2025-03-17.
//

#ifndef TARGETING_STRATEGY_H
#define TARGETING_STRATEGY_H

#include <vector>
#include "./Critters/Critter.h"

class Tower;

class TargetingStrategy {
public:
    virtual ~TargetingStrategy() = default;
    virtual Critter* selectTarget(const Tower* tower, std::vector<Critter*>& targets) = 0;

    virtual TargetingStrategy * clone() const = 0; //pure virtual clone method
};

class NearestToTowerStrategy : public TargetingStrategy {
public:
    Critter* selectTarget(const Tower* tower, std::vector<Critter*>& targets) override;
    TargetingStrategy * clone() const override;
};

class NearestToExitStrategy : public TargetingStrategy {
public:
    Critter* selectTarget(const Tower* tower, std::vector<Critter*>& targets) override;
    TargetingStrategy * clone() const override;

};

class StrongestCritterStrategy : public TargetingStrategy {
public:
    Critter* selectTarget(const Tower* tower, std::vector<Critter*>& targets) override;
    TargetingStrategy * clone() const override;

};

class WeakestCritterStrategy : public TargetingStrategy {
public:
    Critter* selectTarget(const Tower* tower, std::vector<Critter*>& targets) override;
    TargetingStrategy * clone() const override;

};

#endif //TARGETINGSTRATEGY_H
