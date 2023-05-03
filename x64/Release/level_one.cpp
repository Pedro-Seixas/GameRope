#include "level_one.h"
#include "TextTransition.h"

sf::Vector2f ropeStartPosition(150, 300);
sf::Vector2f goalStartPosition(1000, 160);
sf::Vector2f goalSize(200.f, 400.f);

sf::Vector2f spherePosition = ropeStartPosition + sf::Vector2f(-5.f, -3.f); //Account for rope width

//Rope object
float ropeLength = 150.f;

Goal goal(goalStartPosition, goalSize);

Rope rope(ropeStartPosition, 3.f, ropeLength, spherePosition);

Obstacle obstacles[5] = { Obstacle(sf::Vector2f(5000.f, 5000.f), 0.f, sf::Vector2f(10.f, 200.f)), Obstacle(sf::Vector2f(5000.f, 5000.f), 0.f, sf::Vector2f(10.f, 200.f)),
Obstacle(sf::Vector2f(5000.f, 5000.f), 0.f, sf::Vector2f(10.f, 200.f)), Obstacle(sf::Vector2f(5000.f, 5000.f), 0.f, sf::Vector2f(10.f, 200.f)),
Obstacle(sf::Vector2f(5000.f, 5000.f), 0.f, sf::Vector2f(10.f, 200.f)) };

TextTransition text1("YOU COMPLETED THE LEVEL", sf::Vector2f(-700.f, 100), 32);
TextTransition text2("LEVEL TWO", sf::Vector2f(-700.f, 100), 42);


bool applyTransitionEnd(sf::RenderWindow& window)
{
    if (text1.getReset())
    {
        text1.resetClock();
    }

    if (text1.moveText())
    {
        text1.setReset(true);
        return true;
    }
    else {
        text1.draw(window);
        return false;
    }
}


bool applyTransitionStart(TextTransition& text, sf::RenderWindow& window)
{
    if (text.getReset())
    {
        text.resetClock();
    }

    if (text.moveText())
    {
        return true;
    }
    else {
        std::cout << "DRAAAAAAAAW" << std::endl;
        text.draw(window);
        return false;
    }
}

bool levelOne(sf::RenderWindow& window)
{

    goal.checkIfScored(rope.ball);

    rope.update();

    window.clear(sf::Color(32, 32, 32));

    goal.draw(window);
    
    for (int i = 0; i < 5; i++)
    {
        obstacles[i].ballHitObstacle(rope.ball);
        obstacles[i].draw(window);
    }
 

    rope.draw(window);

    text2.draw(window);

    if (goal.checkIfScored(rope.ball))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void loadLevelTwo(sf::RenderWindow& window)
{
    if (rope.ball->getBallScored() && applyTransitionStart(text2, window))
    {
        std::cout << "Dentro da funcao leveltwo" << std::endl;
        rope.restartBall();

        //New Obstacles
        obstacles[0].setNewPosition(sf::Vector2f(640.f, 360.f));

        rope.ball->setBallEscaped(false);
        rope.ball->setBallStatus(false);

    }


}


