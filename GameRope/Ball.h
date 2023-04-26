#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Obstacle.h"
#ifndef BALL_H
#define BALL_H

class Ball
{
public:
    Ball(float radius, sf::Vector2f position);
    void draw(sf::RenderWindow& window);
    void update(sf::Vector2f newPosition);
    sf::CircleShape m_ball;
    void setVelocity(float angle);
    sf::Vector2f getVelocity() const { return m_velocity; }
    void ballEscape(sf::Vector2f velocity, sf::Vector2f position);
    void scoredGoal();
    bool getBallScored() const { return ballScored; }
    bool getBallEscaped() const { return ballEscaped; }
    void setBallStatus();
    void invertVelocity();
    bool outOfBounds();

private:
    float m_gravity;
    sf::Vector2f m_velocity;
    bool ballScored;
    bool ballEscaped;
};

#endif