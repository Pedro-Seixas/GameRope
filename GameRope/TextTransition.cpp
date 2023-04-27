#include "TextTransition.h"
TextTransition::TextTransition(std::string text, sf::Vector2f position)
{
    if (!font.loadFromFile("font/Boba_Cups.ttf"))
    {
        std::cout << "Failed to load Font" << std::endl;
    }

    m_text.setString(text);
    m_text.setFont(font);
    m_text.setCharacterSize(32);
    m_text.setFillColor(sf::Color::White);
    m_text.setPosition(position);
}
void TextTransition::moveText()
{
    static float velocity;


    sf::Vector2f position = m_text.getPosition();

    if (m_text.getPosition().x >= 500)
    {
        velocity = 0.f;
    }
    else
    {
        velocity = 20.f;
        m_text.setPosition(sf::Vector2f(position.x + velocity, position.y));
    }
}