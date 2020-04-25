#include "Terrain.hpp"

Terrain::Terrain()
{
	if (!fTerrainTexure.loadFromFile("images/grass.png"))
	{
		//handle error!
	}

	fTerrainSprite.setTexture(fTerrainTexure);
	//fTerrainSprite.setPosition(0, gameHeight - fTerrainTexure.getSize().y);

}
