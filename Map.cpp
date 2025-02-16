#include "map.h"
#include <queue>
#include <limits>

Map::Map(int width, int height) : width(width), height(height)
{
    grid.resize(height, std::vector<CellType>(width, CellType::SCENERY));
}

bool Map::isWithinBounds(int x, int y) const
{
    return x >= 0 && x < height && y >= 0 && y < width;
}

void Map::setCell(int x, int y, CellType type)
{
    if (!isWithinBounds(x, y))
    {
        std::cerr << "Invalid coordinates!\n";
        return;
    }

    if (type == CellType::ENTRY)
    {
        if (entryPoint.first != -1)
        {
            std::cerr << "Only one entry point is allowed!\n";
            return;
        }
        entryPoint = {x, y};
    }
    else if (type == CellType::EXIT)
    {
        if (exitPoint.first != -1)
        {
            std::cerr << "Only one exit point is allowed!\n";
            return;
        }
        exitPoint = {x, y};
    }

    grid[x][y] = type;
}

bool Map::isPathConnected() const
{
    if (entryPoint.first == -1 || exitPoint.first == -1)
    {
        return false;
    }

    std::vector<std::vector<bool>> visited(height, std::vector<bool>(width, false));
    std::queue<std::pair<int, int>> q;
    q.push(entryPoint);
    visited[entryPoint.first][entryPoint.second] = true;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        if (x == exitPoint.first && y == exitPoint.second)
        {
            return true;
        }

        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i], ny = y + dy[i];

            if (isWithinBounds(nx, ny) && !visited[nx][ny] &&
                (grid[nx][ny] == CellType::PATH || grid[nx][ny] == CellType::EXIT))
            {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    return false;
}

bool Map::validateMap() const
{
    if (entryPoint.first == -1 || exitPoint.first == -1)
    {
        std::cerr << "Map validation failed: Entry and Exit points are required.\n";
        return false;
    }

    if (!isPathConnected())
    {
        std::cerr << "Map validation failed: Path from Entry to Exit is not connected.\n";
        return false;
    }

    std::cout << "Map is valid!\n";
    return true;
}

void Map::displayMap() const
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            switch (grid[i][j])
            {
            case CellType::SCENERY:
                std::cout << "S ";
                break;
            case CellType::PATH:
                std::cout << "P ";
                break;
            case CellType::ENTRY:
                std::cout << "E ";
                break;
            case CellType::EXIT:
                std::cout << "X ";
                break;
            }
        }
        std::cout << '\n';
    }
}

void Map::userCustomizeMap()
{
    std::cout << "Enter coordinates (row col) and type (0: SCENERY, 1: PATH, 2: ENTRY, 3: EXIT). Enter -1 to stop.\n";
    int x, y, type;
    while (true)
    {
        std::cout << "Enter: ";
        std::cin >> x;
        if (x == -1)
            break;
        std::cin >> y >> type;
        if (type < 0 || type > 3)
        {
            std::cout << "Invalid type. Try again.\n";
            continue;
        }
        setCell(x, y, static_cast<CellType>(type));
    }
}
