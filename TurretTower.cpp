//
// Created by Elisa on 2025-02-15.
//

#include "TurretTower.h"
#include "Tower.h"
#include <iostream>
using namespace std;



void TurretTower::upgrade() {

    if (playerFunds >= upgradeCost) {

        playerFunds -= upgradeCost;
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

    double sellValue = refundValue + (level * 10.9);
    cout << "Sniper tower sold for " << sellValue << " gold! Approx. " << cost - refundValue << " less than initial cost." << endl;
    playerFunds += sellValue;
    return sellValue;
}