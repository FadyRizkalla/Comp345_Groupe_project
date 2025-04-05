#ifndef CRITTERVIEW_H
#define CRITTERVIEW_H

#include "CritterObserver.h"
#include <iostream>

class CritterView : public CritterObserver {
public:
    explicit CritterView(Critter* critter);
    ~CritterView();

    void update() override;
};

#endif
