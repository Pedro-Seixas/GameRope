#include "SFML/Graphics.hpp"
#include <iostream>
#include "MainMenu.h"

sf::Color grayBackground(32, 32, 32);

sf::Vector2f size = sf::Vector2f(200, 100);

//Adjust postion to be centered.

sf::Vector2f position = sf::Vector2f(1280 / 2 - (size.x/2.f), 720 / 2-(size.y/2.f));

//Create Menu Buttons
Menu menu_ob(position, size);

void resetMenu()
{
    menu_ob.setButtonSelection(6);
}

int menu(sf::RenderWindow& window)
{

    window.clear(grayBackground);

    menu_ob.update(window);
    menu_ob.drawMenu(window);

    window.display();

    return menu_ob.getButtonSelection();
}