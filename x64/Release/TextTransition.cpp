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
    m_position = position;
}
bool TextTransition::moveText()
{
    static float velocity;
    std::cout << waitTimer.getElapsedTime().asSeconds() << std::endl;
    sf::Vector2f position = m_text.getPosition();

    if (m_text.getPosition().x >= 500 && waitTimer.getElapsedTime().asSeconds() <= 1.7)
    {
        velocity = 0.f;
    }
    else
    {
        velocity = 30.f;
        std::cout << m_text.getPosition().x << std::endl;
        m_text.setPosition(sf::Vector2f(position.x + velocity, position.y));
    }
    //Check if Text left screen
    if (m_text.getPosition().x > 2000)
    {
        std::cout << m_text.getPosition().x << std::endl;
        return true;
    }
    else
    {
        return false;
    }
}

void TextTransition::resetClock()
{
    waitTimer.restart();
    setReset(false);
}

void TextTransition::setReset(bool reset)
{
    m_reset = reset;
}

void TextTransition::draw(sf::RenderWindow& window)
{
    window.draw(m_text);
}

void TextTransition::resetTransition()
{

}