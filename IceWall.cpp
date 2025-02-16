//
// Created by Elisa on 2025-02-15.
//

#include "IceWall.h"
#include "Tower.h"
#include "Critter.h"
#include "Player.h"

IceWall::IceWall(double x, double y) {
    Tower iceWall(x, y, 275, 40, 50, 0, 200 ,1, 192.5);

}

void IceWall::upgrade(){

    Player player{};

    if (player.getPlayerFunds() >= upgradeCost) {

        player.setPlayerFunds(player.getPlayerFunds() - upgradeCost);
        level++;
        power += 5;
        range += 10;
        upgradeCost += 50;
        refundValue = cost * 0.6;
        cout << "Archer Tower upgraded to level " << level << "!" << endl;

    }
    else{
        cout << "Tower upgrade failed! Not enough funds" << endl;
    }

 }

 void IceWall::attack(Critter* critter){

    int speed = critter->getSpeed() - power;
    critter->setSpeed(speed);
    cout << "The Critter is cold! Speed is " << speed << "." << endl;



 }
