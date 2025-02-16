cmake_minimum_required(VERSION 3.30)
project(Comp345_Groupe_project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Comp345_Groupe_project
    ArcherTower.cpp
    ArcherTower.h
    CrossbowTower.cpp
    CrossbowTower.h
    SniperTower.cpp
    SniperTower.h
    Tower.cpp
    Tower.h
    TurretTower.cpp
    TurretTower.h)
