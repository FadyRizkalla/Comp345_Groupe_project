//
// Created by Elisa on 2025-02-15.
//

#include "IceWall.h"
#include "Tower.h"
#include "Critter.h"

void IceWall::upgrade(){

    if (playerFunds <= upgradeCost) {

        playerFunds -= upgradeCost;
        level++;
        power += 5;
        range += 10;
        upgradeCost += 50;
        refundValue = cost * 0.6;
        cout << "Archer Tower upgraded to level " << level << "!" << endl;


    }

 }

 void IceWall::attack(Critter* critter){

    int speed = critter->getSpeed() - power;
    critter->setSpeed(speed);
    cout << "The Critter is cold! Speed is " << speed << "." << endl;



 }
