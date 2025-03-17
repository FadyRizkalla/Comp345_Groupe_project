//
// Created by Elisa on 2025-03-17.
//

#ifndef TOWER_DECORATOR_H
#define TOWER_DECORATOR_H

#include "Tower.h"

class TowerDecorator : public Tower {
protected:
    Tower* wrappedTower;

public:
    TowerDecorator(Tower* tower) : wrappedTower(tower) {}
    virtual ~TowerDecorator() { delete wrappedTower; }

    void upgrade(Player& player) override { wrappedTower->upgrade(player); }
    double sell(Player& player) override { return wrappedTower->sell(player); }
    void attack(Critter* critter) override { wrappedTower->attack(critter); }

};

class LevelUpgradeDecorator : public TowerDecorator {
public:
    LevelUpgradeDecorator(Tower* tower);
    void upgrade(Player& player) override;
};

class SplashDamageDecorator : public TowerDecorator {
public:
    SplashDamageDecorator(Tower* tower);
    void attack(Critter* critter) override;
};

class BurningDamageDecorator : public TowerDecorator {
private:
    int burnDuration;
    int burnDamage;
public:
    BurningDamageDecorator(Tower* tower);
    void attack(Critter* critter) override;
};

class FreezingEffectDecorator : public TowerDecorator {
public:
    FreezingEffectDecorator(Tower* tower);
    void attack(Critter* critter) override;
};


#endif //TOWERDECORATOR_H
