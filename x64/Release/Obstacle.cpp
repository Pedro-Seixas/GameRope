#include "Obstacle.h"
#include "Ball.h"


Obstacle::Obstacle(sf::Vector2f position, float rotation, sf::Vector2f size)
{
	m_obstacle.setPosition(position);
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