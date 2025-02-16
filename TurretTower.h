//
// Created by Elisa on 2025-02-15.
//

#ifndef TURRETTOWER_H
#define TURRETTOWER_H
#include "Tower.h"


/*
 *Turret Tower is the last/5th tier for towers. It is the strongest, fastest, and
 *most expensive tower. It has no special effects, but it can shoot through
 *any critter with ease. It can be too OP at times. Although the price is high,
 *it can be sold or refunded for a better value than most other towers.
*/


class TurretTower : Tower{

    public:
    TurretTower(double x, double y) : Tower(x, y, 500, 50, 30, 60, 270 ,1, 350) {};
    void upgrade() override;
    double sell() override;

};



#endif //TURRETTOWER_H
