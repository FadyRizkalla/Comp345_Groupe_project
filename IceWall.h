//
// Created by Elisa on 2025-02-15.
//

#ifndef ICEWALL_H
#define ICEWALL_H
#include "Tower.h"
#include "Critter.h"



class IceWall : public Tower{

  public:
    IceWall(double x, double y);
    void upgrade(Player &player) override;
    void attack(Critter* critter) override;
};



#endif //ICEWALL_H
