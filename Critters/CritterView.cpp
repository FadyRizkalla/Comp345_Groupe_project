#include "CritterView.h"
#include "Critter.h"
#include <fstream>

CritterView::CritterView(Critter* critter) : CritterObserver(critter) {}

CritterView::~CritterView() {}

void CritterView::update() {
    std::ofstream("Logs.txt", std::ios::app) << "[Critter Observer] Update: Critter at (" << critter->x << ", " << critter->y
              << "), HP: " << critter->getHitPoints() << std::endl;
}
