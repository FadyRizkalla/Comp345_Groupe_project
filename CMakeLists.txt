cmake_minimum_required(VERSION 3.30)
project(Comp345_Groupe_project LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Ensure C++17 for SFML 3.0
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Fetch SFML via Git
include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.0
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
FetchContent_MakeAvailable(SFML)

# Define source files
set(SOURCES
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
        Ogre_Critter.cpp
        Goblin_Critter.cpp
)

set(HEADERS
        Map.h
        Player.h
        Tower.h
        ArcherTower.h
        CrossbowTower.h
        SniperTower.h
        IceWall.h
        TurretTower.h
        Critter.h
        Ogre_Critter.h
        Goblin_Critter.h
)

# Create a single executable
add_executable(Comp345_Groupe_project ${SOURCES} ${HEADERS})

# Link SFML to the executable
target_link_libraries(Comp345_Groupe_project PRIVATE SFML::Graphics)

# Include current directory for headers
target_include_directories(Comp345_Groupe_project PRIVATE .)
