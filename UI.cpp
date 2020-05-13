#include "UI.hpp"
#include "LanderGame.hpp"

UI::UI(unsigned int fGameWidth, unsigned int fGameHeight)
{
	maxImpactX = 0.015f; // add settings class
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
	
	velocityPointerSize = sf::Vector2f(fGameHeight / 150.f, fGameHeight / 55.f);

	// X Pointer Position
	XvelocityPointerPosition = velocityRectagleMiddlePosition;

	// Y Pointer Position
	YvelocityPointerPosition = sf::Vector2f(velocityRectaglePosition.x - velocityRectagleMiddleSize.x / 2,
											velocityRectaglePosition.y - velocityRectagleSize.x / 2.f);

	

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

	XVelDriver(movementVec.x);
	YVelDriver(movementVec.y);



}


void UI::XVelDriver(float movementVecX)
{

	if (XvelocityPointerPosition.x + movementVecX * 100.f > velocityRectaglePosition.x + velocityRectagleSize.x)
	{
		XVelocityPointer.setFillColor(sf::Color::Red);
		XVelocityPointer.setPosition(XvelocityPointerPosition + sf::Vector2f(velocityRectagleSize.x / 2.f, 0.f));
	}
	else if (XvelocityPointerPosition.x + movementVecX * 100.f < velocityRectaglePosition.x)
	{
		XVelocityPointer.setFillColor(sf::Color::Red);
		XVelocityPointer.setPosition(XvelocityPointerPosition - sf::Vector2f(velocityRectagleSize.x / 2.f, 0.f));
	}
	else
	{
		if (movementVecX < maxImpactX && movementVecX > maxImpactX* (-1))
		{
			XVelocityPointer.setFillColor(sf::Color::Green);
		}
		else
		{
			XVelocityPointer.setFillColor(sf::Color::Red);
		}

		XVelocityPointer.setPosition(sf::Vector2f(XvelocityPointerPosition.x + movementVecX * 100.f, XvelocityPointerPosition.y));

	}
}

void UI::YVelDriver(float movementVecY)
{
	if (YvelocityPointerPosition.y + movementVecY * 100.f < velocityRectaglePosition.y - velocityRectagleSize.x)
	{
		YVelocityPointer.setFillColor(sf::Color::Red);
		YVelocityPointer.setPosition(YvelocityPointerPosition - sf::Vector2f(0.f, velocityRectagleSize.x / 2.f));
	}
	else if (YvelocityPointerPosition.y + movementVecY * 100.f > velocityRectaglePosition.y)
	{
		YVelocityPointer.setFillColor(sf::Color::Red);
		YVelocityPointer.setPosition(YvelocityPointerPosition + sf::Vector2f(0.f, velocityRectagleSize.x / 2.f));
	}
	else
	{
		if (movementVecY < maxImpactY)
		{
			YVelocityPointer.setFillColor(sf::Color::Green);
		}
		else
		{
			YVelocityPointer.setFillColor(sf::Color::Red);
		}

		YVelocityPointer.setPosition(sf::Vector2f(YvelocityPointerPosition.x, YvelocityPointerPosition.y + movementVecY * 100.f));

	}
}

void UI::initializeRectangles(unsigned int fGameWidth, unsigned int fGameHeight)
{
	//                   X TRACKER 

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
	XVelocityPointer.setPosition(XvelocityPointerPosition);

	// X Middle Mark
	XVelocityRectagleMiddle.setFillColor(sf::Color::Black);
	XVelocityRectagleMiddle.setOutlineThickness(fGameHeight / -1000.f);
	XVelocityRectagleMiddle.setOutlineColor(sf::Color::Black);
	// X Middle Mark Size and Position
	XVelocityRectagleMiddle.setSize(velocityRectagleMiddleSize);
	XVelocityRectagleMiddle.setPosition(velocityRectagleMiddlePosition);


	//                   Y TRACKER 

	// Y Velocity Strip Body
	YVelocityRectagle.setFillColor(sf::Color::White);
	YVelocityRectagle.setOutlineThickness(fGameHeight / -700.f);
	YVelocityRectagle.setOutlineColor(sf::Color::Black);
	// Y Velocity Strip Size and Position
	YVelocityRectagle.setSize(sf::Vector2f(velocityRectagleSize.y, velocityRectagleSize.x));
	YVelocityRectagle.setPosition(sf::Vector2f(velocityRectaglePosition.x, velocityRectaglePosition.y - velocityRectagleSize.x));

	// Y Velocity Pointer
	YVelocityPointer.setFillColor(sf::Color::Green);
	YVelocityPointer.setOutlineThickness(fGameHeight / -1000.f);
	YVelocityPointer.setOutlineColor(sf::Color::Black);
	// Y Velocity Pointer Size and Position
	YVelocityPointer.setSize(sf::Vector2f(velocityPointerSize.y, velocityPointerSize.x));
	YVelocityPointer.setPosition(sf::Vector2f(velocityRectaglePosition.x - velocityRectagleMiddleSize.x / 2,
												velocityRectaglePosition.y - velocityRectagleSize.x / 2.f));

	// Y Middle Mark
	YVelocityRectagleMiddle.setFillColor(sf::Color::Black);
	YVelocityRectagleMiddle.setOutlineThickness(fGameHeight / -1000.f);
	YVelocityRectagleMiddle.setOutlineColor(sf::Color::Black);
	// Y Middle Mark Size and Position
	YVelocityRectagleMiddle.setSize(sf::Vector2f(velocityRectagleMiddleSize.y, velocityRectagleMiddleSize.x));
	YVelocityRectagleMiddle.setPosition(sf::Vector2f(velocityRectaglePosition.x - velocityRectagleMiddleSize.x / 2,
														velocityRectaglePosition.y - velocityRectagleSize.x / 2.f ));
}
