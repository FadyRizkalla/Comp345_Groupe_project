//
// Created by Elisa on 2025-02-15.
//

#ifndef TURRETTOWER_H
#define TURRETTOWER_H
#include "Tower.h"
#include "Player.h"




class TurretTower : public Tower{

    public:
    TurretTower(double x, double y);
    void upgrade(Player &player) override;
    double sell(Player &player) override;

};



#endif //TURRETTOWER_H
