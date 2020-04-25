#pragma once
#include<SFML/Graphics.hpp>

class Terrain
{
public:
	Terrain(const int gameWidht,const int gameHeight);

	sf::Texture fTerrainTexure;
	sf::Sprite fTerrainSprite;

};