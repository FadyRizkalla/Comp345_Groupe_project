#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <cctype>
#include <optional>

// Enum for tracking game state
enum class GameState {
    MENU,
    MAP_INPUT
};

int main() {
    // Create a window
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Tower Defense");

    // Load font
    sf::Font font;
    if (!font.openFromFile("arial.ttf")) {
        std::cerr << "Error loading font!\n";
        return -1;
    }

    // ---------------- Main Menu UI ----------------
    sf::Text title(font, "Tower Defense", 50);
    title.setFillColor(sf::Color::White);
    title.setPosition({250.f, 100.f});

    sf::RectangleShape startButton({200.f, 50.f});
    startButton.setFillColor(sf::Color::White);
    startButton.setPosition({300.f, 300.f});

    sf::Text startText(font, "Start", 30);
    startText.setFillColor(sf::Color::Black);
    startText.setPosition({370.f, 310.f});

    // ---------------- Input Screen UI ----------------
    sf::Text lengthText(font, "Length:", 30);
    lengthText.setFillColor(sf::Color::White);
    lengthText.setPosition({200.f, 200.f});

    sf::Text widthText(font, "Width:", 30);
    widthText.setFillColor(sf::Color::White);
    widthText.setPosition({200.f, 300.f});

    // ✅ **White Boxes for Input**
    sf::RectangleShape lengthBox({150.f, 40.f});
    lengthBox.setFillColor(sf::Color::White);
    lengthBox.setPosition({350.f, 200.f});

    sf::RectangleShape widthBox({150.f, 40.f});
    widthBox.setFillColor(sf::Color::White);
    widthBox.setPosition({350.f, 300.f});

    // ✅ **Black Input Text**
    sf::Text lengthInput(font, "", 30);
    lengthInput.setFillColor(sf::Color::Black);
    lengthInput.setPosition({365.f, 205.f}); // Center inside the box

    sf::Text widthInput(font, "", 30);
    widthInput.setFillColor(sf::Color::Black);
    widthInput.setPosition({365.f, 305.f}); // Center inside the box

    std::string lengthStr, widthStr;

    // Done Button
    sf::RectangleShape doneButton({200.f, 50.f});
    doneButton.setFillColor(sf::Color::White);
    doneButton.setPosition({300.f, 400.f});

    sf::Text doneText(font, "Done", 30);
    doneText.setFillColor(sf::Color::Black);
    doneText.setPosition({375.f, 410.f});

    bool typingLength = true;
    GameState gameState = GameState::MENU;

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
                        std::cout << "Map Size: " << lengthStr << " x " << widthStr << std::endl;
                    }
                }
            }

            // ✅ **SFML 3.0 Text Input Handling**
            if (gameState == GameState::MAP_INPUT) {
                if (auto textEvent = event->getIf<sf::Event::TextEntered>()) {
                    char inputChar = static_cast<char>(textEvent->unicode);

                    if (std::isdigit(inputChar)) { // Allow only numbers
                        if (typingLength) {
                            if (lengthStr.size() < 3) lengthStr += inputChar;
                        } else {
                            if (widthStr.size() < 3) widthStr += inputChar;
                        }
                    }
                    else if (inputChar == '\b') { // Backspace key
                        if (typingLength && !lengthStr.empty()) {
                            lengthStr.pop_back();
                        } else if (!typingLength && !widthStr.empty()) {
                            widthStr.pop_back();
                        }
                    }
                    else if (inputChar == '\r' || inputChar == '\n') { // Enter key switches input field
                        typingLength = !typingLength;
                    }

                    lengthInput.setString(lengthStr);
                    widthInput.setString(widthStr);
                }
            }
        }

        // Render UI
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
        window.display();
    }

    return 0;
}
