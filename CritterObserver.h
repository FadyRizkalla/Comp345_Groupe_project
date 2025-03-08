#ifndef CRITTEROBSERVER_H
#define CRITTEROBSERVER_H

// Forward declaration to avoid circular dependency
class Critter;

class CritterObserver {
protected:
    Critter* critter;

public:
    CritterObserver(Critter* critter);
    virtual ~CritterObserver();
    virtual void update() = 0;
};

#endif // CRITTEROBSERVER_H
