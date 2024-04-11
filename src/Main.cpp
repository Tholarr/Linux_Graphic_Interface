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

void eventsHandler(sf::Event& event, MainMenu& menu, LockPage& lockPage)
{
    const std::string correctPassword = "test";

    if (event.type == sf::Event::Closed)
        window.close();
    if (lockPage.isLocked())
        lockPage.updateEnteredPassord();
    if (lockPage.isLocked() && event.type == sf::Event::TextEntered) {
        if (event.text.unicode == 13) { // enter key
            if (lockPage.enteredPassword_ == correctPassword) {
                lockPage.unlock();
                lockPage.enteredPassword_.clear();
            } else {
                lockPage.enteredPassword_.clear();
            }
        } else if (event.text.unicode == 8) { // delete key
            if (!lockPage.enteredPassword_.empty())
                lockPage.enteredPassword_.pop_back();
        } else {
            if (lockPage.enteredPassword_.size() < 10)
                lockPage.enteredPassword_ += static_cast<char>(event.text.unicode);
        }
    } else if (!lockPage.isLocked() && event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Space)
            menu.isOpen() ? menu.close() : menu.open();
    }
}

int main(void)
{
    LockPage lockPage(window);
    MainMenu menu;

    std::vector<std::string> options = {"Option 1", "Option 2", "Option 3"};
    menu.setOptions(options);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            eventsHandler(event, menu, lockPage);
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
