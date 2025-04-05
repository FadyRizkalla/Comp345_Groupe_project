#include "TowerObserver.h"
#include "Tower.h"

TowerObserver::TowerObserver(Tower* tower) : tower(tower) {
    tower->addObserver(this);
}

TowerObserver::~TowerObserver() {
    tower->removeObserver(this);
}
