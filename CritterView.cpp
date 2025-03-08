#include "CritterView.h"
#include "Critter.h"

CritterView::CritterView(Critter* critter) : CritterObserver(critter) {}

CritterView::~CritterView() {}

void CritterView::update() {
    std::cout << "[Critter Observer] Update: Critter at (" << critter->x << ", " << critter->y
              << "), HP: " << critter->getHitPoints() << std::endl;
}
