#include "level_one.h"
#include "TextTransition.h"

sf::Vector2f ropeStartPosition(150, 300);
sf::Vector2f goalStartPosition(1000, 360);
sf::Vector2f goalSize(200.f, 200.f);

sf::Vector2f spherePosition = ropeStartPosition + sf::Vector2f(-5.f, -3.f); //Account for rope width

//Rope object
float ropeLength = 150.f;

Goal goal(goalStartPosition, goalSize);

Rope rope(ropeStartPosition, 3.f, ropeLength, spherePosition);

Obstacle obstacle1(sf::Vector2f(640.f, 360.f), 0.f, sf::Vector2f(10.f, 200.f));

TextTransition text1("You completed the First Level!", sf::Vector2f(-700.f, 100));


bool levelOne(sf::RenderWindow& window)
{

    goal.checkIfScored(rope.ball);

    rope.update();

    window.clear();

    goal.draw(window);

    obstacle1.ballHitObstacle(rope.ball);

    obstacle1.draw(window);

    rope.draw(window);

    if (goal.checkIfScored(rope.ball))
    {
        applyTransition(window);
        return true;
    }
    else
    {
        return false;
    }
}

void applyTransition(sf::RenderWindow& window)
{
    text1.moveText();
    text1.draw(window);
}