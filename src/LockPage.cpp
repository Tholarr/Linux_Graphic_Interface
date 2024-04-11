/*
** EPITECH PROJECT, 2024
** Linux_Graphic_Interface
** File description:
** LockPage
*/
#include "include/LockPage.hpp"

LockPage::LockPage(sf::RenderWindow &window)
{
    isLocked_ = true;

    if (!font_.loadFromFile("fonts/Magica.otf"))
        std::cerr << "Error loading font" << std::endl;


    sf::Vector2u windowSize = window.getSize();
    sf::Vector2f boxSize(300.f, 50.f);
    sf::Vector2f boxPosition((windowSize.x - boxSize.x) / 2.f, (windowSize.y - boxSize.y) / 2.f);

    passwordBox_.setSize(boxSize);
    passwordBox_.setPosition(boxPosition);
    passwordBox_.setFillColor(sf::Color (0, 0, 0, 50));
    passwordBox_.setOutlineColor(sf::Color::White);
    passwordBox_.setOutlineThickness(2);

    enteredText_.setFont(font_);
    enteredText_.setCharacterSize(24);
    sf::Vector2f enteredTextPosition(boxPosition.x + 10.f, boxPosition.y + 5);
    enteredText_.setPosition(enteredTextPosition);

    if (!lockTexture_.loadFromFile("assets/lockScreen.jpg")) {
        std::cerr << "Error loading background" << std::endl;
    }

    lockBackground_.setSize(sf::Vector2f(1920, 1080));
    lockBackground_.setTexture(&lockTexture_);
}

LockPage::~LockPage() {
    isLocked_ = true;
}

void LockPage::lock()
{
    isLocked_ = true;
}

void LockPage::unlock()
{
    isLocked_ = false;
}

void LockPage::drawLockPage(sf::RenderWindow &window)
{
    window.draw(lockBackground_);
    window.draw(passwordBox_);
    window.draw(enteredText_);
}

void LockPage::updateEnteredPassord()
{
    if (enteredPassword_.empty()) {
        enteredText_.setString("password");
        enteredText_.setFillColor(sf::Color (255, 255, 255, 100));
    } else {
        enteredText_.setString(enteredPassword_);
        enteredText_.setFillColor(sf::Color::White);
    }
}
