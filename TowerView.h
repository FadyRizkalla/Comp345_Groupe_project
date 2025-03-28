#include "TowerObserver.h"
#include "Tower.h"
#include <iostream>
#include <fstream>

class TowerView : public TowerObserver {
public:
    TowerView(Tower* tower) : TowerObserver(tower) {}

    void update() override {
        std::ofstream("Logs.txt", std::ios::app) << "[Tower Observer] Update: Tower at ("
                  << tower->getX() << ", " << tower->getY() << ")\n";
        std::ofstream("Logs.txt", std::ios::app) << "   -> Level: " << tower->getLevel()
                  << " | Power: " << tower->getPower()
                  << " | Range: " << tower->getRange()
                  << " | Rate of Fire: " << tower->getRateOfFire() << "\n";
    }
};
