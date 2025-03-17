//
// Created by Elisa on 2025-03-17.
//
#include "TowerDecorator.h"

LevelUpgradeDecorator::LevelUpgradeDecorator(Tower* tower) : TowerDecorator(tower) {
    wrappedTower->setLevel(wrappedTower->getLevel() + 1);
    wrappedTower->setPower(wrappedTower->getPower() + 10);
    wrappedTower->setRange(wrappedTower->getRange() + 2);
    wrappedTower->setUpgradeCost(wrappedTower->getUpgradeCost() + 50);
}

void LevelUpgradeDecorator::upgrade(Player& player) {
    TowerDecorator::upgrade(player);
    // Additional upgrade effects if needed
}

SplashDamageDecorator::SplashDamageDecorator(Tower* tower) : TowerDecorator(tower) {}

void SplashDamageDecorator::attack(Critter* critter) {
    wrappedTower->attack(critter);
    // Add splash damage logic here (would need access to nearby critters)
    std::cout << "Splash damage applied to nearby critters!\n";
}

BurningDamageDecorator::BurningDamageDecorator(Tower* tower)
    : TowerDecorator(tower), burnDuration(3), burnDamage(5) {}

void BurningDamageDecorator::attack(Critter* critter) {
    wrappedTower->attack(critter);
    // Simulate burning effect (in a real game, this would be handled over time)
    std::cout << "Burning effect applied: " << burnDamage << " damage for " << burnDuration << " seconds!\n";
}

FreezingEffectDecorator::FreezingEffectDecorator(Tower* tower) : TowerDecorator(tower) {}

void FreezingEffectDecorator::attack(Critter* critter) {
    wrappedTower->attack(critter);
    // Add freezing effect (would need to modify Critter speed)
    std::cout << "Freezing effect applied: Critter slowed!\n";
}