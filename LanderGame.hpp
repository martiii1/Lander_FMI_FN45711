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

	bool detectColision(const sf::Vector2f& landerUpLeftPos, const Level& map, const sf::Vector2f& texureSize);
	float triangleArea(const sf::Vector2f& point1, const sf::Vector2f& point2, const sf::Vector2f& point3);
	bool pointInTriangle(const sf::Vector2f& point, const sf::Vector2f& triangleA, const sf::Vector2f& triangleB, const sf::Vector2f& triangleC);

};

