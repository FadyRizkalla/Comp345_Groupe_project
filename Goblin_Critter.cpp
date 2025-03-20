#include "Goblin_Critter.h"

Goblin_Critter::Goblin_Critter() : Critter(30, 5, 2, 1) {}

double Goblin_Critter::getDistanceToExit() const {
 return Critter::getDistanceToExit(); //base class method implementation

}
