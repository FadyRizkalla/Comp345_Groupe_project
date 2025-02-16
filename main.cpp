#include "map.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    double playerFunds = 250;
    Map gameMap(5, 5);

    gameMap.setCell(0, 0, CellType::ENTRY);
    gameMap.setCell(4, 4, CellType::EXIT);
    gameMap.setCell(0, 1, CellType::PATH);
    gameMap.setCell(1, 1, CellType::PATH);
    gameMap.setCell(1, 2, CellType::PATH);
    gameMap.setCell(2, 2, CellType::PATH);
    gameMap.setCell(3, 2, CellType::PATH);
    gameMap.setCell(4, 2, CellType::PATH);
    gameMap.setCell(4, 2, CellType::PATH);
    gameMap.setCell(4, 3, CellType::PATH);

    cout << "\nGenerated Map:\n";
    gameMap.displayMap();

    if (gameMap.validateMap())
    {
        cout << "The map is valid!\n";
    }
    else
    {
        cout << "The map is not valid!\n";
    }

    cout << "Place your first tower on the map!\n"
         << endl;

    return 0;
}
