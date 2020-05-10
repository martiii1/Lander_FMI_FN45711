#pragma once
#include "TextAndMessages.hpp"
#include "Lander.hpp"
#include <string>

class UI
{
public:
	UI(unsigned int fGameWidth, unsigned int fGameHeight);
	void calculateText(Lander fLander, sf::Vector2f movementVec);

	TextAndMessages startGameMsg;
	TextAndMessages endGameMsg;

	TextAndMessages XVelocityText;
	TextAndMessages YVelocityText;
	TextAndMessages RotationText;

private:
	int temp;
	char buffer[15];
	int displayNumberMultyplier;

	sf::RectangleShape XVelocityRectagle;
	sf::RectangleShape XVelocityRectagleMiddle;

	sf::RectangleShape YVelocityRectagle;
	sf::RectangleShape YVelocityRectagleMiddle;

	sf::RectangleShape XVelocityPointer;
	sf::RectangleShape YVelocityPointer;

};

