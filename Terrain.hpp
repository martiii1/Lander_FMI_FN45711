#pragma once
#include<SFML/Graphics.hpp>

class Terrain
{
public:
	Terrain(unsigned int levelWidth, unsigned int levelHeight);
	Terrain(unsigned int levelWidth, unsigned int levelHeight, float triangleWidth);

	sf::Texture fTerrainTexure;
	sf::VertexArray fTerrainTriangles;

};