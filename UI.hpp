#pragma once
#include "TextAndMessages.hpp"
#include "Lander.hpp"
#include <string>

class UI
{
public:
	UI(unsigned int fGameWidth, unsigned int fGameHeight);
	void calculateUI(Lander fLander, sf::Vector2f movementVec);

	TextAndMessages startGameMsg;
	TextAndMessages endGameMsg;

	TextAndMessages XVelocityText;
	TextAndMessages YVelocityText;
	TextAndMessages RotationText;

protected:
	sf::RectangleShape XVelocityRectagle;
	sf::RectangleShape XVelocityRectagleMiddle;
	sf::RectangleShape XVelocityPointer;

private:
	int temp;
	char buffer[15];
	int displayNumberMultyplier;
	// game settings
	float maxImpactX;
	float maxImpactY;
	float maxRotation;


	
	sf::Vector2f velocityRectagleSize;
	sf::Vector2f velocityRectaglePosition;

	
	sf::Vector2f velocityRectagleMiddleSize;
	sf::Vector2f velocityRectagleMiddlePosition;


	sf::Vector2f velocityPointerSize;
	sf::Vector2f velocityPointerPosition;


	sf::RectangleShape YVelocityRectagle;
	sf::RectangleShape YVelocityRectagleMiddle;

	sf::RectangleShape YVelocityPointer;

	void initializeRectangles(unsigned int fGameWidth, unsigned int fGameHeight);

};

