#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <cctype>
#include <optional>
#include "map.h"  // Include the Map class

// Enum for tracking game state
enum class GameState {
    MENU,
    MAP_INPUT,
    DISPLAY_GRID
};

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Tower Defense");

    sf::Font font;
    if (!font.openFromFile("arial.ttf")) {
        std::cerr << "Error loading font!\n";
        return -1;
    }

    // UI Elements
    sf::Text title(font, "Tower Defense", 50);
    title.setFillColor(sf::Color::White);
    title.setPosition({250.f, 100.f});

    sf::RectangleShape startButton({200.f, 50.f});
    startButton.setFillColor(sf::Color::White);
    startButton.setPosition({300.f, 300.f});

    sf::Text startText(font, "Start", 30);
    startText.setFillColor(sf::Color::Black);
    startText.setPosition({370.f, 310.f});

    // Map Input UI
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

    // Validate Button
    sf::RectangleShape validateButton({200.f, 50.f});
    validateButton.setFillColor(sf::Color::White);
    validateButton.setPosition({300.f, 520.f}); // Below the grid

    sf::Text validateText(font, "Validate", 30);
    validateText.setFillColor(sf::Color::Black);
    validateText.setPosition({355.f, 530.f}); // Centered on the button

    // Validation Result Text
    sf::Text validationResult(font, "", 24);
    validationResult.setFillColor(sf::Color::White);
    validationResult.setPosition({250.f, 580.f}); // Below the button


    bool typingLength = true;
    GameState gameState = GameState::MENU;
    Map* gameMap = nullptr;

    // Grid properties
    int gridWidth = 0, gridHeight = 0;
    std::vector<sf::RectangleShape> gridCells;
    std::vector<std::vector<bool>> cellStates;
    const int maxCellSize = 60;

    sf::Text instructionText(font, "Click to set Path (White), Entry (Green), Exit (Red)", 24);
    instructionText.setFillColor(sf::Color::White);
    instructionText.setPosition({100.f, 20.f});

    std::pair<int, int> entryPoint = {-1, -1};
    std::pair<int, int> exitPoint = {-1, -1};

    while (window.isOpen()) {
        while (const std::optional<sf::Event> event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();

            if (event->is<sf::Event::MouseButtonPressed>()) {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

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

                        std::cout << "Map Created with size: " << length << " x " << width << std::endl;

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

                        gameState = GameState::DISPLAY_GRID;
                    }
                }
                else if (gameState == GameState::DISPLAY_GRID) {
    if (validateButton.getGlobalBounds().contains(mousePos)) {
        if (gameMap) {
            bool isValid = gameMap->validateMap();
            validationResult.setString(isValid ? "Map is valid!" : "Map is NOT valid!");
            validationResult.setFillColor(isValid ? sf::Color::Green : sf::Color::Red);
        }
    }

    for (int i = 0; i < gridHeight; i++) {
        for (int j = 0; j < gridWidth; j++) {
            int index = i * gridWidth + j;
            if (gridCells[index].getGlobalBounds().contains(mousePos)) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E)) { // Entry point
                    if (entryPoint.first != -1) {
                        gameMap->setCell(entryPoint.first, entryPoint.second, CellType::SCENERY);
                        gridCells[entryPoint.first * gridWidth + entryPoint.second].setFillColor(sf::Color::Transparent);
                    }
                    gridCells[index].setFillColor(sf::Color::Green);
                    gameMap->setCell(i, j, CellType::ENTRY);
                    entryPoint = {i, j};
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::X)) { // Exit point
                    if (exitPoint.first != -1) {
                        gameMap->setCell(exitPoint.first, exitPoint.second, CellType::SCENERY);
                        gridCells[exitPoint.first * gridWidth + exitPoint.second].setFillColor(sf::Color::Transparent);
                    }
                    gridCells[index].setFillColor(sf::Color::Red);
                    gameMap->setCell(i, j, CellType::EXIT);
                    exitPoint = {i, j};
                }
                else { // Path toggle
                    cellStates[i][j] = !cellStates[i][j];
                    gameMap->setCell(i, j, cellStates[i][j] ? CellType::PATH : CellType::SCENERY);
                    gridCells[index].setFillColor(cellStates[i][j] ? sf::Color::White : sf::Color::Transparent);
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

            // Draw Validate Button
            window.draw(validateButton);
            window.draw(validateText);
            window.draw(validationResult); // Display validation result
        }


        window.display();
    }

    delete gameMap;
    return 0;
}
