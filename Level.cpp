#include "Level.hpp"

Level::Level()
{
	fLevelGravity = 9.8;
}

sf::Sprite Level::getSprite()
{
	return fTerrainSprite;
}

sf::Texture Level::getTexure()
{
	return fTerrainTexure;
}

void Level::setSpritePosition(int X, int Y)
{
	fTerrainSprite.setPosition(X, Y);
}
