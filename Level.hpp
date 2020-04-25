#pragma once
#include "Terrain.hpp"



class Level : private Terrain
{
public:
	Level();
	sf::Sprite getSprite();
	sf::Texture getTexure();

	void setSpritePosition(int X, int Y);

private:
	float fLevelGravity;
};

