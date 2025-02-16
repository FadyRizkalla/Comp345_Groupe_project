#include "map.h"
#include <iostream>

int main()
{
    Map gameMap(5, 5);

    gameMap.setCell(0, 0, CellType::ENTRY);
    gameMap.setCell(4, 4, CellType::EXIT);

    gameMap.setCell(0, 1, CellType::PATH);
    gameMap.setCell(1, 1, CellType::PATH);
    gameMap.setCell(2, 1, CellType::PATH);
    gameMap.setCell(3, 1, CellType::PATH);
    gameMap.setCell(4, 1, CellType::PATH);
    gameMap.setCell(4, 2, CellType::PATH);
    gameMap.setCell(4, 3, CellType::PATH);
    gameMap.setCell(4, 4, CellType::PATH);

    std::cout << "Generated Map:" << std::endl;
    gameMap.displayMap();

    if (gameMap.validateMap())
    {
        std::cout << "The map is valid!" << std::endl;
    }
    else
    {
        std::cout << "The map is not valid!" << std::endl;
    }

    return 0;
}
