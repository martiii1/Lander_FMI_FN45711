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
	float maxImpactY; // add a settings class

	int tempRot;
	float fXSpeed;
	float fYspeed;
	float distanceBeforeStop;
	float distanceToGround;

	bool stopSidewaysMotion();

	void turnStraightUp();

	bool stopLeftMotion();
	bool stopRightMotion();

	void finalBurn(sf::Vector2f& movementVec);

};

