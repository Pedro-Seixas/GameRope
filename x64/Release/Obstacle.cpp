#include "Obstacle.h"
#include "Ball.h"


Obstacle::Obstacle(sf::Vector2f position, float rotation, sf::Vector2f size)
{
	m_obstacle.setPosition(position);
    m_position = position;
	m_obstacle.setSize(size);
	m_obstacle.setFillColor(sf::Color::White);
	m_obstacle.setRotation(rotation);

}

void Obstacle::draw(sf::RenderWindow& window)
{
	window.draw(m_obstacle);
}

void Obstacle::ballHitObstacle(Ball* ball)
{
    sf::FloatRect obstacleRect = m_obstacle.getGlobalBounds();
    sf::FloatRect m_ballRect = ball->m_ball.getGlobalBounds();

    if (obstacleRect.intersects(m_ballRect))
    {
        ball->invertVelocity();
    }

}

void Obstacle::setNewPosition(sf::Vector2f position)
{
    m_obstacle.setPosition(position);
    m_position = position;
}

void Obstacle::setSize(sf::Vector2f size)
{
    m_obstacle.setSize(size);
}

void Obstacle::obstacleEnable(bool status)
{
    if (status)
    {
        m_obstacle.setPosition(m_position);
    }
    else
    {
        //Place obstacle in a non visible place.
        m_obstacle.setPosition(sf::Vector2f(5000.f, 5000.f));
    }
}

void Obstacle::setRotation(float angle)
{
    m_obstacle.setRotation(angle);
}