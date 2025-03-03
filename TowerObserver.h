//
// Created by Elisa on 2025-03-02.
//

#ifndef TOWEROBSERVER_H
#define TOWEROBSERVER_H

#include "Tower.h"

class TowerObserver {

    protected:
    Tower *tower;

    public:
    TowerObserver(Tower *tower);
    virtual ~TowerObserver();
    virtual void update() = 0;

};



#endif //TOWEROBSERVER_H
