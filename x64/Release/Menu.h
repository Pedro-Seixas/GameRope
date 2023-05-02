#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>
#ifndef MENU_H
#define MENU_H

class Menu
{
public:
    Menu(sf::Vector2f startPosition, sf::Vector2f size);
    void drawMenu(sf::RenderWindow& window);
    void update(sf::RenderWindow& window);
    int getButtonSelection();
    void setButtonSelection(int button);




private:
    struct Button {
        sf::Texture normalButton;
        sf::Texture selectedButton;
        sf::Sprite buttonSprite;
    };
    int buttonSelection=6;
    sf::Texture titleTexture;
    sf::Sprite titleSprite;
    std::unique_ptr<Button[]> buttons;
    sf::Sound sound;
    sf::SoundBuffer buffer;
};


#endif