/*
** PERSONAL PROJECT, 2024
** Linux_Graphic_Interface
** File description:
** MainMenu
*/
#include "include/MainMenu.hpp"
#include <iostream>

MainMenu::MainMenu()
{
    isOpen_ = false;
    selectedIndex_ = -1;
}

MainMenu::~MainMenu()
{
    isOpen_ = false;
}

void MainMenu::open()
{
    isOpen_ = true;
}

void MainMenu::close()
{
    isOpen_ = false;
}

void MainMenu::setOptions(const std::vector<std::string>& options)
{
    options_ = options;
    selectedIndex_ = -1;
    std::cout << "1 : " << options_[0] << std::endl;
    std::cout << "2 : " << options_[1] << std::endl;
    std::cout << "3 : " << options_[2] << std::endl;
}

void MainMenu::drawMainMenu(sf::RenderWindow& window) const
{
    sf::Vector2f size(1920.f, 1080.f);
    sf::Vector2f position(window.getSize().x / 2.f - size.x / 2.f, window.getSize().y / 2.f - size.y / 2.f);

    sf::RectangleShape background(size);
    background.setPosition(position);
    background.setFillColor(sf::Color(0, 0, 0, 230));

    window.draw(background);
}