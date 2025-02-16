//
// Created by Elisa on 2025-02-15.
//

#ifndef ARCHERTOWER_H
#define ARCHERTOWER_H
#include "Tower.h"


// This is the lowest tier of the towers. It is the basic level that the user is able to use.

/* Archer Tower: Basic Level tower
 * Characteristics: Single damage to one enemy, Basic, Cost-effective
 * No special features against critters
*/

class ArcherTower : public Tower {


  public:
    ArcherTower(double x, double y) : Tower(x, y, 100, 5, 5, 2, 50 ,1, 70) {};
    void upgrade() override;
    double sell() override;


};



#endif //ARCHERTOWER_H
