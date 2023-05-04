#include "SFML/Graphics.hpp"
#include <iostream>
#include "level_one.h"
#include "MainMenu.h"
#include "TextTransition.h"
TextTransition text2("LEVEL TWO", sf::Vector2f(-700.f, 100), 42);
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
            if (levelOne(window))
            {
                text2.draw(window);
                if (transition(window, text2))
                {

                    text2.resetTransition();
                    currentState = LEVEL_TWO;
                }
            }
            break;

        case LEVEL_TWO:
            loadLevelTwo(window);
            std::cout << "Dentro LEVEL TWO mas antes do bloco" << std::endl;

            if (levelOne(window) && getCompleteStatus())
            {
                text2.draw(window);
                text2.setReset(true);
                if (transition(window, text2))
                {
                    std::cout << "Level Two" << std::endl;
                    text2.resetTransition();
                    currentState = LEVEL_THREE;
                }
            }
            break;
        case LEVEL_THREE:
            loadLevelThree(window);
            if (levelOne(window))
            {
                text2.draw(window);
                if (transition(window, text2))
                {
                    std::cout << "Level Three" << std::endl;
                    currentState = LEVEL_THREE;
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
