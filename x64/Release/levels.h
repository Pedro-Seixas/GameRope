#pragma once
#ifndef LEVELS_H
#define LEVELS_H

#include "SFML/Graphics.hpp"
#include "Ball.h"
#include "Rope.h"
#include "Goal.h"
#include "Obstacle.h"
#include "TextTransition.h"

bool level(sf::RenderWindow& window);
void loadLevelTwo(sf::RenderWindow& window);
void loadLevelThree(sf::RenderWindow& window);
void loadLevelFour(sf::RenderWindow& window);
void loadLevelFive(sf::RenderWindow& window);
bool transition(sf::RenderWindow& window);
bool getCompleteStatus();

#endif