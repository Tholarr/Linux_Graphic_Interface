/*
** EPITECH PROJECT, 2024
** Linux_Graphique_Interface
** File description:
** Main
*/
#include <SFML/Graphics.hpp>
#include <iostream>

sf::RenderWindow window(sf::VideoMode(1920, 1080), "Graphic Interface");

int main(void)
{
    sf::Vector2f squareSize(1920.f, 1080.f);
    sf::Vector2f squarePosition(window.getSize().x / 2.f - squareSize.x / 2.f, window.getSize().y / 2.f - squareSize.y / 2.f);

    sf::RectangleShape square(squareSize);
    square.setPosition(squarePosition);
    square.setFillColor(sf::Color(0, 0, 0, 230));

    bool squareVisible = false;
    bool MenuIsOpen = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Space)
                    MenuIsOpen = !MenuIsOpen;
            }
        }

        window.clear(sf::Color::Red);

        if (MenuIsOpen)
            window.draw(square);

        window.display();
    }
    return 0;
}
