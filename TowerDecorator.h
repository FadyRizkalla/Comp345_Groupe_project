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
    TowerDecorator(Tower* tower) : wrappedTower(tower) {
        x = tower->getX(); //initialize base class coordinates from wrapped tower
        y =  tower->getY();
        this->setPower(wrappedTower->getPower());
        this->setRange(wrappedTower->getRange());
        this->setLevel(wrappedTower->getLevel());
        this->setCost(wrappedTower->getCost());
    }
    virtual ~TowerDecorator() { delete wrappedTower; }

    void upgrade(Player& player) override { wrappedTower->upgrade(player); }
    double sell(Player& player) override { return wrappedTower->sell(player); }
    void attack(Critter* critter) override { wrappedTower->attack(critter); }
    int getX() const {return wrappedTower->getX();}
    int getY() const {return wrappedTower->getY();}

};

class LevelUpgradeDecorator : public TowerDecorator {
public:
     LevelUpgradeDecorator(Tower* tower);
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
