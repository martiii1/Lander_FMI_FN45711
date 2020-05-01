#include "Terrain.hpp"

Terrain::Terrain(unsigned short int gameWidth = 1024, unsigned short int gameHeight=768)
{
	if (!fTerrainTexure.loadFromFile("images/grass.png"))
	{
		//handle error!
	}

	fTerrainSprite.setTexture(fTerrainTexure);
	//fTerrainSprite.setPosition(0, gameHeight - fTerrainTexure.getSize().y);

	fGameHeight = gameHeight;
	fGameWidth = gameWidth;


	//TODO automate
	fTerrainTriangles = sf::VertexArray(sf::TriangleStrip, 10);

	fTerrainTriangles[0].position = sf::Vector2f(50.f, 500.f);
	fTerrainTriangles[1].position = sf::Vector2f(50.f, fGameHeight);
	fTerrainTriangles[2].position = sf::Vector2f(200.f, 500.f);
	fTerrainTriangles[3].position = sf::Vector2f(200.f, fGameHeight);
	fTerrainTriangles[4].position = sf::Vector2f(300.f, 600.f);
	fTerrainTriangles[5].position = sf::Vector2f(300.f, fGameHeight);
	fTerrainTriangles[6].position = sf::Vector2f(400.f, 600.f);
	fTerrainTriangles[7].position = sf::Vector2f(400.f, fGameHeight);
	fTerrainTriangles[8].position = sf::Vector2f(500.f, 700.f);
	fTerrainTriangles[9].position = sf::Vector2f(500.f, fGameHeight);


}
