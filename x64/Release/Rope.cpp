#include "Rope.h"
#include "Ball.h"

//Constructor
Rope::Rope(sf::Vector2f startPosition, float width, float height, sf::Vector2f spherePosition) : m_angle(0.f)
{

    if (!texture.loadFromFile("img/ropeImg.png")) {
        std::cout << "Failed to Upload Image" << std::endl;
    }

    m_startPosition = startPosition;

    m_rope.setSize(sf::Vector2f(width, height));
    m_rope.setFillColor(sf::Color::White);
    m_rope.setPosition(startPosition);
    m_rope.setTexture(&texture);
    m_rope.setScale(2.f, 1.f);

    m_finalPosition = sf::Vector2f(m_startPosition.x, m_startPosition.y + height);
    m_length = height;

    ball = new Ball(30.f, m_finalPosition);

    sphere.setPosition(sf::Vector2f(spherePosition));
    sphere.setRadius(5.f);
    sphere.setFillColor(sf::Color::White);


};

void Rope::draw(sf::RenderWindow& window)
{
    window.draw(m_rope);
    window.draw(sphere);
    ball->draw(window);
}

void Rope::update()
{
    sf::Time time = clock.getElapsedTime();
    deltaTime = time.asSeconds() + 90;

    //Time-based angle * velocity multiplier
    m_angle = deltaTime * 600.f;


    //Invert rotation
    m_rope.setRotation(-m_angle);

    //Get position of the end of the rope.
    sf::Transform transform = m_rope.getTransform();
    sf::Vector2f endPosition = transform.transformPoint(m_rope.getSize());

    //Adjust the position of the ball to align its center with the end of the rope
    sf::Vector2f ballPosition = endPosition - sf::Vector2f(ball->m_ball.getRadius(), ball->m_ball.getRadius());

    if (ball->getBallEscaped()) {
        ball->ballEscape(ball->getVelocity(), ball->m_ball.getPosition());
    }
    else {
        ball->update(ballPosition);
        ball->setVelocity(m_angle);
    }

    if (ball->outOfBounds())
    {
        restartBall();
    }

}

sf::Vector2f Rope::getFinalPosition() {
    return m_finalPosition;
}

void Rope::restartBall()
{
    //Set ball back to the rope
    ball->m_ball.setPosition(getFinalPosition());
    ball->setVelocity(m_angle);
    ball->setBallEscaped(false);
    ball->setGravity(-0.2f);

    //Make sure to set the keyboard to false so the sound does not bug.
    ball->setKeyboardPressed(false);
}

void Rope::setNewPosition(sf::Vector2f position)
{
    m_startPosition = position;
    m_rope.setPosition(m_startPosition);
    m_finalPosition = sf::Vector2f(m_startPosition.x, m_startPosition.y + m_length);
}

void Rope::setSpherePosition(sf::Vector2f position)
{
    sphere.setPosition(position);
}