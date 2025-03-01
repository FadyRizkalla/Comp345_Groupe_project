cmake_minimum_required(VERSION 3.16)
project(Comp345_Groupe_project)

# Set C++17 Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(.)

# Fetch SFML via Git
include(FetchContent)
FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.0
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM
)
FetchContent_MakeAvailable(SFML)

# Add executable
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
        TurretTower.h
)

# Set compile features
target_compile_features(Comp345_Groupe_project PRIVATE cxx_std_17)

# Link SFML libraries
target_link_libraries(Comp345_Groupe_project PRIVATE SFML::Graphics SFML::Window SFML::System)
