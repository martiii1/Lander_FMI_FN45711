#include "TextAndMessages.hpp"
#include "LanderGame.hpp"

TextAndMessages::TextAndMessages()
{
	if (!fFont.loadFromFile("images/Arial.ttf"))
		return;

	fSizeOfText = 15;
	fPositionX = 0;
	fPositionY = 20;
	fTextColor = sf::Color::White;
	fText = nullptr;

	fTextMsg.setFont(fFont);
	fTextMsg.setCharacterSize(fSizeOfText);
	fTextMsg.setPosition(fPositionX, fPositionY);
	fTextMsg.setFillColor(fTextColor);
	fTextMsg.setString(fText);
}

TextAndMessages::TextAndMessages(char* text, int size, unsigned int positionX, unsigned int positionY, sf::Color color)
{
	if (!fFont.loadFromFile("images/Arial.ttf"))
		return;

	fSizeOfText = size;
	fPositionX = positionX;
	fPositionY = positionY;
	fTextColor = color;
	fText = text;

	fTextMsg.setFont(fFont);
	fTextMsg.setCharacterSize(fSizeOfText);
	fTextMsg.setPosition(fPositionX, fPositionY);
	fTextMsg.setFillColor(fTextColor);
	fTextMsg.setString(fText);

}

void TextAndMessages::chageTxt(char* text)
{
	fText = text;
}

void TextAndMessages::chagePosition(unsigned int positionX, unsigned int positionY)
{
	fPositionX = positionX;
	fPositionY = positionY;
}

void TextAndMessages::chageSize(int size)
{
	fSizeOfText = size;
}

sf::Text TextAndMessages::getText()
{
	return fTextMsg;
}
