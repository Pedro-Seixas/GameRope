#include "Goal.h"
#include "Ball.h"
#include <iostream>


Goal::Goal(sf::Vector2f position, sf::Vector2f size)
{
    m_position = position;

    m_goal.setPosition(position);
    m_goal.setFillColor(sf::Color::Green);
    m_goal.setSize(size);
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
        std::cout << "GOOOOOOOOOOOOAL" << std::endl;
        ball->setBallStatus(true);
        ball->scoredGoal();
        return true;

    }
    else
    {
        return false;
    }

}