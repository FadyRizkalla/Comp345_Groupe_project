//
// Created by Elisa on 2025-02-15.
//

#ifndef SNIPERTOWER_H
#define SNIPERTOWER_H
#include "Tower.h"

/*
 * Sniper Tower is the 3rd tower in the tower tier.
 * It's special feature is it's incredibly large range.
 * It can shoot critters from a far away distance, and its shots
 * deal effective direct damage.
 */

class SniperTower : Tower {
    public:
    SniperTower(double x, double y) : Tower(x, y, 210, 60, 20, 10, 120 ,1, 147) {};
    void upgrade() override;
    double sell() override;
};



#endif //SNIPERTOWER_H
