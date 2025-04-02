#ifndef TOWER_H
#define TOWER_H

#include "Player.h"
#include <vector>
#include "Map.h"
#include "Critter.h"
#include "TowerObserver.h"
#include "TargetingStrategy.h"



enum class TowerType {
    ARCHER,
    CROSSBOW,
    SNIPER,
    ICE_WALL,
    TURRET
};


class Critter;

class TowerObserver;

class Tower
{
protected:
  int x, y;
  double cost;
  int range;
  int power;
  int rateOfFire;
  int level;
  double upgradeCost;
  double refundValue;
  std::vector<TowerObserver*> observers;
  TargetingStrategy* targetingStrategy;
  TowerType type;

public:
  Tower();
  Tower(double x, double y, double cost, int range, int power, int rateOfFire, double upgradeCost, int level, double refundValue);
  Tower(const Tower &tower);
  Tower(double x, double y, double cost, int range, int power, int rateOfFire, double upgradeCost, int level, double refundValue, TowerType type)
        : x(x), y(y), cost(cost), range(range), power(power), rateOfFire(rateOfFire), upgradeCost(upgradeCost), level(level), refundValue(refundValue), type(type) {}

  virtual ~Tower();

  virtual void upgrade(Player &player);
  virtual double sell(Player &player);
  virtual void attack(Critter *critter);

  bool isTargetInRange(const Critter *Critter) const;
  void setTargetingStrategy(TargetingStrategy* strategy);
  void acquireTarget(std::vector<Critter *> &targets);
  TargetingStrategy* getTargetingStrategy() const;  //get the target strategy

  bool isValidPlacement(int coX, int coY, const Map &map, const std::vector<Tower *> &towers) const;
  void placeTower(Map &map);

  int getRange() const;
  int getLevel() const;
  double getCost() const;
  int getPower() const;
  int getRateOfFire() const;
  double getUpgradeCost() const;
  int getX() const { return x; }
  int getY() const { return y; }
  TowerType getType() const {
        return type;
    }

  void setRange(int x);
  void setLevel(int x);
  void setCost(double x);
  void setPower(int x);
  void setRateOfFire(int x);
  void setUpgradeCost(double x);


  void addObserver(TowerObserver *observer);
  void removeObserver(TowerObserver *observer);
  void notifyObservers();

  void clearObservers() {
    observers.clear();
  }


};

#endif
