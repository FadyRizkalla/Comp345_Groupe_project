#ifndef SFML_MAP_OBSERVER_H
#define SFML_MAP_OBSERVER_H

#include "map_observer.h"
#include <SFML/Graphics.hpp>
#include <vector>

class SFMLMapObserver : public MapObserver {
private:
    sf::RenderWindow& window;
    std::vector<sf::RectangleShape>& gridCells;
    int gridWidth, gridHeight;

public:
    SFMLMapObserver(Map* map, sf::RenderWindow& win, std::vector<sf::RectangleShape>& cells, int width, int height);
    void update() override; // Handles map updates
};

#endif
