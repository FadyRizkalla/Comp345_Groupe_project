#include "TowerDecorator.h"
#include <iostream>


// LevelUpgradeDecorator
LevelUpgradeDecorator::LevelUpgradeDecorator(Tower* tower) : TowerDecorator(tower) {
    wrappedTower->setLevel(wrappedTower->getLevel() + 1);
    wrappedTower->setPower(wrappedTower->getPower() + 10);
    wrappedTower->setRange(wrappedTower->getRange() + 2);
    wrappedTower->setUpgradeCost(wrappedTower->getUpgradeCost() + 50);
}

void LevelUpgradeDecorator::upgrade(Player& player) {
    TowerDecorator::upgrade(player);
}

// SplashDamageDecorator
SplashDamageDecorator::SplashDamageDecorator(Tower* tower) : TowerDecorator(tower) {}

void SplashDamageDecorator::attack(Critter* critter) {
    wrappedTower->attack(critter);
    std::cout << "Splash damage applied to nearby critters!\n";
}

// BurningDamageDecorator
BurningDamageDecorator::BurningDamageDecorator(Tower* tower)
    : TowerDecorator(tower), burnDuration(3), burnDamage(5) {}

void BurningDamageDecorator::attack(Critter* critter) {
    wrappedTower->attack(critter);
    std::cout << "Burning effect applied: " << burnDamage << " damage for " << burnDuration << " seconds!\n";
}

// FreezingEffectDecorator
FreezingEffectDecorator::FreezingEffectDecorator(Tower* tower) : TowerDecorator(tower) {}

void FreezingEffectDecorator::attack(Critter* critter) {
    wrappedTower->attack(critter);
    std::cout << "Freezing effect applied: Critter slowed!\n";
}