#include "map_observer.h"

MapObserver::MapObserver(Map* map) : subject(map) {
    subject->addObserver(this);
}

MapObserver::~MapObserver() {
    subject->removeObserver(this);
}
