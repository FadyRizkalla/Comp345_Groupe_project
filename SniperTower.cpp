//
// Created by Elisa on 2025-02-15.
//

#include "SniperTower.h"
#include "Tower.h"
#include "Player.h"
#include <iostream>
using namespace std;

SniperTower::SniperTower(double x, double y) {
    Tower sTower(x, y, 210, 60, 20, 10, 120 ,1, 147);

}

void SniperTower::upgrade() {

    Player player;

    if (player.getPlayerFunds() >= upgradeCost) {

        player.setPlayerFunds(player.getPlayerFunds() - upgradeCost);
        level++;
        power += 20;
        range += 10;
        rateOfFire += 12;
        upgradeCost += 120;
        refundValue = cost * 0.67;
        cout << "Crossbow Tower upgraded to level " << level << "!" << endl;


    }
    else {
        cout << "Tower upgrade failed! Not enough funds" << endl;
    }


}

double SniperTower::sell() {

    Player player;
    double sellValue = refundValue + (level * 10.8);
    cout << "Sniper tower sold for " << sellValue << " gold! Approx. " << cost - refundValue << " less than initial cost." << endl;
    player.setPlayerFunds(player.getPlayerFunds() - sellValue);
    return sellValue;
}
