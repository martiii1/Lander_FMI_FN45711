#pragma once
#include <SFML/Graphics.hpp>

class TextAndMessages
{
public:
	TextAndMessages();
	TextAndMessages(char* text, int size, unsigned int positionX, unsigned int positionY, sf::Color color);

	void chageTxt(char* text);
	void chagePosition(unsigned int positionX, unsigned int positionY);
	void chageSize(int size);
	


	sf::Text getText();

private:
	sf::Text fTextMsg;
	sf::Font fFont;
	int fSizeOfText;
	unsigned int fPositionX;
	unsigned int fPositionY;
	sf::Color fTextColor;
	char* fText;

};

