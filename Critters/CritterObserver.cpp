//
// Created by Elisa on 2025-03-02.
//

#include "CritterObserver.h"
#include "Critter.h"
CritterObserver::CritterObserver(Critter* critter): critter(critter) {

  critter->addObserver(this);
}

CritterObserver::~CritterObserver() {
  critter->removeObserver(this);
}
