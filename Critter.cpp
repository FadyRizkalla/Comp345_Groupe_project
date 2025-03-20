//
// Created by fadi on 2025-02-11.

#include "Critter.h"
#include "CritterObserver.h"
#include <algorithm>


Critter::Critter(int hp, int str, int spd, int lvl)
    : hit_point(hp), strength(str), speed(spd), level(lvl), x(0), y(0), previousX(-1), previousY(-1), exitCell(-1, -1) {}


void Critter::takeDamage(int damage) {
    hit_point -= damage;
    if (hit_point < 0) hit_point = 0;
}

void Critter::setPath(const std::vector<std::pair<int, int>>& p) {
    path = p;
    if (!path.empty()) {
        x = path[0].first;
        y = path[0].second;
        pathIndex = 0;
    }
}

bool Critter::hasReachedExit() const {
    return (x == exitCell.first && y == exitCell.second);
}




void Critter::move(Map& gameMap) {
    if (pathIndex < path.size()) {
        std::pair<int, int> nextStep = path[pathIndex];

        if (gameMap.getCellType(nextStep.first, nextStep.second) == CellState::EXIT) {
            x = nextStep.first;
            y = nextStep.second;
            pathIndex++; // Move to exit cell
            std::cout << "Critter entered the exit at (" << x << ", " << y << ")!\n";
            notifyObservers();
            return;
        }

        x = nextStep.first;
        y = nextStep.second;
        pathIndex++;

        notifyObservers();
    }
}






int Critter::getHitPoints() const { return hit_point; }
int Critter::getReward() const { return reward; }
int Critter::getStrength() const { return strength; }
int Critter::getSpeed() const { return speed; }
int Critter::getLevel() const { return level; }
void Critter::setHitPoint(int hp) { hit_point = hp; notifyObservers();}
void Critter::setReward(int r) { reward = r; notifyObservers();}
void Critter::setStrength(int s) { strength = s; notifyObservers();}
void Critter::setSpeed(int s) { speed = s; notifyObservers();}
void Critter::setLevel(int l) { level = l; notifyObservers();}

bool Critter::isDead() const { return hit_point <= 0; }


void Critter::addObserver(CritterObserver *observer) {

    observers.push_back(observer);
}

void Critter::removeObserver(CritterObserver *observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());

}

void Critter::notifyObservers() {

    for (auto observer : observers) {
        observer->update();
    }
}


