#pragma once

#include <SFML/Graphics.hpp>
#include "Lander.hpp"
#include "Level.hpp"
#include "TextAndMessages.hpp"


class LanderGame
{
public:
	LanderGame();
	LanderGame(unsigned int gameWidth, unsigned int gameHeight);

	void startGame();


	unsigned int getWidth();
	unsigned int getHeight();

private:
	unsigned int fGameWidth;
	unsigned int fGameHeight;

	Lander fLander;
	Level fCurrentLevel;

	bool detectColision(Lander& lander, Level& map);
	float triangleArea(sf::Vector2f &point1, sf::Vector2f &point2, sf::Vector2f &point3);
	bool pointInTriangle(sf::Vector2f& point, sf::Vector2f& triangleA, sf::Vector2f& triangleB, sf::Vector2f& triagleC);

};

