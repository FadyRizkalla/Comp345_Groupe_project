#ifndef MAP_OBSERVER_H
#define MAP_OBSERVER_H

#include "map.h"

// Observer class
class MapObserver {
protected:
    Map* subject; // Reference to the observed map

public:
    explicit MapObserver(Map* map);
    virtual ~MapObserver();
    virtual void update() = 0; // Pure virtual function
};

#endif
