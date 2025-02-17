//
// Created by Elisa on 2025-02-15.
//

#ifndef ICEWALL_H
#define ICEWALL_H
#include "Tower.h"
#include "Critter.h"

/*
   Ice Tower doesn't really have a rating. It has the special feature of making
critters slower. Therefore, allowing more time for other towers to shoot.
Ice tower's only purpose is making critters slower. It has similar attributes
in terms of costs as Sniper Tower.
 */

class IceWall : public Tower{

  public:
    IceWall(double x, double y);
    void upgrade(Player &player) override;
    void attack(Critter* critter) override;
};



#endif //ICEWALL_H
