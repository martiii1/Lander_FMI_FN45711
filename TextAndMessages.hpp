#pragma once
#include <SFML/Graphics.hpp>

class TextAndMessages
{
public:
	TextAndMessages();
	TextAndMessages(const char* text, int size, unsigned int positionX, unsigned int positionY, sf::Color color);

	void chageTxt(const char* text);
	void chagePosition(unsigned int positionX, unsigned int positionY);
	void chageSize(int size);
	void changeColor(sf::Color newColor);
	
	void create(const char* text, int size, unsigned int positionX, unsigned int positionY, sf::Color color);
	
	sf::Text getText();

private:
	sf::Text fTextMsg;
	sf::Font fFont;
	int fSizeOfText;
	unsigned int fPositionX;
	unsigned int fPositionY;
	sf::Color fTextColor;
	const char* fText;

};

