/*
** EPITECH PROJECT, 2024
** Linux_Graphic_Interface
** File description:
** LockPage
*/
#include "include/LockPage.hpp"

LockPage::LockPage()
{
    isLocked_ = true;

    if (!font_.loadFromFile("fonts/Magica.otf"))
        std::cerr << "Error loading font" << std::endl;

    lockText_.setFont(font_);
    lockText_.setString("Press SPACE to Unlock");
    lockText_.setCharacterSize(24);
    lockText_.setFillColor(sf::Color::White);
    lockText_.setPosition(100, 100);

    enteredText_.setFont(font_);
    enteredText_.setCharacterSize(24);
    enteredText_.setFillColor(sf::Color::White);
    enteredText_.setPosition(200, 200);

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
    window.draw(lockText_);
    window.draw(enteredText_);
}

void LockPage::updateEnteredPassord()
{
    enteredText_.setString(enteredPassword_);
}
