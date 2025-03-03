//
// Created by Elisa on 2025-03-02.
//

#ifndef TOWERVIEW_H
#define TOWERVIEW_H

#include "TowerObserver.h"

class TowerView : public TowerObserver {

  public:
    TowerView(Tower* tower);
    void update() override;
};



#endif //TOWERVIEW_H
