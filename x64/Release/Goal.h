#pragma once
#include "SFML/Graphics.hpp"
#include "Ball.h"
#include <iostream>
#ifndef GOAL_H
#define GOAL_H

class Goal
{
public:
    Goal(sf::Vector2f position, sf::Vector2f size);
    void draw(sf::RenderWindow& window);
    sf::RectangleShape m_goal;
    bool checkIfScored(Ball* ball);
    void setNewPosition(sf::Vector2f position);
    void setSize(sf::Vector2f size);

private:
    sf::Vector2f m_position;
    sf::Sound sound;
    sf::SoundBuffer buffer;
    bool playOnce = true;

};

#endif