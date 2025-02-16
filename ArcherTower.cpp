//
// Created by Elisa on 2025-02-15.
//

#include "ArcherTower.h"
#include "Tower.h"

void attack(Critter *critter) {

    for (int i = 0; i < rateOfFire; i++) {

        critter->takeDamage(power);
        cout << "Tower attacking!" << "Critter just lost " << power << " health." << endl;
        if(critter->getStrength() < 0) {
            cout << "Critter died!" << endl;
        }

    }

}

void upgrade() {

    if (playerFunds <= upgradeCost) {

        playerFunds - upgradeCost;
        level++;
        power += 5;
        range += 2;
        rateOfFire += 5;
        upgradeCost += 50;
        refundValue = cost * 0.6;
        cout << "Archer Tower upgraded to level " << level << "!" << endl;


    }

}

double sell() {

    double sellValue = refundValue + (level * 10.4 );
    cout << "Archer tower sold for " << sellValue << " gold! Approx. " << cost - refundValue << " less than initial cost." << endl;
    playerFunds += sellValue;
    return sellValue;
}

