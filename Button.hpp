#pragma once
#include <SFML/Graphics.hpp>

class Button
{

public:
	Button(const char* notPressedImage,const char* pressedImage, unsigned int positionX, unsigned int positionY);

	bool isClicked();

private:
	sf::Texture notPressedTexure;
	sf::Texture pressedTexure;
	sf::Sprite notPressedButtonSprite;
	sf::Sprite pressedButtonSprite;
	bool isPressed;

};

