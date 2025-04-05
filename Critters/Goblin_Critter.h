#ifndef GOBLIN_H
#define GOBLIN_H

#include "Critter.h"

class Goblin_Critter : public Critter
{
public:
  Goblin_Critter();
  double getDistanceToExit() const override;  //method to be overriden
};

#endif // GOBLIN_H