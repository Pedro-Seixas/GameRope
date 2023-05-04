#include "Goal.h"
#include "Ball.h"
#include <iostream>


Goal::Goal(sf::Vector2f position, sf::Vector2f size)
{
    m_position = position;

    m_goal.setPosition(position);
    m_goal.setFillColor(sf::Color::Green);
    m_goal.setSize(size);

    //Audio
    if (!buffer.loadFromFile("audio/goal.wav"))
    {
        std::cout << "Failed to load Audio" << std::endl;
    }

    sound.setBuffer(buffer);
    sound.setVolume(50.f);
};

void Goal::draw(sf::RenderWindow& window)
{
    window.draw(m_goal);
}

bool Goal::checkIfScored(Ball* ball)
{
    sf::CircleShape m_ball = ball->m_ball;
    //Check if ball is inside goal.
    if (m_goal.getGlobalBounds().contains(m_ball.getPosition()))
    {
        ball->setBallStatus(true);
        ball->scoredGoal();
        if (playOnce)
        {
            sound.play();
            playOnce = false;
        }
        return true;

    }
    else
    {
        playOnce = true;
        return false;
    }

}

void Goal::setNewPosition(sf::Vector2f position)
{
    m_goal.setPosition(position);
}

void Goal::setSize(sf::Vector2f size)
{
    m_goal.setSize(size);
}
