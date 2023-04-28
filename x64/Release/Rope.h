#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#ifndef ROPE_H
#define ROPE_H
class Goal;
class Ball;

class Rope
{
public:
    Rope(sf::Vector2f startPosition, float width, float height, sf::Vector2f spherePosition);
    void draw(sf::RenderWindow& window);
    void update();
    sf::Vector2f getFinalPosition();
    sf::Transform transform = m_rope.getTransform();
    void createNewBall();
    float getTime() const { return deltaTime; }
    void restartBall();
    Ball* ball;
    sf::CircleShape sphere;

private:
    sf::RectangleShape m_rope;
    sf::Vector2f m_finalPosition;
    sf::Vector2f m_startPosition;
    sf::Texture texture;
    float m_angle;
    float m_length;
    float deltaTime;
    sf::Clock clock;
};


#endif