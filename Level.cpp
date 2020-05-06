#include "Level.hpp"


Level::Level(unsigned int levelWidth, unsigned int levelHeight, float triangleWidth) : Terrain(levelWidth, levelHeight, triangleWidth)
{
	fLevelGravity = 9.8f;
}



sf::Texture Level::getTexure()
{
	return fTerrainTexture;
}

void Level::changeScaleFactor(float newScaleFactor)
{
	fScaleFactor = newScaleFactor;
}
