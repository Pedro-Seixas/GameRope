#include "level_one.h"

sf::Vector2f ropeStartPosition(150, 300);
sf::Vector2f goalStartPosition(1000, 360);
sf::Vector2f goalSize(200.f, 200.f);

sf::Vector2f spherePosition = ropeStartPosition + sf::Vector2f(-5.f, -5.f); //Account for rope width

//Rope object
float ropeLength = 150.f;

Goal goal(goalStartPosition, goalSize);

Rope rope(ropeStartPosition, 3.f, ropeLength, spherePosition);

Obstacle obstacle1(sf::Vector2f(640.f, 360.f), 0.f, sf::Vector2f(10.f, 200.f));


bool levelOne(sf::RenderWindow& window)
{

    goal.checkIfScored(rope.ball);

    rope.update();

    window.clear();

    goal.draw(window);

    obstacle1.ballHitObstacle(rope.ball);

    obstacle1.draw(window);

    rope.draw(window);

    window.display();

    if (goal.checkIfScored(rope.ball))
    {
        return true;
    }
    else
    {
        return false;
    }
}