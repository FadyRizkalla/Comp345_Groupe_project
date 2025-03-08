#ifndef MAP_H
#define MAP_H

#include <vector>
#include <iostream>
#include <set>

// Forward declare observer class
class MapObserver;

enum class CellType {
    SCENERY,
    PATH,
    ENTRY,
    EXIT,
    TOWER
};

class Map {
private:
    int width, height;
    std::vector<std::vector<CellType>> grid;
    std::pair<int, int> entryPoint{-1, -1};
    std::pair<int, int> exitPoint{-1, -1};

    std::set<MapObserver*> observers; // ✅ List of observers

    bool isPathConnected() const;
    void notifyObservers(); // ✅ Notify observers

public:
    Map(int width, int height);

    void setCell(int x, int y, CellType type);
    bool validateMap() const;
    void displayMap() const;
    bool isWithinBounds(int x, int y) const;
    CellType getCellType(int x, int y) const;
    std::vector<std::pair<int, int>> getPath() const;
    int getHeight() const { return height; }
    int getWidth() const { return width; }

    // ✅ Observer pattern methods
    void addObserver(MapObserver* observer);
    void removeObserver(MapObserver* observer);
};

#endif
