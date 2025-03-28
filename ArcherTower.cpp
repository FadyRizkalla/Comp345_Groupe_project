//
// Created by Elisa on 2025-02-15.
//

#include "ArcherTower.h"
#include "Tower.h"
#include "Player.h"
#include <fstream>
#include <iostream>
using namespace std;


ArcherTower::ArcherTower(double x, double y): Tower(x, y, 100, 5, 5, 2, 50 ,1, 70){}

void ArcherTower::upgrade(Player &player) {


    if (player.getPlayerFunds() >= upgradeCost) {

        player.subtractPlayerFunds(upgradeCost);
        level++;
        power += 5;
        range += 2;
        rateOfFire += 5;
        upgradeCost += 50;
        refundValue = cost * 0.6;
        ofstream("Logs.txt", std::ios::app) << "Archer Tower upgraded to level " << level << "!" << endl;
    }
    else {
        ofstream("Logs.txt", std::ios::app) << "Tower upgrade failed! Not enough funds" << endl;
    }

}

double ArcherTower::sell(Player &player) {
    double sellValue = refundValue + (level * 10.4 );
    ofstream("Logs.txt", std::ios::app) << "Archer tower sold for " << sellValue << " gold! Approx. " << cost - refundValue << " less than initial cost." << endl;
    player.subtractPlayerFunds(sellValue);
    return sellValue;
}

