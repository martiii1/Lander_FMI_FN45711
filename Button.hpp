#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>

class Button
{

public:
	Button();
	Button(const char* notPressedImage,const char* pressedImage, float positionX, float positionY);
	
	void create(const char* notPressedImage, const char* pressedImage, float positionX, float positionY);
	void setPos();

	sf::Sprite getSprite();
	bool isClicked(float mouseX, float mouseY, bool click);

private:
	sf::Texture fNotPressedTexure;
	sf::Texture fPressedTexure;
	sf::Sprite fSpriteForReturn;
	sf::Sprite fNotPressedButtonSprite;
	sf::Sprite fPressedButtonSprite;

	float fPositionX, fPositionY;
	float fSpriteSizeX, fSpriteSizeY;


};

