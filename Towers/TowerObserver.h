#ifndef TOWEROBSERVER_H
#define TOWEROBSERVER_H

class Tower;

class TowerObserver {
protected:
    Tower* tower;

public:
    TowerObserver(Tower* tower);
    virtual ~TowerObserver();

    virtual void update() = 0;
};

#endif // TOWEROBSERVER_H
