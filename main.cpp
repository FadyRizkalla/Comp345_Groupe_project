#include "map.h"
#include "Tower.h"
#include <iostream>
using namespace std;

int main()
{
    double playerFunds = 250;
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

    cout << "Place your first tower on the map!\n" << endl;


    return 0;
}
