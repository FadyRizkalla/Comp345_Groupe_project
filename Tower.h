#ifndef TOWER_H
#define TOWER_H

#include "Player.h"
#include <vector>
#include "Map.h"
#include "Critter.h"



class Critter;

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

public:
  Tower();
  Tower(double x, double y, double cost, int range, int power, int rateOfFire, double upgradeCost, int level, double refundValue);
  Tower(const Tower &tower);

  virtual ~Tower();

  virtual void upgrade(Player &player);
  virtual double sell(Player &player);
  virtual void attack(Critter *critter);

  bool isTargetInRange(const Critter *Critter) const;
  void acquireTarget(std::vector<Critter *> &targets);

  bool isValidPlacement(int coX, int coY, const Map &map, const std::vector<Tower *> &towers) const;
  void placeTower(Map &map); // New method to update the map

  int getRange() const;
  int getLevel() const;
  double getCost() const;
  int getPower() const;
  int getRateOfFire() const;
  double getUpgradeCost() const;

  void setRange(int x);
  void setLevel(int x);
  void setCost(double x);
  void setPower(int x);
  void setRateOfFire(int x);
  void setUpgradeCost(double x);
};

#endif
