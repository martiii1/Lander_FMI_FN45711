#pragma once
#include<SFML/Graphics.hpp>

class Terrain
{
public:
	Terrain();
	Terrain(unsigned short int gameWidth, unsigned short int gameHeight);


	sf::Texture fTerrainTexure;

	sf::VertexArray fTerrainTriangles;

	unsigned short int fGameWidth;
	unsigned short int fGameHeight;
};