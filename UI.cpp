#include "UI.hpp"
#include "LanderGame.hpp"

UI::UI(unsigned int fGameWidth, unsigned int fGameHeight)
{
	maxImpactX = 0.015f;
	maxImpactY = 0.1f;
	maxRotation = 3.f;

	startGameMsg.create(" Lander! \n Press \"enter\" to start the game", 35, fGameWidth / 4, fGameHeight / 50, sf::Color::White);
	endGameMsg.create("", 35, fGameWidth / 3, fGameHeight / 6, sf::Color::White);

	XVelocityText.create("", 20, 10.f, fGameHeight - 25, sf::Color::White);
	YVelocityText.create("", 20, 110.f, fGameHeight - 25, sf::Color::White);
	RotationText.create("", 20, 210.f, fGameHeight - 25, sf::Color::White);

	displayNumberMultyplier = 1000;


	// X Velocity Main Bar size and pos
	velocityRectagleSize = sf::Vector2f(fGameHeight / 2.f, fGameHeight / 120.f);
	velocityRectaglePosition = sf::Vector2f(fGameHeight * 0.05f, fGameHeight * 0.90f);

	// X Middle Mark Size and Position
	velocityRectagleMiddleSize = sf::Vector2f(fGameHeight / 150.f, fGameHeight / 70.f);
	velocityRectagleMiddlePosition = sf::Vector2f(velocityRectaglePosition.x + velocityRectagleSize.x / 2.f,
													velocityRectaglePosition.y - velocityRectagleMiddleSize.x / 2.f);
	
	// X Pointer Size and Position
	velocityPointerSize = sf::Vector2f(fGameHeight / 150.f, fGameHeight / 55.f);
	velocityPointerPosition = velocityRectagleMiddlePosition;

	

	initializeRectangles(fGameWidth,fGameHeight);
	

}

void UI::calculateUI(Lander fLander, sf::Vector2f movementVec)
{
	temp = movementVec.x * displayNumberMultyplier;
	XVelocityText.chageTxt(_itoa(temp, buffer, 10));

	temp = movementVec.y * displayNumberMultyplier;
	YVelocityText.chageTxt(_itoa(temp, buffer, 10));

	temp = fLander.getRotation();
	RotationText.chageTxt(_itoa(temp, buffer, 10));


	if (movementVec.x * 10 > velocityRectagleSize.x / 2.f)
	{
		XVelocityPointer.setFillColor(sf::Color::Red);
		XVelocityPointer.setPosition(velocityRectaglePosition + sf::Vector2f(0, velocityRectagleSize.y));
	}
	else if (movementVec.x * 10.f < velocityRectagleSize.x / -2.f)
	{
		XVelocityPointer.setFillColor(sf::Color::Red);
		XVelocityPointer.setPosition(velocityRectaglePosition);
	}
	else 
	{
		if ( movementVec.x < maxImpactX && movementVec.x > maxImpactX * (-1) )
		{
			XVelocityPointer.setFillColor(sf::Color::Green);
		}
		else
		{
			XVelocityPointer.setFillColor(sf::Color::Red);
		}

		XVelocityPointer.setPosition(XVelocityPointer.getPosition() + sf::Vector2f(movementVec.x * 10.f, 0.f));

	}
}


void UI::initializeRectangles(unsigned int fGameWidth, unsigned int fGameHeight)
{
	// X Velocity Strip Body
	XVelocityRectagle.setFillColor(sf::Color::White);
	XVelocityRectagle.setOutlineThickness(fGameHeight / -700.f);
	XVelocityRectagle.setOutlineColor(sf::Color::Black);
	// X Velocity Strip Size and Position
	XVelocityRectagle.setSize(velocityRectagleSize);
	XVelocityRectagle.setPosition(velocityRectaglePosition);

	// X Velocity Pointer
	XVelocityPointer.setFillColor(sf::Color::Green);
	XVelocityPointer.setOutlineThickness(fGameHeight / -1000.f);
	XVelocityPointer.setOutlineColor(sf::Color::Black);
	// X Velocity Pointer Size and Position
	XVelocityPointer.setSize(velocityPointerSize);
	XVelocityPointer.setPosition(velocityPointerPosition);

	// X Middle Mark
	XVelocityRectagleMiddle.setFillColor(sf::Color::Black);
	XVelocityRectagleMiddle.setOutlineThickness(fGameHeight / -1000.f);
	XVelocityRectagleMiddle.setOutlineColor(sf::Color::Black);
	// X Middle Mark Size and Position
	XVelocityRectagleMiddle.setSize(velocityRectagleMiddleSize);
	XVelocityRectagleMiddle.setPosition(velocityRectagleMiddlePosition);

}
