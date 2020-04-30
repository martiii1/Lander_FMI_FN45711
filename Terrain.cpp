#include "Terrain.hpp"

Terrain::Terrain()
{
	if (!fTerrainTexure.loadFromFile("images/grass.png"))
	{
		//handle error!
	}

	fTerrainSprite.setTexture(fTerrainTexure);
	//fTerrainSprite.setPosition(0, gameHeight - fTerrainTexure.getSize().y);


	asd = sf::VertexArray(sf::TriangleStrip, 10);

	asd[0].position = sf::Vector2f(50.f, 500.f);
	asd[1].position = sf::Vector2f(50.f, 1000.f);
	asd[2].position = sf::Vector2f(200.f, 500.f);
	asd[3].position = sf::Vector2f(200.f, 1000.f);
	asd[4].position = sf::Vector2f(300.f, 600.f);//
	asd[5].position = sf::Vector2f(300.f, 1000.f);//
	asd[6].position = sf::Vector2f(400.f, 600.f);//
	asd[7].position = sf::Vector2f(400.f, 1000.f);
	asd[8].position = sf::Vector2f(500.f, 700.f);
	asd[9].position = sf::Vector2f(500.f, 1000.f);


}
