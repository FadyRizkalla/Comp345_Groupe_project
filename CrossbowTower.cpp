//
// Created by Elisa on 2025-02-15.
//

#include "CrossbowTower.h"
#include "Tower.h"
#include "Player.h"
#include <iostream>

#include "ArcherTower.h"
using namespace std;

CrossbowTower::CrossbowTower(double x, double y): Tower(x, y, 175, 15, 12, 6, 75 ,1, 122.5){}

void CrossbowTower::upgrade(Player &player) {


    if (player.getPlayerFunds() >= upgradeCost) {

        player.subtractPlayerFunds(upgradeCost);
        level++;
        power += 10;
        range += 5;
        rateOfFire += 9;
        upgradeCost += 20;
        refundValue = cost * 0.65;
        cout << "Crossbow Tower upgraded to level " << level << "!" << endl;

    }
    else {
        cout << "Tower upgrade failed! Not enough funds" << endl;
    }

}

double CrossbowTower::sell(Player &player) {
    const double sellValue = refundValue + (level * 10.6 );
    cout << "Crossbow tower sold for " << sellValue << " gold! Approx. " << cost - refundValue << " less than initial cost." << endl;
    player.subtractPlayerFunds(sellValue);
    return sellValue;
}

