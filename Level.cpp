#include "Level.hpp"

Level::Level()
{
	fLevelGravity = 9.8;
}

Level::Level(unsigned int gameWidth, unsigned int gameHeight)
{
	fLevelGravity = 9.8;
	fGameWidth = gameWidth;
	fGameHeight = gameHeight;
}


sf::Texture Level::getTexure()
{
	return fTerrainTexure;
}
