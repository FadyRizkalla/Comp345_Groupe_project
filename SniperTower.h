//
// Created by Elisa on 2025-02-15.
//

#ifndef SNIPERTOWER_H
#define SNIPERTOWER_H
#include "Tower.h"


class SniperTower : public Tower {
    public:
    SniperTower(double x, double y);
    void upgrade(Player &player) override;
    double sell(Player &player) override;
};



#endif //SNIPERTOWER_H
