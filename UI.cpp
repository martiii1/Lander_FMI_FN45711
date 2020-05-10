#include "UI.hpp"

UI::UI(unsigned int fGameWidth, unsigned int fGameHeight)
{

	startGameMsg.create(" Lander! \n Press \"enter\" to start the game", 35, fGameWidth / 4, fGameHeight / 50, sf::Color::White);
	endGameMsg.create("", 35, fGameWidth / 3, fGameHeight / 6, sf::Color::White);

	XVelocityText.create("", 20, 10.f, fGameHeight - 25, sf::Color::White);
	YVelocityText.create("", 20, 110.f, fGameHeight - 25, sf::Color::White);
	RotationText.create("", 20, 210.f, fGameHeight - 25, sf::Color::White);

	displayNumberMultyplier = 1000;

	// X velocity strip
	XVelocityRectagle.setSize(sf::Vector2f(fGameHeight / 2, fGameHeight / 2));
	XVelocityRectagle.setFillColor(sf::Color::White);
	XVelocityRectagle.setOutlineThickness(fGameHeight / -100.f);
	XVelocityRectagle.setOutlineColor(sf::Color::Black);


	// X Middle mark
	XVelocityRectagleMiddle.setSize(sf::Vector2f(fGameHeight / 100, fGameHeight / 200));
	XVelocityRectagleMiddle.setFillColor(sf::Color::White);
	XVelocityRectagleMiddle.setOutlineThickness(fGameHeight / -100.f);
	XVelocityRectagleMiddle.setOutlineColor(sf::Color::Black);

	// Y velocity strip
	YVelocityRectagle.setSize(sf::Vector2f(fGameHeight / 2, fGameHeight / 2));
	YVelocityRectagle.setFillColor(sf::Color::White);
	YVelocityRectagle.setOutlineThickness(fGameHeight / -100.f);
	YVelocityRectagle.setOutlineColor(sf::Color::Black);




}

void UI::calculateText(Lander fLander, sf::Vector2f movementVec)
{
	temp = movementVec.x * displayNumberMultyplier;
	XVelocityText.chageTxt(_itoa(temp, buffer, 10));

	temp = movementVec.y * displayNumberMultyplier;
	YVelocityText.chageTxt(_itoa(temp, buffer, 10));

	temp = fLander.getRotation();
	RotationText.chageTxt(_itoa(temp, buffer, 10));

}
