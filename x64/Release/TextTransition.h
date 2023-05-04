#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#ifndef TEXTTRANSITION_H
#define TEXTTRANSITION_H

class TextTransition
{
public:
    TextTransition(std::string text, sf::Vector2f position, unsigned int size);
    sf::Text getText() const { return m_text; }
    bool moveText();
    void draw(sf::RenderWindow& window);
    void resetClock();
    bool getReset() const { return m_reset; }
    void setReset(bool reset);
    void resetTransition();
    void setResetPosition(bool reset);
    bool getResetPosition() const { return resetPosition; }

private:
    sf::Text m_text;
    sf::Font font;
    sf::Clock waitTimer;
    sf::Vector2f m_position;
    bool m_reset = true;
    bool resetPosition = true;
};

#endif