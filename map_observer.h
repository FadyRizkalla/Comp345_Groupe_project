#ifndef MAP_OBSERVER_H
#define MAP_OBSERVER_H

#include "map.h"

class MapObserver {
protected:
    Map* subject;

public:
    explicit MapObserver(Map* map);
    virtual ~MapObserver();
    virtual void update() = 0;
};

#endif
