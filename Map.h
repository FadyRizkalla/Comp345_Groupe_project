#ifndef MAP_H
#define MAP_H

#include <vector>
#include <iostream>

enum class CellType
{
    SCENERY,
    PATH,
    ENTRY,
    EXIT
};

class Map
{
private:
    int width, height;
    std::vector<std::vector<CellType>> grid;
    std::pair<int, int> entryPoint{-1, -1};
    std::pair<int, int> exitPoint{-1, -1};

    bool isWithinBounds(int x, int y) const;
    bool isPathConnected() const; 

public:
    Map(int width, int height);
    void setCell(int x, int y, CellType type);
    bool validateMap() const;
    void displayMap() const;
};

#endif 
