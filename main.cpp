#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <cctype>
#include <optional>
#include "map.h"
#include "sfml_map_observer.h"
#include "Player.h"
#include "Tower.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Goblin_Critter.h"
#include "Ogre_Critter.h"
#include "TowerView.h"
#include "CritterView.h"
#include "TargetingStrategy.h"
#include "TowerDecorator.h"
#include <algorithm>


enum class GameState {
    MENU,
    MAP_INPUT,
    DISPLAY_GRID,
    MAP_VIEW
};


int main() {
    std::vector<Tower*> placedTowers;

    sf::RenderWindow window(sf::VideoMode({1200, 800}), "Tower Defense");

    sf::Font font;
    if (!font.openFromFile("arial.ttf")) {
        std::cerr << "Error loading font!\n";
        return -1;
    }

    sf::Text title(font, "Tower Defense", 50);
    title.setFillColor(sf::Color::White);
    title.setPosition({250.f, 100.f});

    sf::RectangleShape startButton({200.f, 50.f});
    startButton.setFillColor(sf::Color::White);
    startButton.setPosition({300.f, 300.f});

    sf::Text startText(font, "Start", 30);
    startText.setFillColor(sf::Color::Black);
    startText.setPosition({370.f, 310.f});

    sf::Text lengthText(font, "Length:", 30);
    lengthText.setFillColor(sf::Color::White);
    lengthText.setPosition({200.f, 200.f});

    sf::Text widthText(font, "Width:", 30);
    widthText.setFillColor(sf::Color::White);
    widthText.setPosition({200.f, 300.f});

    sf::RectangleShape lengthBox({150.f, 40.f});
    lengthBox.setFillColor(sf::Color::White);
    lengthBox.setPosition({350.f, 200.f});

    sf::RectangleShape widthBox({150.f, 40.f});
    widthBox.setFillColor(sf::Color::White);
    widthBox.setPosition({350.f, 300.f});

    sf::Text lengthInput(font, "", 30);
    lengthInput.setFillColor(sf::Color::Black);
    lengthInput.setPosition({365.f, 205.f});

    sf::Text widthInput(font, "", 30);
    widthInput.setFillColor(sf::Color::Black);
    widthInput.setPosition({365.f, 305.f});

    std::string lengthStr, widthStr;

    sf::RectangleShape doneButton({200.f, 50.f});
    doneButton.setFillColor(sf::Color::White);
    doneButton.setPosition({300.f, 400.f});

    sf::Text doneText(font, "Done", 30);
    doneText.setFillColor(sf::Color::Black);
    doneText.setPosition({375.f, 410.f});

    sf::RectangleShape validateButton({200.f, 50.f});
    validateButton.setFillColor(sf::Color::White);
    validateButton.setPosition({300.f, 620.f});

    sf::Text validateText(font, "Validate", 30);
    validateText.setFillColor(sf::Color::Black);
    validateText.setPosition({355.f, 630.f});

    sf::Text validationResult(font, "", 24);
    validationResult.setFillColor(sf::Color::White);
    validationResult.setPosition({250.f, 680.f});


    bool typingLength = true;
    GameState gameState = GameState::MENU;
    Map* gameMap = nullptr;

    int gridWidth = 0, gridHeight = 0;
    std::vector<sf::RectangleShape> gridCells;
    std::vector<std::vector<bool>> cellStates;
    const int maxCellSize = 60;

    sf::Text instructionText(font, "Click to set Path (White), Entry (Green), Exit (Red)", 24);
    instructionText.setFillColor(sf::Color::White);
    instructionText.setPosition({100.f, 20.f});

    sf::Text playerFundsText(font, "Gold: 500", 24);
    playerFundsText.setFillColor(sf::Color::Yellow);
    playerFundsText.setPosition({800.f, 20.f});


    sf::RectangleShape nextButton({200.f, 50.f});
    nextButton.setFillColor(sf::Color::White);
    nextButton.setPosition({300.f, 720.f});

    sf::Text nextText(font, "Next", 30);
    nextText.setFillColor(sf::Color::Black);
    nextText.setPosition({375.f, 730.f});

    sf::Text towerTypesText(font, "Towers:", 24);
    towerTypesText.setFillColor(sf::Color::White);
    towerTypesText.setPosition({800.f, 60.f});

    sf::Text archerTowerText(font, "1. Archer Tower", 20);
    archerTowerText.setFillColor(sf::Color::White);
    archerTowerText.setPosition({800.f, 90.f});

    sf::Text crossbowTowerText(font, "2. Crossbow Tower", 20);
    crossbowTowerText.setFillColor(sf::Color::White);
    crossbowTowerText.setPosition({800.f, 120.f});

    sf::Text sniperTowerText(font, "3. Sniper Tower", 20);
    sniperTowerText.setFillColor(sf::Color::White);
    sniperTowerText.setPosition({800.f, 150.f});

    sf::Text iceWallText(font, "4. Ice Wall", 20);
    iceWallText.setFillColor(sf::Color::White);
    iceWallText.setPosition({800.f, 180.f});

    sf::Text turretTowerText(font, "5. Turret Tower", 20);
    turretTowerText.setFillColor(sf::Color::White);
    turretTowerText.setPosition({800.f, 210.f});

    sf::Text upgradeText(font,"upgrade", 20);
    upgradeText.setFillColor(sf::Color::White);
    upgradeText.setPosition({800.f, 270.f});


    bool isMapValid = false;
    Player player;



    std::pair<int, int> entryPoint = {-1, -1};
    std::pair<int, int> exitPoint = {-1, -1};

    SFMLMapObserver* observer = nullptr;

    int selectedTowerType = 0;

    sf::Text selectedTowerText(font, "Selected: None", 24);
    selectedTowerText.setFillColor(sf::Color::White);
    selectedTowerText.setPosition({800.f, 240.f});

    sf::RectangleShape readyButton({200.f, 50.f});
    readyButton.setFillColor(sf::Color::White);
    readyButton.setPosition({800.f, 300.f});

    sf::Text readyText(font, "Ready", 30);
    readyText.setFillColor(sf::Color::Black);
    readyText.setPosition({870.f, 310.f});

    bool isReady = false;

    std::vector<Critter*> critters;
    std::srand(std::time(nullptr));

    sf::Clock spawnTimer;
    int critterSpawnIndex = 0;
    float spawnDelay = 0.5f;


    while (window.isOpen()) {
        while (const std::optional<sf::Event> event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();

            if (auto keyEvent = event->getIf<sf::Event::KeyPressed>()) {
                if (keyEvent->code == sf::Keyboard::Key::Num1) {
                    selectedTowerType = 1;
                    selectedTowerText.setString("Selected: Archer");
                } else if (keyEvent->code == sf::Keyboard::Key::Num2) {
                    selectedTowerType = 2;
                    selectedTowerText.setString("Selected: Crossbow");
                } else if (keyEvent->code == sf::Keyboard::Key::Num3) {
                    selectedTowerType = 3;
                    selectedTowerText.setString("Selected: Sniper");
                } else if (keyEvent->code == sf::Keyboard::Key::Num4) {
                    selectedTowerType = 4;
                    selectedTowerText.setString("Selected: Ice Wall");
                } else if (keyEvent->code == sf::Keyboard::Key::Num5) {
                    selectedTowerType = 5;
                    selectedTowerText.setString("Selected: Turret");
                }
            }


            if (event->is<sf::Event::MouseButtonPressed>()) {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                auto mouseEvent = event->getIf<sf::Event::MouseButtonPressed>();

                if (gameState == GameState::MENU) {
                    if (startButton.getGlobalBounds().contains(mousePos)) {
                        gameState = GameState::MAP_INPUT;
                    }
                }

                else if (gameState == GameState::MAP_INPUT) {
                    if (doneButton.getGlobalBounds().contains(mousePos) && !lengthStr.empty() && !widthStr.empty()) {
                        int length = std::stoi(lengthStr);
                        int width = std::stoi(widthStr);

                        gameMap = new Map(length, width);
                        gridWidth = width;
                        gridHeight = length;

                        gridCells.clear();
                        cellStates.assign(gridHeight, std::vector<bool>(gridWidth, false));

                        int cellSize = std::min(maxCellSize, std::min(600 / gridHeight, 800 / gridWidth));
                        float startX = (800 - (gridWidth * cellSize)) / 2;
                        float startY = (600 - (gridHeight * cellSize)) / 2 + 30;

                        for (int i = 0; i < gridHeight; i++) {
                            for (int j = 0; j < gridWidth; j++) {
                                sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
                                cell.setFillColor(sf::Color::Transparent);
                                cell.setOutlineThickness(2);
                                cell.setOutlineColor(sf::Color::White);
                                cell.setPosition(sf::Vector2f(startX + j * cellSize, startY + i * cellSize));
                                gridCells.push_back(cell);
                            }
                        }

                        observer = new SFMLMapObserver(gameMap, window, gridCells, gridWidth, gridHeight);

                        gameState = GameState::DISPLAY_GRID;
                    }

                }
                else if (gameState == GameState::DISPLAY_GRID) {
                    if (validateButton.getGlobalBounds().contains(mousePos)) {
                        if (gameMap) {
                            isMapValid = gameMap->validateMap();
                            validationResult.setString(isMapValid ? "Map is valid!" : "Map is NOT valid!");
                            validationResult.setFillColor(isMapValid ? sf::Color::Green : sf::Color::Red);
                        }
                    }

                    if (isMapValid && nextButton.getGlobalBounds().contains(mousePos)) {
                        std::cout << "Next button clicked! Switching to MAP VIEW mode..." << std::endl;

                        player.setPlayerFunds(500);

                        gameState = GameState::MAP_VIEW;
                    }



                    for (int i = 0; i < gridHeight; i++) {
                        for (int j = 0; j < gridWidth; j++) {
                            int index = i * gridWidth + j;
                            if (gridCells[index].getGlobalBounds().contains(mousePos)) {
                                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E)) {
                                    if (entryPoint.first != -1) {
                                        gameMap->setCell(entryPoint.first, entryPoint.second, CellType::SCENERY);
                                    }
                                    gameMap->setCell(i, j, CellType::ENTRY);
                                    entryPoint = {i, j};
                                }

                                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::X)) {
                                    if (exitPoint.first != -1) {
                                        gameMap->setCell(exitPoint.first, exitPoint.second, CellType::SCENERY);
                                    }
                                    gameMap->setCell(i, j, CellType::EXIT);
                                    exitPoint = {i, j};
                                }
                                else {
                                    cellStates[i][j] = !cellStates[i][j];
                                    gameMap->setCell(i, j, cellStates[i][j] ? CellType::PATH : CellType::SCENERY);
                                }
                            }
                        }

                    }
}
                    else if (gameState == GameState::MAP_VIEW) {
                        sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));


                        if (readyButton.getGlobalBounds().contains(mousePos)) {
                            isReady = true;
                            std::cout << "Player is ready! Critters will spawn one by one.\n";

                            std::cout << "Entry Point: (" << entryPoint.first << ", " << entryPoint.second << ")\n";

                            std::vector<std::pair<int, int>> path = gameMap->getPath();
                            std::cout << "Full Path: ";
                            for (const auto& step : path) {
                                std::cout << "(" << step.first << ", " << step.second << ") ";
                            }
                            std::cout << std::endl;

                            if (!path.empty()) {
                                std::cout << "First Path Cell: (" << path.front().first << ", " << path.front().second << ")\n";
                            } else {
                                std::cout << "Error: No valid path found!\n";
                            }

                            if (entryPoint.first != -1 && entryPoint.second != -1) {
                                if (!path.empty() && path.front() == entryPoint) {
                                    std::cout << "Entry matches first path cell. Spawning correctly." << std::endl;
                                } else {
                                    std::cout << "Warning: Entry point (" << entryPoint.first << ", " << entryPoint.second
                                              << ") does NOT match first path step (" << path.front().first << ", " << path.front().second << ")."
                                              << " Adjusting entry position." << std::endl;
                                    if (path.empty() || path.front() != entryPoint) {
                                        std::cout << "Error: Path does not start from the correct entry!\n";
                                    }

                                }

                                for (int i = 0; i < 3; i++) {
                                    Critter* goblin = new Goblin_Critter();
                                    goblin->setPosition(entryPoint.first, entryPoint.second);
                                    goblin->setPath(path);
                                    goblin->setExit(exitPoint.first, exitPoint.second); // Set exit for distance calc
                                    critters.push_back(goblin);
                                    CritterObserver* goblinObserver = new CritterView(goblin);
                                }

                                for (int i = 0; i < 2; i++) {
                                    Critter* ogre = new Ogre_Critter();
                                    ogre->setPosition(entryPoint.first, entryPoint.second);
                                    ogre->setPath(path);
                                    ogre->setExit(exitPoint.first, exitPoint.second); // Set exit for distance calc
                                    critters.push_back(ogre);
                                    CritterObserver* ogreObserver = new CritterView(ogre);
                                }

                                spawnTimer.restart();
                                critterSpawnIndex = 0;

                            } else {
                                std::cout << "Error: No entry point set!\n";
                            }
                        }

                        if (!isReady) {
                        for (int i = 0; i < gridHeight; i++) {
                            for (int j = 0; j < gridWidth; j++) {
                                int index = i * gridWidth + j;
                                if (gridCells[index].getGlobalBounds().contains(mousePos)) {

                                    if (selectedTowerType == 0) {
                                        std::cout << "No tower selected!" << std::endl;
                                        continue;
                                    }

                                    Tower* baseTower = nullptr;
                                    switch (selectedTowerType) {
                                        case 1: // Archer Tower
                                            baseTower = new Tower(j, i, 100, 5, 10, 2, 50, 1, 50);
                                        break;
                                        case 2: // Crossbow Tower
                                            baseTower = new Tower(j, i, 150, 6, 15, 3, 75, 1, 75);
                                        break;
                                        case 3: // Sniper Tower
                                            baseTower = new Tower(j, i, 200, 8, 20, 1, 100, 1, 100);
                                        break;
                                        case 4: // Ice Wall
                                            baseTower = new Tower(j, i, 120, 4, 5, 1, 60, 1, 60);
                                        break;
                                        case 5: // Turret Tower
                                            baseTower = new Tower(j, i, 180, 5, 12, 4, 90, 1, 90);
                                        break;
                                    }

                                    if ( baseTower && baseTower->isValidPlacement(j, i, *gameMap, placedTowers)) {
                                        double towerCost = baseTower->getCost();
                                        if (player.hasEnoughFunds(towerCost)) {
                                            player.subtractPlayerFunds(towerCost);
                                            playerFundsText.setString("Gold: " + std::to_string(player.getPlayerFunds()));

                                            // Apply Decorator Pattern based on tower type or additional logic
                                            Tower* decoratedTower = baseTower;
                                            if (selectedTowerType == 4) { // Ice Wall gets Freezing effect
                                                decoratedTower = new FreezingEffectDecorator(decoratedTower);
                                            } else if (selectedTowerType == 5) { // Turret gets Splash damage
                                                decoratedTower = new SplashDamageDecorator(decoratedTower);
                                            }

                                            // Add more decorators as desired (e.g., random upgrades)

                                            if (rand() % 2 == 0) { // 50% chance of burning effect
                                                decoratedTower = new BurningDamageDecorator(decoratedTower);
                                            }



                                            // Apply Strategy Pattern for targeting
                                        switch (selectedTowerType) {
                                            case 1: // Archer: Nearest to Tower
                                                decoratedTower->setTargetingStrategy(new NearestToTowerStrategy());
                                                break;
                                            case 2: // Crossbow: Strongest
                                                decoratedTower->setTargetingStrategy(new StrongestCritterStrategy());
                                                break;
                                            case 3: // Sniper: Weakest
                                                decoratedTower->setTargetingStrategy(new WeakestCritterStrategy());
                                                break;
                                            case 4: // Ice Wall: Nearest to Exit
                                                decoratedTower->setTargetingStrategy(new NearestToExitStrategy());
                                                break;
                                            case 5: // Turret: Nearest to Tower
                                                decoratedTower->setTargetingStrategy(new NearestToTowerStrategy());
                                                break;
                                        }

                                            //Tower observers

                                            TowerObserver* observer = new TowerView(decoratedTower);
                                            decoratedTower->addObserver(observer);

                                            placedTowers.push_back(decoratedTower);
                                            gridCells[index].setFillColor(sf::Color::Blue);

                                            std::cout << "Tower placed at (" << j << ", " << i << ") with Observer attached.\n";
                                        } else {
                                            std::cout << "Not enough gold to place this tower!" << std::endl;
                                        }
                                    } else {
                                        std::cout << "Invalid tower placement!" << std::endl;
                                        delete baseTower;
                                    }
                                        // UPGRADE TOWER POWER

                                    } else if (mouseEvent->button == sf::Mouse::Button::Right) {

                                        for (auto it = placedTowers.begin(); it != placedTowers.end(); it++) {
                                            Tower* tower = *it;
                                            if (tower->getX() == j && tower->getY() == i) {
                                                double upgradeCost = tower->getCost();
                                                if (player.hasEnoughFunds(upgradeCost)) {   //checks if the player has enough funds before upgrading
                                                    player.subtractPlayerFunds(upgradeCost);
                                                    playerFundsText.setString("Gold: " + std::to_string(player.getPlayerFunds()));

                                                    Tower* upgradeTower = new LevelUpgradeDecorator(tower);
                                                    TowerObserver* newObserver = new TowerView(upgradeTower);
                                                    upgradeTower->addObserver(newObserver);

                                                    *it = upgradeTower;
                                                    delete tower;

                                                    std::cout<< "Tower at (" << j << ", " << i << ") upgraded to Level " << upgradeTower->getLevel() << " !.\n";
                                                    gridCells[index].setFillColor(sf::Color::Cyan);
                                                    break;
                                                } else {
                                                    std::cout << "Not enough gold to upgrade this tower!" << std::endl;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }




            }

            if (gameState == GameState::MAP_INPUT) {
                if (auto textEvent = event->getIf<sf::Event::TextEntered>()) {
                    char inputChar = static_cast<char>(textEvent->unicode);



                    if (std::isdigit(inputChar)) {
                        if (typingLength && lengthStr.size() < 3) lengthStr += inputChar;
                        else if (!typingLength && widthStr.size() < 3) widthStr += inputChar;
                    }
                    else if (inputChar == '\b') {
                        if (typingLength && !lengthStr.empty()) lengthStr.pop_back();
                        else if (!typingLength && !widthStr.empty()) widthStr.pop_back();
                    }
                    else if (inputChar == '\r' || inputChar == '\n') {
                        typingLength = !typingLength;
                    }

                    lengthInput.setString(lengthStr);
                    widthInput.setString(widthStr);
                }
            }
        }

        window.clear(sf::Color::Black);

        if (gameState == GameState::MENU) {
            window.draw(title);
            window.draw(startButton);
            window.draw(startText);
        }
        else if (gameState == GameState::MAP_INPUT) {
            window.draw(lengthText);
            window.draw(widthText);
            window.draw(lengthBox);
            window.draw(widthBox);
            window.draw(lengthInput);
            window.draw(widthInput);
            window.draw(doneButton);
            window.draw(doneText);
        }
        else if (gameState == GameState::DISPLAY_GRID) {
            window.draw(instructionText);
            for (const auto& cell : gridCells) window.draw(cell);

            window.draw(validateButton);
            window.draw(validateText);
            window.draw(validationResult);

            if (isMapValid) {
                window.draw(nextButton);
                window.draw(nextText);
            }
        }
        else if (gameState == GameState::MAP_VIEW) {
            for (const auto& cell : gridCells) {
                window.draw(cell);
            }

            if (!isReady) {
                window.draw(readyButton);
                window.draw(readyText);
                window.draw(upgradeText);
            } else {
                //critter spawns
                if (critterSpawnIndex < critters.size() && spawnTimer.getElapsedTime().asSeconds() > spawnDelay) {
                    critterSpawnIndex++;
                    spawnTimer.restart();
                }

                //critters movement
                static sf::Clock critterMoveClock;
                if (critterMoveClock.getElapsedTime().asSeconds() > 0.6f) {
                    for (int i = 0; i < critterSpawnIndex; i++) {
                        critters[i]->move(*gameMap);
                    }

                    critterMoveClock.restart();
                }

                //tower attacks

                static sf::Clock towerAttackClock;
                if (towerAttackClock.getElapsedTime().asSeconds() > 0.5f && !critters.empty()) {
                    std::cout << "Towers attempting to attack...\n";
                    for (Tower* tower : placedTowers) {
                        tower->acquireTarget(critters);
                    }

                    // Clean up dead critters
                    critters.erase(
                        std::remove_if(critters.begin(), critters.end(),
                            [](Critter* c) {
                                if (c->isDead() || c->hasReachedExit()) {
                                    std::cout << "Critter removed from game (Dead or Exited Map).\n";
                                    delete c;
                                    return true;
                                }
                                return false;
                            }),
                        critters.end()
                    );
                    towerAttackClock.restart();
                } else if (critters.empty()) {
                    std::cout << "All critters defeated or escaped!.\n";
                    isReady = false;  // reset to allow new wave or game over
                }

                //critter drawing

                for (int i = 0; i < critterSpawnIndex; i++) {
                    sf::CircleShape critterShape(10);
                    critterShape.setFillColor(sf::Color::Red);

                    float cellSize = std::min(maxCellSize, std::min(600 / gridHeight, 800 / gridWidth));
                    float startX = (800 - (gridWidth * cellSize)) / 2;
                    float startY = (600 - (gridHeight * cellSize)) / 2 + 30;

                    float critterOffset = (cellSize - 20) / 2;
                    critterShape.setRadius(10);

                    sf::Vector2f critterPosition(
                        startX + critters[i]->getPosition().second * cellSize + critterOffset,
                        startY + critters[i]->getPosition().first * cellSize + critterOffset
                    );

                    critterShape.setPosition(critterPosition);
                    window.draw(critterShape);
                }




            }

            playerFundsText.setString("Gold: " + std::to_string(player.getPlayerFunds()));
            window.draw(playerFundsText);

            window.draw(towerTypesText);
            window.draw(archerTowerText);
            window.draw(crossbowTowerText);
            window.draw(sniperTowerText);
            window.draw(iceWallText);
            window.draw(turretTowerText);
            window.draw(selectedTowerText);

        }







        window.display();
    }

    if (gameMap) delete gameMap;
    if (observer) delete observer;

    //prevent memory leaks by deleting towers and critters

    for (Tower* tower : placedTowers) {
        delete tower;
    }

    for (Critter* critter : critters) {
        delete critter;
    }

    return 0;
}
