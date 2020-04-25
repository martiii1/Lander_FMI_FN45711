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

};

