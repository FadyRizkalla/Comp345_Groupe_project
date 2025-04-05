//
// Created by Elisa on 2025-02-15.
//

#ifndef CROSSBOWTOWER_H
#define CROSSBOWTOWER_H
#include "Tower.h"


class CrossbowTower : public Tower {

    public:
    CrossbowTower(double x, double y);
    void upgrade(Player &player) override;
    double sell(Player &player) override;
};



#endif //CROSSBOWTOWER_H
