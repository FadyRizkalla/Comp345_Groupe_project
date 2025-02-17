cmake_minimum_required(VERSION 3.30)
project(Comp345_Groupe_project)

# Use C++17 or later
set(CMAKE_CXX_STANDARD 17)

# Include directories (if needed)
include_directories(.)

# Define the executable and add all required source files
add_executable(Comp345_Groupe_project
        main.cpp
        Map.cpp
        Player.cpp
        Tower.cpp
        ArcherTower.cpp
        CrossbowTower.cpp
        SniperTower.cpp
        IceWall.cpp
        TurretTower.cpp
        Critter.cpp
)