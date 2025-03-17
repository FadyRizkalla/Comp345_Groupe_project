#include "TowerView.h"
#include "Tower.h"

TowerView::TowerView(Tower* tower) : TowerObserver(tower) {}

void TowerView::update() {
  std::cout << "Tower View Updated: \n";
  std::cout << "Level: " << tower->getLevel() << " | "
            << "Power: " << tower->getPower() << " | "
            << "Range: " << tower->getRange() << " | "
            << "Rate of Fire: " << tower->getRateOfFire() << "\n";
}
