/*
** PERSONAL PROJECT, 2024
** Linux_Graphique_Interface
** File description:
** Main
*/
#include <SFML/Graphics.hpp>
#include <iostream>

#include "include/MainMenu.hpp"
#include "include/LockPage.hpp"

sf::RenderWindow window(sf::VideoMode(1920, 1080), "Graphic Interface");

int main(void)
{
    MainMenu menu;
    LockPage lockPage;

    std::vector<std::string> options = {"Option 1", "Option 2", "Option 3"};
    menu.setOptions(options);

    const std::string correctPassword = "test";

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (lockPage.isLocked() && event.type == sf::Event::TextEntered) {
                if (event.text.unicode == 13) {
                    if (lockPage.enteredPassword_ == correctPassword) {
                        lockPage.unlock();
                        lockPage.enteredPassword_.clear();
                        lockPage.updateEnteredPassord();
                    } else {
                        lockPage.enteredPassword_.clear();
                        lockPage.updateEnteredPassord();
                    }
                } else if (event.text.unicode == 8) {
                    if (!lockPage.enteredPassword_.empty()) {
                        lockPage.enteredPassword_.pop_back();
                        lockPage.updateEnteredPassord();
                    }
                } else {
                    lockPage.enteredPassword_ += static_cast<char>(event.text.unicode);
                    lockPage.updateEnteredPassord();
                }
            } else if (!lockPage.isLocked() && event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Space) {
                    menu.isOpen() ? menu.close() : menu.open();
                }
            }
        }

        window.clear(sf::Color::Red);

        if (lockPage.isLocked())
            lockPage.drawLockPage(window);
        if (menu.isOpen())
            menu.drawMainMenu(window);

        window.display();
    }
    return 0;
}
