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
    int x;
    int y;

public:
    // Constructor
    Critter(int hp, int str, int spd, int lvl);

    // Damage function
    void takeDamage(int damage);

    // Movement function
    void move();

    int getHitPoints() const;
    int getReward() const;
    int getStrength() const;
    int getSpeed() const;
    int getLevel() const;

    // Setters
    void setHitPoints(int hp);
    void setReward(int rw);
    void setStrength(int str);
    void setSpeed(int spd);
    void setLevel(int lvl);

    // Check if the critter is dead
    bool isDead() const;
    std::pair<int, int> Critter::getPosition() const;
};

#endif 
