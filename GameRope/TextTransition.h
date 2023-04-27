#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#ifndef TEXTTRANSITION_H
#define TEXTTRANSITION_H

class TextTransition
{
public:
    TextTransition(std::string text, sf::Vector2f position);
    sf::Text getText() const { return m_text; }
    void moveText();
    void draw(sf::RenderWindow& window);

private:
    sf::Text m_text;
    sf::Font font;
    sf::Clock clock;
};

#endif