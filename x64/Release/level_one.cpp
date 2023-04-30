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

TextTransition text1("You Completed The Level", sf::Vector2f(-700.f, 100), 32);

//TODO create a function level2 where set all the objetos in new positions/sizes
// then update goalScored to false and call this function on main.cpp

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
        return true;
    }
    else
    {
        return false;
    }
}


bool applyTransition(sf::RenderWindow& window)
{
    if (text1.moveText())
    {
        return true;
    }
    else {
        text1.draw(window);
        return false;
    }
}

void loadLevelTwo(sf::RenderWindow& window)
{   
    if (rope.ball->getBallScored())
    {
        sf::Vector2f ropeStartPosition(300.f, 300.f);
        sf::Vector2f spherePosition = ropeStartPosition + sf::Vector2f(-5.f, -3.f);

        std::cout << "Dentro da funcao leveltwo" << std::endl;
        rope.setNewPosition(ropeStartPosition);
        rope.setSpherePosition(spherePosition);
        rope.restartBall();

        rope.ball->setBallEscaped(false);
        rope.ball->setBallStatus(false);
    }


}