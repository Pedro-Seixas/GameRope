#pragma once
#include "SFML/Graphics.hpp"
#include "Ball.h"
#include <iostream>
#ifndef OBSTACLE_H
#define OBSTACLE_H

class Ball;

class Obstacle
{
public:
	Obstacle(sf::Vector2f position, float rotation, sf::Vector2f size);
	void draw(sf::RenderWindow& window);
	sf::RectangleShape getObstacle() const { return m_obstacle; }
	void ballHitObstacle(Ball* ball);
	void setNewPosition(sf::Vector2f position);
	void setSize(sf::Vector2f size);
	void obstacleEnable(bool status);

private:
	sf::RectangleShape m_obstacle;
	sf::Vector2f m_position;


};

#endif

