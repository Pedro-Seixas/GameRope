#include "SFML/Graphics.hpp"
#include <iostream>
#include "level_one.h"
#include "MainMenu.h"
#include "TextTransition.h"

enum GameState { MENU, LEVEL_ONE, LEVEL_TWO, LEVEL_THREE };

int main()
{
    bool inMenu = true;
    GameState currentState = MENU;

    sf::RenderWindow window(sf::VideoMode(1280, 720), "I ROPE it works");
    window.setFramerateLimit(60);

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
                currentState = LEVEL_ONE;
            }
            else if (menu(window) == 1)
            {

            }
            else if (menu(window) == 2)
            {
                window.close();
            }
            break;
        case LEVEL_ONE:
            //Check if the level was completed, if so apply transition and check if its done applying the transition.
            if (levelOne(window))
            {
                if (transition(window))
                {
                    currentState = LEVEL_TWO;
                }
            }
            break;

        case LEVEL_TWO:
            loadLevelTwo(window);

            if (levelOne(window) && getCompleteStatus())
            {

                if (transition(window))
                {
                    currentState = LEVEL_THREE;
                }
            }
            break;
        case LEVEL_THREE:
            loadLevelThree(window);
            if (levelOne(window))
            {
                if (transition(window))
                {
                    currentState = LEVEL_ONE;
                }
            }
            break;

        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            currentState = MENU;
            resetMenu();
        }

        window.display();
    }

    return 0;
}
