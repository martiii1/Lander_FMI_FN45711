#include "Button.hpp"

Button::Button(const char* notPressedImage, const char* pressedImage, unsigned int positionX, unsigned int positionY)
{
	if (!notPressedTexure.loadFromFile("images/button1.png"))
	{
		//handle error!
	}

	if (!pressedTexure.loadFromFile("images/button1P.png"))
	{
		//handle error!
	}

	notPressedButtonSprite.setTexture(notPressedTexure);
	pressedButtonSprite.setTexture(pressedTexure);

}
