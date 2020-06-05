#include "Terrain.hpp"
#include "Lander.hpp"
#include "LanderGame.hpp"
#include <time.h> 

Terrain::Terrain(unsigned int levelWidth, unsigned int levelHeight)
{
	if (!fTerrainTexture.loadFromFile("images/earth_ground.png"))
	{
		//handle error!
	}

	fTerrainTriangles = sf::VertexArray(sf::TriangleStrip, 2);

	fTerrainTriangles[0].position = sf::Vector2f(50.f, 500.f);
	fTerrainTriangles[1].position = sf::Vector2f(50.f, levelHeight);
	fScaleFactor = 1.f;


}

Terrain::Terrain(unsigned int levelWidth, unsigned int levelHeight, float triangleWidth)
{
		loadTextures();

		newRandomTerrain(levelWidth, levelHeight, triangleWidth);
}

void Terrain::newRandomTerrain(unsigned int levelWidth, unsigned int levelHeight, float triangleWidth)
{
	srand(time(NULL));

	unsigned short int randWidth = 0;
	unsigned short int randHeight = 550;

	fTerrainTriangles.clear();

	fTerrainTriangles = sf::VertexArray(sf::TriangleStrip, 2);

	fTerrainTriangles[0].position = sf::Vector2f(0.f, randHeight);
	fTerrainTriangles[1].position = sf::Vector2f(0.f, levelHeight);

	fillerRectangle.setSize(sf::Vector2f(levelWidth * 10.f, levelHeight)); // TODO FIX THE 10 (magic number)
	fillerRectangle.setPosition(0, levelHeight);
	fillerRectangle.setTexture(&fTerrainTexture);


	do
	{
		if (randHeight < levelHeight * 0.5f)
		{
			randHeight += rand() % (levelHeight / 15); // random elevation change from 0 to 50 - ish
		}
		else if (randHeight > levelHeight * 0.9f)
		{
			randHeight -= rand() % (levelHeight / 15); // TODO remove the magic numbers
		}
		else
		{
			if (rand() % 100 > 50)
				randHeight -= rand() % (levelHeight / 15);
			else
				randHeight += rand() % (levelHeight / 15);
		}

		randWidth += (rand() % (int)triangleWidth) + (int)triangleWidth / 2 + 1; // random width from 50% lander to 150% lander !!! WILL BE CHANGED
		

		fTerrainTriangles.append(sf::Vector2f(randWidth * fScaleFactor, randHeight ));
		fTerrainTriangles.append(sf::Vector2f(randWidth * fScaleFactor, levelHeight));



	} while (randWidth * fScaleFactor < levelWidth * 10); // TODO CHANGE THE 10 !!!
}

void Terrain::loadTextures()
{
	if (!fEarthTexture.loadFromFile("images/earth_ground.png"))
	{
		//handle error!
	}
	
	if (!fMoonTexture.loadFromFile("images/moon_ground.png"))
	{
		//handle error!
	}

	if (!fMarsTexture.loadFromFile("images/mars_ground.png"))
	{
		//handle error!
	}

	fEarthTexture.setSmooth(true);

}

