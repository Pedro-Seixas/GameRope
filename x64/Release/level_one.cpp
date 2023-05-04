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
bool transitionComplete = true;
bool tempBallStatus = true;
//Temp variable to store to goal status in order to be able to reset the goal and the logic still work as the ball was in the goal
//bool tempScore = true;
//bool endTransitionEnded = true;

//bool applyTransitionEnd(sf::RenderWindow& window)
//{
//    if (text1.getReset())
//    {
//        text1.resetClock();
//    }
//    if (!text1.getResetPosition())
//    {
//        text1.resetTransition();
//    }
//    if (text1.moveText())
//    {
//        std::cout << "Entrou move text" << std::endl;
//        std::cout << "END TRANSITION ENDED ______________________" << std::endl;
//        tempScore = false;
//        text1.setReset(true);
//        endTransitionEnded = true;
//        return true;
//    }
//    else {
//        text1.draw(window);
//        return false;
//    }
//}
//
//
//bool applyTransitionStart(TextTransition& text, sf::RenderWindow& window)
//{
    //if (text.getReset())
    //{
    //    text.resetClock();
    //}
//
//    if (!text.getResetPosition())
//    {
//        text.resetTransition();
//    }
//
//    if (endTransitionEnded)
//    {
//        if (text.moveText())
//        {
//            std::cout << "Entrou move text" << std::endl;
//            endTransitionEnded = false;
//            tempScore = false;
//            return true;
//        }
//        else 
//        {
//            text.draw(window);
//            return false;
//        }
//    }
//
//}

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
        std::cout << "Dentro da funcao leveltwo" << std::endl;
        rope.restartBall();

        //New Obstacles
        obstacles[0].setNewPosition(sf::Vector2f(640.f, 360.f));

        rope.ball->setBallEscaped(false);
        rope.ball->setBallStatus(false);
        transitionComplete = false;
        text1.setReset(true);
        tempBallStatus = true;
        text1.resetTransition();
    }



}

void loadLevelThree(sf::RenderWindow& window)
{
    if (transitionComplete)
    {
        std::cout << "Dentro da funcao leveltwo" << std::endl;
        rope.restartBall();

        //New Obstacles
        obstacles[0].setNewPosition(sf::Vector2f(740.f, 360.f));
        obstacles[1].setNewPosition(sf::Vector2f(640.f, 360.f));

        rope.ball->setBallEscaped(false);
        rope.ball->setBallStatus(false);
        text1.setReset(true);
        transitionComplete = false;
    }



}

bool transition(sf::RenderWindow& window, TextTransition& text)
{
    std::cout << text1.getReset() << std::endl;
    if (text1.getReset())
    {
        std::cout << "-----------------------------------------------------------" << std::endl;
        text1.resetClock();
    }

    if (text1.moveText())
    {
        if (text.getReset())
        {
            text.resetClock();
        }
        if (text.moveText())
        {
            tempBallStatus = false;
            transitionComplete = true;
            return true;
        }
        else
        {
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