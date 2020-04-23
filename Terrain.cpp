#include "Terrain.hpp"

Terrain::Terrain(const int gameWidht,const int gameHeight)
{
	if (!fTerrainTexure.loadFromFile("test2.png"))
	{
		//error
	}

	fTerrainSprite;
	fTerrainSprite.setTexture(fTerrainTexure);
	//fTerrainSprite.setPosition(gameWidht/2, gameHeight - fTerrainTexure.getSize().y);
}
