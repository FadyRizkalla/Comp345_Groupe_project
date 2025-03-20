#ifndef MAP_H
#define MAP_H

#include <vector>
#include <iostream>
#include <set>
#include"Cell.h"
class MapObserver;

class Map {
private:
    int width, height;
    std::vector<std::vector<Cell>> grid;
    std::pair<int, int> entryPoint{-1, -1};
    std::pair<int, int> exitPoint{-1, -1};

    std::set<MapObserver*> observers;

    bool isPathConnected() const;
    void notifyObservers();

public:
    Map(int width, int height);

    void setCell(int x, int y,Cell& cell);
    bool validateMap() const;
    void displayMap() const;
    bool isWithinBounds(int x, int y) const;
    CellState getCellType(int x, int y) const;
    std::vector<std::pair<int, int>> getPath() const;
    int getHeight() const { return height; }
    int getWidth() const { return width; }

    void addObserver(MapObserver* observer);
    void removeObserver(MapObserver* observer);
};

#endif
