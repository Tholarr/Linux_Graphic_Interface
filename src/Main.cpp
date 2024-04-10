/*
** PERSONAL PROJECT, 2024
** Linux_Graphique_Interface
** File description:
** Main
*/
#include <SFML/Graphics.hpp>
#include <iostream>

#include "include/MainMenu.hpp"

sf::RenderWindow window(sf::VideoMode(1920, 1080), "Graphic Interface");

int main(void)
{
    MainMenu menu;

    std::vector<std::string> options = {"Option 1", "Option 2", "Option 3"};
    menu.setOptions(options);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Space)
                    menu.isOpen() ? menu.close() : menu.open();
            }
        }

        window.clear(sf::Color::Red);

        if (menu.isOpen())
            menu.drawMainMenu(window);

        window.display();
    }
    return 0;
}
