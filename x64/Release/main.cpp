#include "SFML/Graphics.hpp"
#include <iostream>
#include "level_one.h"
#include "MainMenu.h"
#include "TextTransition.h"

std::string aboutString = " This game was designed by Pedro Seixas.\n\n The goal is to release the Ball by pressing [SPACE]\n \
so it reaches the Goal.\n\n This was a fun project to do and building the logic behind\n the main loop was tricky. But I \
am happy with the result.";

enum GameState { MENU, ABOUT, LEVEL_ONE, LEVEL_TWO, LEVEL_THREE, LEVEL_FOUR };

TextTransition about(aboutString, sf::Vector2f(200, 200), 30);

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
                currentState = ABOUT;
            }
            else if (menu(window) == 2)
            {
                window.close();
            }
            break;
        case ABOUT:
            window.clear(sf::Color(32, 32, 32));
            about.draw(window);
            break;
        case LEVEL_ONE:
            //Check if the level was completed, if so apply transition and check if its done applying the transition.
            if (level(window))
            {
                if (transition(window))
                {
                    currentState = LEVEL_TWO;
                }
            }
            break;

        case LEVEL_TWO:
            loadLevelTwo(window);

            if (level(window) && getCompleteStatus())
            {

                if (transition(window))
                {
                    currentState = LEVEL_THREE;
                }
            }
            break;
        case LEVEL_THREE:
            loadLevelThree(window);
            if (level(window))
            {
                if (transition(window))
                {
                    currentState = LEVEL_FOUR;
                }
            }
            break;

        case LEVEL_FOUR:
            loadLevelFour(window);
            if (level(window))
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
