#pragma once
#include<SFML/Graphics.hpp>

class Terrain
{
public:
	Terrain(unsigned int levelWidth, unsigned int levelHeight);
	Terrain(unsigned int levelWidth, unsigned int levelHeight, float triangleWidth);

	sf::Texture fTerrainTexture;

	sf::Texture fEarthTexture;
	sf::Texture fMoonTexture;
	sf::Texture fMarsTexture;

	sf::VertexArray fTerrainTriangles;

	float fScaleFactor = 1.f;

	void newRandomTerrain(unsigned int levelWidth, unsigned int levelHeight, float triangleWidth);


private:
	void loadTextures();
};