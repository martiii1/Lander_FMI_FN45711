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

	//TODO automate
	fTerrainTriangles = sf::VertexArray(sf::TriangleStrip, 2);

	fTerrainTriangles[0].position = sf::Vector2f(50.f, 500.f);
	fTerrainTriangles[1].position = sf::Vector2f(50.f, levelHeight);


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
	unsigned short int randHeight = 500;

	fTerrainTriangles.clear();

	fTerrainTriangles = sf::VertexArray(sf::TriangleStrip, 2);

	fTerrainTriangles[0].position = sf::Vector2f(0.f, 500.f);
	fTerrainTriangles[1].position = sf::Vector2f(0.f, levelHeight);


	float tempTriangleNumber = levelWidth / triangleWidth;

	do
	{
		
		if (randHeight < levelHeight * 0.1f)
		{
			randHeight += rand() % 51; // random elevation change from 0 to 50
		}
		else if (randHeight > levelHeight * 0.9f)
		{
			randHeight -= rand() % 51;
		}
		else
		{
			if (rand() % 100 > 50)
				randHeight -= rand() % 51;
			else
				randHeight += rand() % 51;
		}

		randWidth += rand() % (int)triangleWidth + (int)triangleWidth / 2 + 1; // random width from 50% lander to 100% lander !!! WILL BE CHANGED

		fTerrainTriangles.append(sf::Vector2f(randWidth, randHeight));
		fTerrainTriangles.append(sf::Vector2f(randWidth, levelHeight));



	} while (randWidth < levelWidth);
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

}

