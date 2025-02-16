//
// Created by Elisa on 2025-02-15.
//

#include "TurretTower.h"
#include "Tower.h"
#include "Player.h"
#include <iostream>
using namespace std;

TurretTower::TurretTower(double x, double y) {
    Tower tTower(x, y, 500, 50, 30, 60, 270 ,1, 350);

}


void TurretTower::upgrade() {

    Player player;

    if (player.getPlayerFunds() >= upgradeCost) {

        player.setPlayerFunds(player.getPlayerFunds() - upgradeCost);
        level++;
        power += 75;
        range += 20;
        rateOfFire += 30;
        upgradeCost += 120;
        refundValue = cost * 0.70;
        cout << "Crossbow Tower upgraded to level " << level << "!" << endl;

    }
    else {
        cout << "Tower upgrade failed! Not enough funds" << endl;
    }

}

double TurretTower::sell() {
    Player player;
    double sellValue = refundValue + (level * 10.9);
    cout << "Sniper tower sold for " << sellValue << " gold! Approx. " << cost - refundValue << " less than initial cost." << endl;
    player.setPlayerFunds(player.getPlayerFunds() - sellValue);
    return sellValue;
}