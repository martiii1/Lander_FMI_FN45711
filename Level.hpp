#pragma once
#include "Terrain.hpp"



class Level : public Terrain
{
public:
	Level();
	Level(unsigned int gameWidth, unsigned int gameHeight);
	sf::Texture getTexure();


	float fLevelGravity;
};

