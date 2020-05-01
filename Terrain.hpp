#pragma once
#include<SFML/Graphics.hpp>

class Terrain
{
public:
	Terrain(unsigned short int gameWidth = 1024, unsigned short int gameHeight = 768);

	sf::Texture fTerrainTexure;
	sf::Sprite fTerrainSprite;

	sf::VertexArray fTerrainTriangles;

	unsigned short int fGameWidth;
	unsigned short int fGameHeight;
};