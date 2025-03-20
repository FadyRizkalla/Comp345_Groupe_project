#include "Cell.h"

// Default constructor (already implemented in the header file)
Cell::Cell() : status(CellState::Empty), critter(nullptr), tower(nullptr) {}

// Getter for status
CellState Cell::getStatus() const {
    return status;  // Return the status directly
}

// Setter for status
void Cell::setStatus(CellState newStatus) {
    status = newStatus;  // Corrected the parameter
}

// Getter for critter
Critter* Cell::getCritter() const {
    return critter;
}

// Setter for critter
void Cell::setCritter(Critter* newCritter) {
    critter = newCritter;
    if (newCritter) {
        status = CellState::CRITTER;  // Update status when adding a critter
    } else if (!tower) {
        status =CellState::Empty;  // If no tower is present, set status to EMPTY
    }
}

// Getter for tower
Tower* Cell::getTower() const {
    return tower;
}

// Setter for tower
void Cell::setTower(Tower* newTower) {
    tower = newTower;
    if (newTower) {
        status = CellState::TOWER;  // Update status when adding a tower
    } else if (!critter) {
        status = CellState::Empty;  // If no critter is present, set status to EMPTY
    }
}
