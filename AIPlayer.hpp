#pragma once
#include "Lander.hpp"
#include "SFML/Graphics.hpp"
class AIPlayer
{
public:
	AIPlayer();

	bool isRunning;
	bool left;
	bool right;
	bool up;
	
	void calcNextMove(Lander& lander, sf::Vector2f& movementVec);

private:

	int tempRot;
	float distanceBeforeStop;

};

