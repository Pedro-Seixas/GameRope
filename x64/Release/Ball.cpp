#include "Rope.h"
#include "Ball.h"
#include "Goal.h"
#include "Obstacle.h"

# define M_PI 3.14159265358979323846

Ball::Ball(float radius, sf::Vector2f position) : m_gravity(-0.2), m_velocity(0.f, 0.f)
{
    if (!ballTexture.loadFromFile("img/ballImg.png")) {
        std::cout << "Failed to Upload Image" << std::endl;
    }

    m_ball.setRadius(radius);
    m_ball.setPosition(position);
    m_ball.setTexture(&ballTexture);

    ballScored = false;
    ballEscaped = false;

    if (!buffer.loadFromFile("audio/releaseSound.wav"))
    {
        std::cout << "Failed to load Audio" << std::endl;
    }

    sound.setBuffer(buffer);
    sound.setVolume(50.f);

};

void Ball::setVelocity(float angle)
{
    //Convert angle from degrees to radians because of cmath functions
    float angleRadians = (angle) * (M_PI / 180);

    //Convert angular velocity to linear velocity
    float velocityX = 10 * cos(angleRadians);
    float velocityY = 10 * sin(angleRadians);

    m_velocity = sf::Vector2f(velocityX, velocityY);

}

void Ball::invertVelocity()
{
    m_velocity = sf::Vector2f(-m_velocity.x, m_velocity.y);
}

void Ball::ballEscape(sf::Vector2f velocity, sf::Vector2f position)
{
    float velocityMultiplier = 2.5;

    sf::Vector2f newPosition = position + sf::Vector2f(velocity.x * velocityMultiplier, -velocity.y * velocityMultiplier);

    m_velocity.y += m_gravity;

    update(newPosition);

}


void Ball::draw(sf::RenderWindow& window)
{
    window.draw(m_ball);
}

void Ball::update(sf::Vector2f newPosition) 
{
  
    m_ball.setPosition(newPosition);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        ballEscaped = true;
        if (!keyboardPressed)
        {
            sound.play();
            keyboardPressed = true;
        }
    }


}

void Ball::scoredGoal()
{
    m_velocity = sf::Vector2f(0.f, 0.f);
    m_gravity = 0.f;

}

bool Ball::outOfBounds()
{
    if ((m_ball.getPosition().x > 1400 || m_ball.getPosition().x < -400.f ) || m_ball.getPosition().y > 900)
    {
        if (keyboardPressed)
        {
            keyboardPressed = false;

        }
        return true;
    }
    else
    {
        return false;
    }
}

void Ball::setBallStatus(bool status)
{
    ballScored = status;
}

void Ball::setBallEscaped(bool escapeStatus)
{
    ballEscaped = escapeStatus;
}

void Ball::setGravity(float gravity)
{
    m_gravity = gravity;
}

void Ball::setKeyboardPressed(bool status)
{
    keyboardPressed = status;
}