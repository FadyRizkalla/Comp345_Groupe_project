#ifndef CRITTER_H
#define CRITTER_H

#include <iostream>
#include <vector>
#include "CritterObserver.h"
#include "map.h"

class CritterObserver;

class Critter {
private:
    int reward;
    int hit_point;
    int strength;
    int speed;
    int level;
    std::vector<CritterObserver *> observers;
    std::vector<std::pair<int, int>> path;
    int pathIndex = 0;
    std::pair<int, int> exitCell;

public:
    int x;
    int y;
    int previousX, previousY;

    // Constructor
    Critter(int hp, int str, int spd, int lvl);

    // Damage function
    void takeDamage(int damage);

    void move(Map& gameMap);

    // Set Path
    void setPath(const std::vector<std::pair<int, int>>& p);

    // Getters
    int getHitPoints() const;
    int getReward() const;
    int getStrength() const;
    int getSpeed() const;
    int getLevel() const;

    // Setters
    void setHitPoint(int hp);
    void setReward(int rw);
    void setStrength(int str);
    void setSpeed(int spd);
    void setLevel(int lvl);

    // Check if the critter is dead
    bool isDead() const;

    void setPosition(int newX, int newY) {
        previousX = x = newX;
        previousY = y = newY;
    }
    std::pair<int, int> getPosition() const { return {x, y}; }

    void setExit(int exitX, int exitY) { exitCell = {exitX, exitY}; }

    bool hasReachedExit() const;


    // Observer methods
    void addObserver(CritterObserver *observer);
    void removeObserver(CritterObserver *observer);
    void notifyObservers();
};

#endif // CRITTER_H
