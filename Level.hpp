#pragma once
#include "Terrain.hpp"



class Level : public Terrain
{
public:
	Level(unsigned int levelWidth, unsigned int levelHeight, float triangleWidth);

	float fLevelGravity;

	sf::Texture getTexure();

	void changeScaleFactor(float newScaleFactor);
};

