#include "map.h"
#include "map_observer.h"
#include <queue>
#include <map>
#include <limits>
#include <algorithm>

Map::Map(int width, int height) : width(width), height(height)
{
    grid.resize(height, std::vector<CellType>(width, CellType::SCENERY));
}

void Map::notifyObservers() {
    for (auto* observer : observers) {
        observer->update();
    }
}

bool Map::isWithinBounds(int x, int y) const
{
    return x >= 0 && x < height && y >= 0 && y < width;
}

CellType Map::getCellType(int x, int y) const
{
    if (!isWithinBounds(x, y))
    {
        std::cerr << "Error: Coordinates out of bounds. Returning SCENERY as default.\n";
        return CellType::SCENERY;
    }
    return grid[x][y];
}

void Map::setCell(int x, int y, CellType type) {
    if (!isWithinBounds(x, y)) return;

    if (type == CellType::ENTRY && entryPoint.first == -1) {
        entryPoint = {x, y};
    } else if (type == CellType::EXIT && exitPoint.first == -1) {
        exitPoint = {x, y};
    }

    grid[x][y] = type;
    notifyObservers(); // ✅ Notify observers of the change
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
        return false;
    }

    if (!isPathConnected())
    {
        return false;
    }

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
            case CellType::TOWER:
                std::cout << "T ";
                break;
            }
        }
        std::cout << '\n';
    }
}


void Map::addObserver(MapObserver* observer) {
    observers.insert(observer);
}

void Map::removeObserver(MapObserver* observer) {
    observers.erase(observer);
}

std::vector<std::pair<int, int>> Map::getPath() const {
    std::vector<std::pair<int, int>> path;

    if (entryPoint.first == -1 || entryPoint.second == -1 || exitPoint.first == -1 || exitPoint.second == -1) {
        std::cout << "Error: Entry or Exit point not set!" << std::endl;
        return path; // Return empty path
    }

    std::queue<std::pair<int, int>> q;
    std::map<std::pair<int, int>, std::pair<int, int>> parent; // Track previous cell
    std::set<std::pair<int, int>> visited; // Track visited nodes

    q.push(entryPoint);
    parent[entryPoint] = {-1, -1}; // Mark start point
    visited.insert(entryPoint);

    int dx[] = {1, -1, 0, 0}; // Directions: Right, Left, Down, Up
    int dy[] = {0, 0, 1, -1};

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        // ✅ If we reached the exit, stop and reconstruct the path
        if (x == exitPoint.first && y == exitPoint.second) {
            std::pair<int, int> current = {x, y};
            while (current.first != -1) {
                path.push_back(current);
                current = parent[current];
            }
            std::reverse(path.begin(), path.end()); // Reverse to get correct order
            return path;
        }

        // ✅ Explore all 4 directions
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // ✅ Ensure the next cell is valid, is a PATH/EXIT, and is not visited
            if (isWithinBounds(nx, ny) && (getCellType(nx, ny) == CellType::PATH || getCellType(nx, ny) == CellType::EXIT)
                && visited.find({nx, ny}) == visited.end()) {
                q.push({nx, ny});
                parent[{nx, ny}] = {x, y}; // Store previous node
                visited.insert({nx, ny});
                }
        }
    }

    std::cout << "Error: No valid path found from entry to exit!" << std::endl;
    return path; // Return empty if no path found
}


