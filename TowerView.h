#include "TowerObserver.h"
#include "Tower.h"
#include <iostream>

class TowerView : public TowerObserver {
public:
    TowerView(Tower* tower) : TowerObserver(tower) {}

    void update() override {
        std::cout << "[Tower Observer] Update: Tower at ("
                  << tower->getX() << ", " << tower->getY() << ")\n";
        std::cout << "   -> Level: " << tower->getLevel()
                  << " | Power: " << tower->getPower()
                  << " | Range: " << tower->getRange()
                  << " | Rate of Fire: " << tower->getRateOfFire() << "\n";
    }
};
