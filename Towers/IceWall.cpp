//
// Created by Elisa on 2025-02-15.
//

#include "IceWall.h"
#include "Tower.h"
#include "./Critters/Critter.h"
#include "./Player/Player.h"
#include <iostream>
#include <fstream>


IceWall::IceWall(double x, double y): Tower(x, y, 275, 40, 50, 0, 200 ,1, 192.5){}

void IceWall::upgrade(Player& player) {
    if (player.hasEnoughFunds(upgradeCost)) {
        player.subtractPlayerFunds(upgradeCost);
        level++;
        std::ofstream("Logs.txt", std::ios::app) << "Ice Wall upgraded to level " << level << "!" << std::endl;
    } else {
        std::ofstream("Logs.txt", std::ios::app) << "Tower upgrade failed! Not enough funds" << std::endl;
    }
}

void IceWall::attack(Critter* critter) {
    if (critter) {
        critter->setSpeed(critter->getSpeed() / 2);
        std::ofstream("Logs.txt", std::ios::app) << "The Critter is cold! Speed is " << critter->getSpeed() << "." << std::endl;
    }
}
