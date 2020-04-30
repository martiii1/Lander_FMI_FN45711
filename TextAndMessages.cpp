#include "TextAndMessages.hpp"
#include "LanderGame.hpp"

TextAndMessages::TextAndMessages()
{

	fSizeOfText = 15;
	fPositionX = 0;
	fPositionY = 20;
	fTextColor = sf::Color::White;
	fText = nullptr;

	if (!fFont.loadFromFile("images/Arial.ttf"))
		return;

	fTextMsg.setFont(fFont);
	fTextMsg.setCharacterSize(fSizeOfText);
	fTextMsg.setPosition(fPositionX, fPositionY);
	fTextMsg.setFillColor(fTextColor);
	fTextMsg.setString(fText);
}

TextAndMessages::TextAndMessages(const char* text, int size, unsigned int positionX, unsigned int positionY, sf::Color color)
{
	fSizeOfText = size;
	fPositionX = positionX;
	fPositionY = positionY;
	fTextColor = color;
	fText = text;

	if (!fFont.loadFromFile("images/Arial.ttf"))
		return;

	fTextMsg.setFont(fFont);
	fTextMsg.setCharacterSize(fSizeOfText);
	fTextMsg.setPosition(fPositionX, fPositionY);
	fTextMsg.setFillColor(fTextColor);
	fTextMsg.setString(fText);

}


void TextAndMessages::chageTxt(const char* text)
{
	fTextMsg.setString(text);
}

void TextAndMessages::chagePosition(unsigned int positionX, unsigned int positionY)
{
	fPositionX = positionX;
	fPositionY = positionY;
}

void TextAndMessages::chageSize(int size)
{
	fTextMsg.setCharacterSize(size);
}

void TextAndMessages::changeColor(sf::Color newColor)
{
	fTextMsg.setFillColor(newColor);
}

sf::Text TextAndMessages::getText()
{
	return fTextMsg;
}
