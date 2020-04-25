#pragma once

#include <SFML/Graphics.hpp>
#include "Lander.hpp"
#include "Level.hpp"
#include "TextAndMessages.hpp"


class LanderGame
{
public:
	LanderGame();

	void startGame();

private:
	unsigned int gameWidth;
	unsigned int gameHeight;

	Lander fLander;
	Level fCurrentLevel;

};

