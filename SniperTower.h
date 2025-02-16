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

class SniperTower : public Tower {
    public:
    SniperTower(double x, double y);
    void upgrade() override;
    double sell() override;
};



#endif //SNIPERTOWER_H
