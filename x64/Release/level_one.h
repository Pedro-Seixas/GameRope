#pragma once
#ifndef LEVEL_ONE_H
#define LEVEL_ONE_H

#include "SFML/Graphics.hpp"
#include "Ball.h"
#include "Rope.h"
#include "Goal.h"
#include "Obstacle.h"

bool levelOne(sf::RenderWindow& window);
bool applyTransition(sf::RenderWindow& window);
void loadLevelTwo(sf::RenderWindow& window);

#endif