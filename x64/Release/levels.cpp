#include "levels.h"
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

bool transitionComplete = true;
bool tempBallStatus = true;

bool level(sf::RenderWindow& window)
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


    if (goal.checkIfScored(rope.ball) && tempBallStatus)
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
    if (transitionComplete)
    {
        rope.restartBall();

        //New Obstacles
        obstacles[0].setNewPosition(sf::Vector2f(640.f, 360.f));

        rope.ball->setBallEscaped(false);
        rope.ball->setBallStatus(false);

        text1.setReset(true);
        text2.setReset(true);

        tempBallStatus = true;
        transitionComplete = false;

        text1.resetTransition();

        text2.resetTransition();
        text2.changeText("LEVEL THREE");
    }



}

void loadLevelThree(sf::RenderWindow& window)
{
    if (transitionComplete)
    {
        rope.restartBall();

        //New Obstacles
        obstacles[0].setNewPosition(sf::Vector2f(640.f, 0.f));
        obstacles[1].setNewPosition(sf::Vector2f(640.f, 400.f));
        obstacles[1].setSize(sf::Vector2f(10.f, 400.f));

        rope.ball->setBallEscaped(false);
        rope.ball->setBallStatus(false);

        text1.setReset(true);
        text2.setReset(true);

        tempBallStatus = true;
        transitionComplete = false;

        text1.resetTransition();

        text2.resetTransition();
        text2.changeText("LEVEL FOUR");
    }



}

void loadLevelFour(sf::RenderWindow& window)
{
    if (transitionComplete)
    {
        rope.restartBall();

        //New Obstacles
        obstacles[0].setNewPosition(sf::Vector2f(640.f, 0.f));
        obstacles[1].setNewPosition(sf::Vector2f(640.f, 300.f));
        obstacles[1].setSize(sf::Vector2f(10.f, 600.f));

        rope.ball->setBallEscaped(false);
        rope.ball->setBallStatus(false);

        text1.setReset(true);
        text2.setReset(true);

        tempBallStatus = true;
        transitionComplete = false;

        text1.resetTransition();

        text2.resetTransition();
        text2.changeText("LEVEL FIVE");
    }



}

bool transition(sf::RenderWindow& window)
{
    std::cout << text1.getReset() << std::endl;
    if (text1.getReset())
    {
        text1.resetClock();
    }

    if (text1.moveText())
    {
        if (text2.getReset())
        {
            text2.resetClock();
        }

        if (text2.getReset())
        {
            text2.resetClock();
        }
        if (text2.moveText())
        {
            tempBallStatus = false;
            transitionComplete = true;
            return true;
        }
        else
        {
            text2.draw(window);
            return false;
        }
    }
    else
    {   
        text1.draw(window);
        return false;
    }
}

bool getCompleteStatus()
{
    return tempBallStatus;
}