#include "map.h"
#include <iostream>

int main()
{
    int width, height;

    std::cout << "Enter the dimensions of the map (width height): ";
    std::cin >> width >> height;

    Map gameMap(width, height);

    gameMap.userCustomizeMap();

    std::cout << "\nCustomized Map:\n";
    
    gameMap.displayMap();
    if (gameMap.validateMap())
    {
        std::cout << "The map is valid!\n";
    }
    else
    {
        std::cout << "The map is not valid!\n";
    }

    return 0;
}
