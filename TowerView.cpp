//
// Created by Elisa on 2025-03-02.
//

#include "TowerView.h"

TowerView::TowerView(Tower* tower): TowerObserver(tower) {}

void TowerView::update() {

  std::cout << "Tower updated! New stats:\n";
  std::cout << "Power: " << tower->getPower() << ", Range: " << tower->getRange() << ", Rate of Fire: " << tower->getRateOfFire() << std::endl;
}


