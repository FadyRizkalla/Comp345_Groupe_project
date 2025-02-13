#ifndef CRITTER_H
#define CRITTER_H

#include <iostream>
using namespace std;

class Critter {
private:
    int reward;
    int hit_point;
    int strength;
    int speed;
    int level;

public:
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

    // Check if the critter is dead
    bool isDead() const;
};

#endif // CRITTER_H
