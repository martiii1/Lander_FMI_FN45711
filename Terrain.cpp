#include "Terrain.hpp"

Terrain::Terrain(const int gameWidht,int gameHeight)
{
	if (!fTerrainTexure.loadFromFile("grass.png"))
	{
		//handle error!
	}

	fTerrainSprite.setTexture(fTerrainTexure);
	//fTerrainSprite.setPosition(0, gameHeight - fTerrainTexure.getSize().y);

}
