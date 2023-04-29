#include "TextTransition.h"
TextTransition::TextTransition(std::string text, sf::Vector2f position, unsigned int size)
{
    if (!font.loadFromFile("font/Boba_Cups.ttf"))
    {
        std::cout << "Failed to load Font" << std::endl;
    }

    m_text.setString(text);
    m_text.setFont(font);
    m_text.setCharacterSize(size);
    m_text.setFillColor(sf::Color::White);
    m_text.setPosition(position);
}
bool TextTransition::moveText()
{
    static float velocity;
    static sf::Clock waitTimer;

    sf::Vector2f position = m_text.getPosition();

    if (m_text.getPosition().x >= 500 && waitTimer.getElapsedTime().asSeconds() <= 1.7)
    {
        velocity = 0.f;
    }
    else
    {
        velocity = 30.f;
        m_text.setPosition(sf::Vector2f(position.x + velocity, position.y));
    }
    //Check if Text left screen
    if (m_text.getPosition().x > 2000)
    {
        return true;
    }
    else
    {
        return false;
    }
}