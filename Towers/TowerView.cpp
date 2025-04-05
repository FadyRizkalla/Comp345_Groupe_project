#include "TowerView.h"
#include "Tower.h"
#include <fstream>

TowerView::TowerView(Tower* tower) : TowerObserver(tower) {}

void TowerView::update() {
  std::ofstream("Logs.txt", std::ios::app) << "Tower View Updated: \n";
  std::ofstream("Logs.txt", std::ios::app) << "Level: " << tower->getLevel() << " | "
            << "Power: " << tower->getPower() << " | "
            << "Range: " << tower->getRange() << " | "
            << "Rate of Fire: " << tower->getRateOfFire() << "\n";
}
