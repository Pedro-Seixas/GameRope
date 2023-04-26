#include "SFML/Graphics.hpp"
#include <iostream>
#include "level_one.h"
#include "MainMenu.h"

enum GameState { MENU, LEVEL_ONE };


int main()
{
    bool inMenu = true;
    GameState currentState = MENU;

    sf::RenderWindow window(sf::VideoMode(1280, 720), "I ROPE it works");
    window.setFramerateLimit(120);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        switch (currentState) {

        case MENU:
            if (menu(window) == 0)
            {
                std::cout << "start" << std::endl;
                currentState = LEVEL_ONE;
            }
            else if (menu(window) == 1)
            {
                std::cout << "about" << std::endl;
            }
            else if (menu(window) == 2)
            {
                window.close();
            }
            break;

        case LEVEL_ONE:
            if (levelOne(window))
            {
                std::cout << "Level One Completed" << std::endl;
            }
            break;
        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            currentState = MENU;
            resetMenu();
        }
    }

    return 0;
}