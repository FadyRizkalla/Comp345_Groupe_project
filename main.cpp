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
#include "CritterFactory.h"
#include <fstream>


enum class GameState {
    MENU,
    MAP_INPUT,
    DISPLAY_GRID,
    MAP_VIEW
};


int main() {

  	std::ofstream("Logs.txt");
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

    bool isMapValid = false;
    Player player;



    std::pair<int, int> entryPoint = {-1, -1};
    std::pair<int, int> exitPoint = {-1, -1};

    SFMLMapObserver* observer = nullptr;

    int selectedTowerType = 0;

    sf::Text selectedTowerText(font, "Selected: None", 24);
    selectedTowerText.setFillColor(sf::Color::White);
    selectedTowerText.setPosition({800.f, 240.f});

    //Tower Upgrade UI

    sf::Text upgradeInfoText(font, "", 20); // Displays upgrade cost and description
    upgradeInfoText.setFillColor(sf::Color::White);
    upgradeInfoText.setPosition({800.f, 290.f});

    sf::RectangleShape upgradeButton({200.f, 50.f});
    upgradeButton.setFillColor(sf::Color::White);
    upgradeButton.setPosition({800.f, 340.f});
    upgradeButton.setOutlineThickness(2.f);
    upgradeButton.setOutlineColor(sf::Color::Black);

    sf::Text upgradeButtonText(font, "Upgrade", 30);
    upgradeButtonText.setFillColor(sf::Color::Black);
    upgradeButtonText.setPosition({870.f, 350.f});

    //end of upgrade UI


    sf::RectangleShape readyButton({200.f, 50.f});
    readyButton.setFillColor(sf::Color::White);
    readyButton.setPosition({800.f, 410.f});

    sf::Text readyText(font, "Ready", 30);
    readyText.setFillColor(sf::Color::Black);
    readyText.setPosition({870.f, 420.f});

    bool isReady = false;

    std::vector<Critter*> critters;
    std::srand(std::time(nullptr));

    sf::Clock spawnTimer;
    int critterSpawnIndex = 0;
    float spawnDelay = 0.5f;

    Tower* selectedTower = nullptr;  //track currently selected Tower
    int selectedTowerIndex = -1;  //Index of placedTowers for the selected tower
    bool isUpgrading = false;

    int waveNumber = 1;

    sf::Text crittersInEndZoneText(font, "Critters in End Zone: 0", 24);
	crittersInEndZoneText.setFillColor(sf::Color::White);
	crittersInEndZoneText.setPosition({10.f, 750.f});

    sf::Texture sceneryTexture;
if (!sceneryTexture.loadFromFile("scenery.png")) {
    std::cerr << "Error loading scenery texture!" << std::endl;
    return -1;
}

sf::Sprite scenerySprite(sceneryTexture);


sf::Texture pathTexture;
if (!pathTexture.loadFromFile("path.png")) {
    std::cerr << "Error loading path texture!" << std::endl;
    return -1;
}

sf::Sprite pathSprite(pathTexture);

sf::Texture towerTexture;
if (!towerTexture.loadFromFile("tower.png")) {
    std::cerr << "Error loading tower texture!" << std::endl;
    return -1;
}
sf::Sprite towerSprite(towerTexture);

    // Load the Critter textures
sf::Texture ogreTexture;
    if (!ogreTexture.loadFromFile("ogre.png")) {
        std::cerr << "Error loading ogre texture!" << std::endl;
        return -1;
    }
sf::Sprite ogreSprite(ogreTexture);

sf::Texture goblinTexture;
    if (!goblinTexture.loadFromFile("goblin.png")) {
        std::cerr << "Error loading goblin texture!" << std::endl;
        return -1;
    }
sf::Sprite goblinSprite(goblinTexture);

    sf::Text critterHealthText(font, "Critter Health: N/A", 24);
    critterHealthText.setFillColor(sf::Color::White);
    critterHealthText.setPosition({800.f, 370.f});


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
                        std::ofstream("Logs.txt", std::ios::app) << "Next button clicked! Switching to MAP VIEW mode..." << std::endl;

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
                            std::ofstream("Logs.txt", std::ios::app) << "Player is ready! Critters will spawn one by one.\n" << std::endl;




                            std::ofstream("Logs.txt", std::ios::app) << "Entry Point: (" << entryPoint.first << ", " << entryPoint.second << ")\n" << std::endl;


                            std::vector<std::pair<int, int>> path = gameMap->getPath();
                            std::ofstream("Logs.txt", std::ios::app) << "Full Path: " << std::endl;

                            for (const auto& step : path) {
                                std::ofstream("Logs.txt", std::ios::app) << "(" << step.first << ", " << step.second << ") " << std::endl;
                            }
                            std::ofstream("Logs.txt", std::ios::app) << "\n" << std::endl;



                            if (!path.empty()) {
                                std::ofstream("Logs.txt", std::ios::app) << "First Path Cell: (" << path.front().first << ", " << path.front().second << ")\n";
                            } else {
                                std::ofstream("Logs.txt", std::ios::app) << "Error: No valid path found!\n";
                            }

                            if (entryPoint.first != -1 && entryPoint.second != -1) {
                                if (!path.empty() && path.front() == entryPoint) {
                                    std::ofstream("Logs.txt", std::ios::app) << "Entry matches first path cell. Spawning correctly." << std::endl;
                                } else {
                                    std::ofstream("Logs.txt", std::ios::app) << "Warning: Entry point (" << entryPoint.first << ", " << entryPoint.second
                                              << ") does NOT match first path step (" << path.front().first << ", " << path.front().second << ")."
                                              << " Adjusting entry position." << std::endl;
                                    if (path.empty() || path.front() != entryPoint) {
                                        std::ofstream("Logs.txt", std::ios::app) << "Error: Path does not start from the correct entry!\n";
                                    }

                                }

                                std::vector<Critter*> newCritters = CritterFactory::createCritters(waveNumber, entryPoint, exitPoint, path);
                                critters.insert(critters.end(), newCritters.begin(), newCritters.end());

                                waveNumber++;

                                // Observe the new critters
                                for (Critter* critter : newCritters) {
                                    CritterObserver* critterObserver = new CritterView(critter);
                                }

                                spawnTimer.restart();
                                critterSpawnIndex = 0;

                            } else {
                                std::ofstream("Logs.txt", std::ios::app) << "Error: No entry point set!\n";
                            }
                        }

                        if (!isReady) {
                            //check for upgrade button click

                            if (selectedTower && upgradeButton.getGlobalBounds().contains(mousePos)) {
                                if (selectedTowerIndex >= 0 && selectedTowerIndex < placedTowers.size()) {
                                    double upgradeCost = selectedTower->getCost();
                                    if (player.hasEnoughFunds(upgradeCost)) {  //checks if player has enough funds to afford upgrade
                                        player.subtractPlayerFunds(upgradeCost);   //substracts the funds
                                        playerFundsText.setString("Gold: " + std::to_string(player.getPlayerFunds()));

                                        TargetingStrategy* strategy = selectedTower->getTargetingStrategy()->clone(); //Clone the current targeting strategy to preserve it.

                                        Tower* upgradedTower = new LevelUpgradeDecorator(selectedTower); //create the upgraded tower with LevelUpgradeDecorator
                                        upgradedTower->setTargetingStrategy(strategy); //set the cloned strategy

                                        TowerObserver* newObserver = new TowerView(upgradedTower); //add a new observer of the upgraded tower
                                        upgradedTower-> addObserver(newObserver);

                                        //update the placedTowers vector
                                        placedTowers[selectedTowerIndex] = upgradedTower; //replace old tower with upgraded one
                                        selectedTower->clearObservers();  //clean observer
                                        selectedTower = upgradedTower; //update selectedTower to point to upgraded tower

                                        //update console and  tower map
                                        std::ofstream("Logs.txt", std::ios::app) << "Tower at (" << selectedTower->getX() << ", " << selectedTower->getY() << ") upgraded to Level " << upgradedTower->getLevel() << "!\n";
                                        int index = selectedTower->getY() * gridWidth + selectedTower->getX();

                                        //Update upgrade info
                                        upgradeInfoText.setString("Level " + std::to_string(selectedTower->getLevel()) + ": Cost " + std::to_string((int)selectedTower->getCost()) + " gold\n+10 Power, +2 Range");
                                    } else {
                                        std::ofstream("Logs.txt", std::ios::app) << "Not enough gold to upgrade this tower! Need " << upgradeCost << " gold! \n" << std::endl;
                                    }
                                }else {
                                    std::ofstream("Logs.txt", std::ios::app) << "Error: Invalid tower selected for upgrade! \n";
                                    selectedTower = nullptr;
                                    selectedTowerIndex = -1;
                                    upgradeInfoText.setString("");
                                }
                            }

                         bool clickedOnTower = false;
                        for (int i = 0; i < gridHeight; i++) {
                            for (int j = 0; j < gridWidth; j++) {
                                int index = i * gridWidth + j;
                                if (gridCells[index].getGlobalBounds().contains(mousePos)) {
                                    //check if clicking in an existing tower
                                    for (int t = 0; t < placedTowers.size(); t++) {

                                        Tower* tower = placedTowers[t];
                                        if (tower->getX() == j && tower->getY() == i) {
                                            selectedTower = tower;
                                            selectedTowerIndex = t;
                                            clickedOnTower = true;

                                            //Reset all tower colors, highlight selected one

                                            for (auto& cell : gridCells) {
                                                if (cell.getFillColor() == sf::Color::Yellow) {
                                                    cell.setFillColor(sf::Color::Blue);
                                                }
                                            }
                                            gridCells[index].setFillColor(sf::Color::Yellow);

                                            // Display upgrade info
                                            upgradeInfoText.setString("Level " + std::to_string(selectedTower->getLevel()) +
                                                                      ": Cost " + std::to_string((int)selectedTower->getCost()) +
                                                                      " gold\n+10 Power, +2 Range");
                                            std::ofstream("Logs.txt", std::ios::app) << "Selected tower at (" << j << ", " << i << ")\n";
                                            break;

                                        }

                                    }

                                    //Deselect Tower if clicking on a non-tower cell
                                    if (!clickedOnTower) {
                                        selectedTower = nullptr;
                                        selectedTowerIndex = -1;
                                        upgradeInfoText.setString("");
                                        isUpgrading = false;
                                        for (auto& cell : gridCells) {
                                            if (cell.getFillColor() == sf::Color::Yellow) {
                                                cell.setFillColor(sf::Color::Blue);
                                            }
                                        }
                                    }



                                    if (!clickedOnTower && !isUpgrading &&  selectedTowerType != 0) {

                                        Tower* baseTower = nullptr;
                                        switch (selectedTowerType) {
                                            case 1: // Archer Tower
                                                baseTower = new Tower(i, j, 100, 3, 15, 2, 50, 1, 50);
                                                break;
                                            case 2: // Crossbow Tower
                                                baseTower = new Tower(i, j, 150, 4, 15, 3, 75, 1, 75);
                                                break;
                                            case 3: // Sniper Tower
                                                baseTower = new Tower(i, j, 200, 7, 20, 2, 100, 1, 100);
                                                break;
                                            case 4: // Ice Wall
                                                baseTower = new Tower(i, j, 120, 4, 5, 1, 60, 1, 60);
                                                break;
                                            case 5: // Turret Tower
                                                baseTower = new Tower(i, j, 180, 5, 12, 4, 90, 1, 90);
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
                                                    decoratedTower->setTargetingStrategy(new WeakestCritterStrategy());
                                                    break;
                                                case 3: // Sniper: Weakest
                                                    decoratedTower->setTargetingStrategy(new StrongestCritterStrategy());
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
                                                decoratedTower->placeTower(*gameMap);

                                                std::ofstream("Logs.txt", std::ios::app) << "Tower placed at (" << j << ", " << i << ") with range: " << decoratedTower->getRange() << ".\n";
                                            } else {
                                                std::ofstream("Logs.txt", std::ios::app) << "Not enough gold to place this tower!" << std::endl;
                                            }
                                        } else {
                                            std::ofstream("Logs.txt", std::ios::app) << "Invalid tower placement!" << std::endl;
                                            delete baseTower;
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
            float cellSize = std::min(maxCellSize, std::min(600 / gridHeight, 800 / gridWidth));

scenerySprite.setScale(
    sf::Vector2f(
        static_cast<float>(cellSize) / static_cast<float>(sceneryTexture.getSize().x),
        static_cast<float>(cellSize) / static_cast<float>(sceneryTexture.getSize().y)
    )
);


            for (int i = 0; i < gridHeight; i++) {
        for (int j = 0; j < gridWidth; j++) {
            int index = i * gridWidth + j;

            if (gameMap->getCellType(i, j) == CellType::SCENERY) {
                sf::Vector2f position = gridCells[index].getPosition();
                scenerySprite.setPosition(position);
                window.draw(scenerySprite);
            } else {
                window.draw(gridCells[index]);
            }
        }
    }

            window.draw(validateButton);
            window.draw(validateText);
            window.draw(validationResult);

            if (isMapValid) {
                window.draw(nextButton);
                window.draw(nextText);
            }
        }
        else if (gameState == GameState::MAP_VIEW) {
            float cellSize = std::min(maxCellSize, std::min(600 / gridHeight, 800 / gridWidth));

scenerySprite.setScale(
    sf::Vector2f(
        static_cast<float>(cellSize) / static_cast<float>(sceneryTexture.getSize().x),
        static_cast<float>(cellSize) / static_cast<float>(sceneryTexture.getSize().y)
    )
);

pathSprite.setScale(
        sf::Vector2f(
            static_cast<float>(cellSize) / static_cast<float>(pathTexture.getSize().x),
            static_cast<float>(cellSize) / static_cast<float>(pathTexture.getSize().y)
        )
    );

towerSprite.setScale(
        sf::Vector2f(
            static_cast<float>(cellSize) / static_cast<float>(pathTexture.getSize().x),
            static_cast<float>(cellSize) / static_cast<float>(pathTexture.getSize().y)
        )
    );

ogreSprite.setScale(
    sf::Vector2f(
        static_cast<float>(cellSize) / static_cast<float>(ogreTexture.getSize().x),
        static_cast<float>(cellSize) / static_cast<float>(ogreTexture.getSize().y)
        )
);

goblinSprite.setScale(
    sf::Vector2f(
        static_cast<float>(cellSize) / static_cast<float>(goblinTexture.getSize().x),
        static_cast<float>(cellSize) / static_cast<float>(goblinTexture.getSize().y)
    )
);


            for (int i = 0; i < gridHeight; i++) {
        for (int j = 0; j < gridWidth; j++) {
            int index = i * gridWidth + j;
            int towerIndex = j * gridWidth + i;

             bool towerPlaced = false;
            for (Tower* tower : placedTowers) {
                if (tower->getX() == j && tower->getY() == i) {
                  	sf::Vector2f position = gridCells[towerIndex].getPosition();
                    towerSprite.setPosition(position);
					window.draw(towerSprite);
                    towerPlaced = true;
                    break;
                }
            }

            if (gameMap->getCellType(i, j) == CellType::SCENERY) {
                sf::Vector2f position = gridCells[index].getPosition();
                scenerySprite.setPosition(position);
                window.draw(scenerySprite);
            }
            else if (gameMap->getCellType(i, j) == CellType::PATH) {
                sf::Vector2f position = gridCells[index].getPosition();
                pathSprite.setPosition(position);
                window.draw(pathSprite);
            }

            else {
              if(!towerPlaced){
                	window.draw(gridCells[index]);
                }
            }
        }
    }

            if (!isReady) {
                window.draw(readyButton);
                window.draw(readyText);
                if (selectedTower) {
                    window.draw(upgradeButton);
                    window.draw(upgradeButtonText);
                }
                window.draw(upgradeInfoText);
            } else {
                //critter spawns
                if (critterSpawnIndex < critters.size() && spawnTimer.getElapsedTime().asSeconds() > spawnDelay) {
                    critterSpawnIndex++;
                    spawnTimer.restart();
                }

                //critters movement
                static sf::Clock critterMoveClock;
                int crittersInEndZone = 0;
                if (critterMoveClock.getElapsedTime().asSeconds() > 0.6f) {
                    for (int i = 0; i < critterSpawnIndex; i++) {
                        critters[i]->move(*gameMap);

                        if (critters[i]->hasReachedExit()) {
        crittersInEndZone++;
        crittersInEndZoneText.setString("Critters in End Zone: " + std::to_string(crittersInEndZone));
    }
                    }

                    critterMoveClock.restart();
                }

                //tower attacks

                static sf::Clock towerAttackClock;
                if (towerAttackClock.getElapsedTime().asSeconds() > 0.5f && !critters.empty()) {
                    std::ofstream("Logs.txt", std::ios::app) << "Towers attempting to attack. Active towers: " << placedTowers.size() << "\n" <<  std::endl;

                    int totalHealth = 0;
                    for (Critter* critter : critters) {
                        totalHealth += critter->getHitPoints();
                    }

                    critterHealthText.setString("Total Critter Health: " + std::to_string(totalHealth));

                    for (Tower* tower : placedTowers) {
                      	std::ofstream("Logs.txt", std::ios::app) << "Tower range : " << tower->getRange() << "\n" << std::endl;
                        tower->acquireTarget(critters);
                        critterHealthText.setString("Total Critter Health: " + std::to_string(totalHealth));

                    }

                    // Clean up dead critters
                    critters.erase(
                        std::remove_if(critters.begin(), critters.end(),
                            [](Critter* c) {
                                if (c->isDead() || c->hasReachedExit()) {
                                    std::ofstream("Logs.txt", std::ios::app) << "Critter removed from game.\n";
                                    delete c;
                                    return true;
                                }
                                return false;
                            }),
                        critters.end()
                    );
                    towerAttackClock.restart();
                } else if (critters.empty()) {
                    std::ofstream("Logs.txt", std::ios::app) << "All critters defeated or escaped!.\n";
                    critterHealthText.setString("Total Critter Health: " + std::to_string(0));
                    isReady = false;  // reset to allow new wave or game over
                    player.setPlayerFunds(player.getPlayerFunds() + 250);
                    playerFundsText.setString("Gold: " + std::to_string(player.getPlayerFunds()));
                }

                //critter drawing



                for (int i = 0; i < critterSpawnIndex; i++) {

                    float startX = (800 - (gridWidth * cellSize)) / 2;
                    float startY = (500 - (gridHeight * cellSize)) / 2 + 30;
                    float critterOffset = (cellSize - 20) / 2;

                    sf::Vector2f critterPosition(
                        startX + critters[i]->getPosition().second * cellSize + critterOffset,
                        startY + critters[i]->getPosition().first * cellSize + critterOffset

                    );

                    //Check critter type and draw the appropriate sprite
                    if (dynamic_cast<Ogre_Critter*>(critters[i])) {
                        ogreSprite.setPosition(critterPosition);
                        window.draw(ogreSprite);
                    }else if (dynamic_cast<Goblin_Critter*>(critters[i])) {
                        goblinSprite.setPosition(critterPosition);
                        window.draw(goblinSprite);
                    }
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
            window.draw(crittersInEndZoneText);
            window.draw(critterHealthText);

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

