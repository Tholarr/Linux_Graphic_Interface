/*
** EPITECH PROJECT, 2024
** Linux_Graphic_Interface
** File description:
** LockPage
*/

#ifndef LOCKPAGE_HPP_
#define LOCKPAGE_HPP_
#include <iostream>
#include <SFML/Graphics.hpp>

class LockPage {
public:
    LockPage();
    ~LockPage();

    void lock();
    void unlock();
    bool isLocked() const { return isLocked_; }

    void drawLockPage(sf::RenderWindow &window);

private:
    bool isLocked_;
    sf::Text lockText_;
    sf::Font font_;
    sf::RectangleShape lockBackground_;
    sf::Texture lockTexture_;
};

#endif /* !LOCKPAGE_HPP_ */
