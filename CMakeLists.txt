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
        ./Map/Map.cpp
        ./Player/Player.cpp
        ./Towers/Tower.cpp
        ./Towers/ArcherTower.cpp
        ./Towers/CrossbowTower.cpp
        ./Towers/SniperTower.cpp
        ./Towers/IceWall.cpp
        ./Towers/TurretTower.cpp
        ./Critters/Critter.cpp
        ./Critters/Ogre_Critter.cpp
        ./Critters/Goblin_Critter.cpp
        ./Map/map_observer.cpp
        ./Map/sfml_map_observer.cpp
        ./Towers/TowerObserver.cpp
        ./Critters/CritterObserver.cpp
        ./Critters/CritterView.cpp
        ./Towers/TargetingStrategy.cpp
        ./Towers/TowerDecorator.cpp
        ./Critters/Goblin_Critter.cpp
        ./Critters/Ogre_Critter.cpp
        ./Critters/CritterFactory.cpp
)

set(HEADERS
        ./Map/Map.h
        ./Player/Player.h
        ./Towers/Tower.h
        ./Towers/ArcherTower.h
        ./Towers/CrossbowTower.h
        ./Towers/SniperTower.h
        ./Towers/IceWall.h
        ./Towers/TurretTower.h
        ./Critters/Critter.h
        ./Critters/Ogre_Critter.h
        ./Critters/Goblin_Critter.h
        ./Map/map_observer.h
        ./Map/sfml_map_observer.h
        ./Towers/TowerObserver.h
        ./Critters/CritterObserver.h
        ./Critters/CritterView.h
        ./Towers/TargetingStrategy.h
        ./Towers/TowerDecorator.h
        ./Critters/Goblin_Critter.h
        ./Critters/Ogre_Critter.h
        ./Critters/CritterFactory.h
)

add_executable(Comp345_Groupe_project ${SOURCES} ${HEADERS})

target_link_libraries(Comp345_Groupe_project PRIVATE SFML::Graphics)

target_include_directories(Comp345_Groupe_project PRIVATE .)
