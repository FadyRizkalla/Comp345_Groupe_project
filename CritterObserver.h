//
// Created by Elisa on 2025-03-02.
//

#ifndef CRITTEROBSERVER_H
#define CRITTEROBSERVER_H

#include "Critter.h"

class CritterObserver {

    protected:
    Critter* critter;

    public:
    CritterObserver(Critter* critter);
    virtual ~CritterObserver();
    virtual void update() = 0;
};



#endif //CRITTEROBSERVER_H
