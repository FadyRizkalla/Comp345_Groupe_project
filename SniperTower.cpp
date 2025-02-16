//
// Created by Elisa on 2025-02-15.
//

#include "SniperTower.h"
#include "Tower.h"
#include <iostream>
using namespace std;



void SniperTower::upgrade() {

    if (playerFunds <= upgradeCost) {

        playerFunds -= upgradeCost;
        level++;
        power += 20;
        range += 10;
        rateOfFire += 12;
        upgradeCost += 120;
        refundValue = cost * 0.67;
        cout << "Crossbow Tower upgraded to level " << level << "!" << endl;


    }

}

double SniperTower::sell() {

    double sellValue = refundValue + (level * 10.8);
    cout << "Sniper tower sold for " << sellValue << " gold! Approx. " << cost - refundValue << " less than initial cost." << endl;
    playerFunds += sellValue;
    return sellValue;
}
