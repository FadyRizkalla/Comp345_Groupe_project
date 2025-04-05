//
// Created by Elisa on 2025-02-15.
//

#ifndef ARCHERTOWER_H
#define ARCHERTOWER_H
#include "Tower.h"



class ArcherTower : public Tower {


  public:
    ArcherTower(double x, double y);

    void upgrade(Player &player) override;
    double sell(Player &player) override;


};



#endif //ARCHERTOWER_H
