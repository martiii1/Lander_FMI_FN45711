#include "Button.hpp"


Button::Button(const char* notPressedImage, const char* pressedImage, float positionX, float positionY)
{
	if (!fNotPressedTexure.loadFromFile(notPressedImage))
	{
		//handle error!
	}

	if (!fPressedTexure.loadFromFile(pressedImage))
	{
		//handle error!
	}

	fSpriteSizeX = fNotPressedTexure.getSize().x;
	fSpriteSizeY = fNotPressedTexure.getSize().y;


	fNotPressedButtonSprite.setTexture(fNotPressedTexure);
	fPressedButtonSprite.setTexture(fPressedTexure);

	fPositionX = positionX;
	fPositionY = positionY;

}

void Button::setPos()
{
	fPressedButtonSprite.setPosition(fPositionX, fPositionY);
	fNotPressedButtonSprite.setPosition(fPositionX, fPositionY);
}

sf::Sprite Button::getSprite()
{
	return fSpriteForReturn;
}

bool Button::isClicked(float mouseX,float mouseY, bool click)
{
	if (mouseX > fPositionX &&
		mouseX < fPositionX + fSpriteSizeX &&
		mouseY > fPositionY &&
		mouseY < fPositionY + fSpriteSizeY &&
		click)
	{
		fSpriteForReturn = fPressedButtonSprite;
		return true;
	}
	else
	{
		fSpriteForReturn = fNotPressedButtonSprite;
		return false;
	}

	
}
