//
/* Created by fadi on 2025-02-11.
Todo
Implement a group of C++ classes that allows the creation of a group of critters following the
tower defense game rules. Individual critters should have the following characteristics: reward,
hit point, strength, speed, level, etc. The critter group generator is a component of the game that
is called at the beginning of each wave to create a group of critters whose characteristics are
adapted to the level of difficulty of the next wave (assuming that every successive wave is of
increasing difficulty). The critter group is a list of critters that will appear sequentially one after
the other on the entry point of the map when the game is played. When it is its turn to act, a
critter should determine where it will move, assuming that it knows where the exit point is of the
map, then move at a certain speed. A critter may be attacked by towers, which will reduce its hit
points, eventually dying if it reaches zero hit points. For every critter killed, the player should get
a coin reward proportional to the level of the critter. Once a critter reaches the exit point, it steals
coins from the player at a rate determined by the critter’s strength.

*/

#include "Critter.h"

// Constructor
Critter::Critter(int hp, int str, int spd, int lvl)
    : hit_point(hp), strength(str), speed(spd), level(lvl), x(0), y(0), reward(10) {}

// Function to take damage
void Critter::takeDamage(int damage) {
    hit_point -= damage;
    if (hit_point < 0) hit_point = 0; // Ensure HP doesn't go below zero
}

// Movement function (Example: Moves randomly)
void Critter::move() {

}

// Getters
int Critter::getHitPoints() const { return hit_point; }
int Critter::getReward() const { return reward; }
int Critter::getStrength() const { return strength; }
int Critter::getSpeed() const { return speed; }
int Critter::getLevel() const { return level; }
std::pair<int, int> Critter::getPosition() const { return std::make_pair(x, y); }
void Critter::setHitPoint(int hp) { hit_point = hp; }
void Critter::setReward(int r) { reward = r; }
void Critter::setStrength(int s) { strength = s; }
void Critter::setSpeed(int s) { speed = s; }
void Critter::setLevel(int l) { level = l; }

// Check if critter is dead
bool Critter::isDead() const { return hit_point <= 0; }
