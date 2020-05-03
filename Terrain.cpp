#include "Terrain.hpp"
#include "Lander.hpp"
#include "LanderGame.hpp"
#include <time.h> 

Terrain::Terrain(unsigned int levelWidth, unsigned int levelHeight)
{
	if (!fTerrainTexure.loadFromFile("images/grass.png"))
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
		srand(time(NULL));

		unsigned short int randWidth = 0;
		unsigned short int randHeight = 500;
		bool randElevationDirection = true; // TODO later

		fTerrainTriangles = sf::VertexArray(sf::TriangleStrip, 2);

		fTerrainTriangles[0].position = sf::Vector2f(50.f, 500.f);
		fTerrainTriangles[1].position = sf::Vector2f(50.f, levelHeight);


		float tempTriangleNumber = levelWidth / triangleWidth;

		do
		{
			randWidth += rand() % (int)triangleWidth + (int)triangleWidth / 2 + 1; // random width from 50% lander to 100% lander !!! WILL BE CHANGED
			randHeight -= rand() % 51; // random elevation change from 0 to 50
			/*if (rand() % 100 > 50)
				randElevationDirection = true;
			else
				randElevationDirection = false; TODO */

			fTerrainTriangles.append(sf::Vector2f(randWidth, randHeight));
			fTerrainTriangles.append(sf::Vector2f(randWidth, levelHeight));



		} while (randWidth < levelWidth);

}

