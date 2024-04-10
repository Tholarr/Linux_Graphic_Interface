/*
** PERSONAL PROJECT, 2024
** Linux_Graphic_Interface
** File description:
** MainMenu
*/

#ifndef MAINMENU_HPP_
#define MAINMENU_HPP_
#include <vector>
#include <SFML/Graphics.hpp>

class MainMenu {
    public:
        MainMenu();
        ~MainMenu();

        void open();
        void close();
        bool isOpen() const { return isOpen_; }

        void setOptions(const std::vector<std::string>& options);
        int getSelectedOption() const { return selectedIndex_; }

        void drawMainMenu(sf::RenderWindow& window) const;

    private:
        bool isOpen_;
        int selectedIndex_;
        std::vector<std::string> options_;

        // sf::RectangleShape dropdownBackground_;
        // std::vector<sf::Text> optionTexts_;

};

#endif /* !MAINMENU_HPP_ */
