cmake_minimum_required(VERSION 3.30)
project(Comp345_Groupe_project LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.0
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
FetchContent_MakeAvailable(SFML)

set(SOURCES
main.cpp
Cell.cpp
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
map_observer.cpp
sfml_map_observer.cpp
TowerObserver.cpp
CritterObserver.cpp
CritterView.cpp
       
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
map_observer.h
sfml_map_observer.h
TowerObserver.h
CritterObserver.h
CritterView.h
main.h
)

add_executable(Comp345_Groupe_project ${SOURCES} ${HEADERS})

target_link_libraries(Comp345_Groupe_project PRIVATE SFML::Graphics)

target_include_directories(Comp345_Groupe_project PRIVATE .)
