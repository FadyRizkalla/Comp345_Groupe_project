#ifndef CRITTER_H
#define CRITTER_H

#include <iostream>
#include <vector>
using namespace std;

class CritterObserver;

class Critter {
private:
    int reward;
    int hit_point;
    int strength;
    int speed;
    int level;
    std::vector<CritterObserver *> observers; //List of Observers for critters


public:

    int x;
    int y;

    // Constructor
    Critter(int hp, int str, int spd, int lvl);

    // Damage function
    void takeDamage(int damage);

    // Movement function
    void move();

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
    std::pair<int, int> getPosition() const;

    //observer methods
    void addObserver(CritterObserver *observer);
    void removeObserver(CritterObserver *observer);
    void notifyObservers();
};

#endif // CRITTER_H
