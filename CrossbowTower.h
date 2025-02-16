//
// Created by Elisa on 2025-02-15.
//

#ifndef CROSSBOWTOWER_H
#define CROSSBOWTOWER_H
#include "Tower.h"

/*
 *This is the second tier for towers. Cross bows are faster and have a longer range
 *than archers. However, they are still weaker than the next towers in the list.
 *They have the advantage of range, cost, power, and rate of fire over archers.
 *However, crossbow towers cost a lot more to make. Moreover, there's no special features like
 *slowing or anything else. However, they are most effective in normal critters.
*/

class CrossbowTower : Tower {

    public:
    CrossbowTower(double x, double y) : Tower(x, y, 175, 15, 12, 6, 75 ,1, 122.5) {};
    void upgrade() override;
    double sell() override;
};



#endif //CROSSBOWTOWER_H
