//
// Created by Elisa on 2025-03-02.
//

#include "TowerObserver.h"


TowerObserver::TowerObserver(Tower* tower): tower(tower) {

      tower -> addObserver(this);
}

TowerObserver::~TowerObserver() {
  tower -> removeObserver(this);
}
