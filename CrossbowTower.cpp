//
// Created by Elisa on 2025-02-15.
//

#include "CrossbowTower.h"
#include "Tower.h"
#include <iostream>
using namespace std;



void CrossbowTower::upgrade() {

    if (playerFunds <= upgradeCost) {

        playerFunds -= upgradeCost;
        level++;
        power += 10;
        range += 5;
        rateOfFire += 9;
        upgradeCost += 20;
        refundValue = cost * 0.65;
        cout << "Crossbow Tower upgraded to level " << level << "!" << endl;


    }

}

double CrossbowTower::sell() {

    double sellValue = refundValue + (level * 10.6 );
    cout << "Crossbow tower sold for " << sellValue << " gold! Approx. " << cost - refundValue << " less than initial cost." << endl;
    playerFunds += sellValue;
    return sellValue;
}

