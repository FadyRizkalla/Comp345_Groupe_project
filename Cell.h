#ifndef CELL_H
#define CELL_H

#include "Critter.h"
#include "Tower.h"


    enum CellState {
        Empty,
        TOWER,
        CRITTER,  
        SCENERY,
        PATH,
        ENTRY,
        EXIT,
    };



class Cell {
private:
    CellState status;
    Critter* critter;
    Tower* tower;

public:
    // Constructor
    Cell() : status(CellState::Empty), critter(nullptr), tower(nullptr) {}

    // Getter for status
    CellState getStatus() const { return status; }

    // Setter for status
    void setStatus(CellState newStatus) { status = newStatus; }

    // Getter for critter
    Critter* getCritter() const { return critter; }

    // Setter for critter
    void setCritter(Critter* newCritter) { critter = newCritter; }

    // Getter for tower
    Tower* getTower() const { return tower; }

    // Setter for tower
    void setTower(Tower* newTower) { tower = newTower; }
};

#endif // CELL_H
