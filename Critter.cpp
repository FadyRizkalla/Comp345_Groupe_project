//
// Created by fadi on 2025-02-11.

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
