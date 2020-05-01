#pragma once
#include "Terrain.hpp"



class Level : public Terrain
{
public:
	Level();
	sf::Sprite getSprite();
	sf::Texture getTexure();

	void setSpritePosition(int X, int Y);

	float fLevelGravity;
};

