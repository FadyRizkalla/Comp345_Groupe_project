#include "sfml_map_observer.h"
#include <fstream>

SFMLMapObserver::SFMLMapObserver(Map* map, sf::RenderWindow& win, std::vector<sf::RectangleShape>& cells, int width, int height)
    : MapObserver(map), window(win), gridCells(cells), gridWidth(width), gridHeight(height) {}

void SFMLMapObserver::update() {
    std::ofstream("Logs.txt", std::ios::app) << "Map updated! Redrawing grid...\n";

    for (int i = 0; i < gridHeight; i++) {
        for (int j = 0; j < gridWidth; j++) {
            int index = i * gridWidth + j;
            switch (subject->getCellType(i, j)) {
                case CellType::SCENERY:
                    gridCells[index].setFillColor(sf::Color::Transparent);
                break;
                case CellType::PATH:
                    gridCells[index].setFillColor(sf::Color::White);
                break;
                case CellType::ENTRY:
                    gridCells[index].setFillColor(sf::Color::Green);
                break;
                case CellType::EXIT:
                    gridCells[index].setFillColor(sf::Color::Red);
                break;
                case CellType::TOWER:
                    gridCells[index].setFillColor(sf::Color::Blue);
                break;
            }
        }
    }
}
