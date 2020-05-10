#pragma once

#include <SFML/Graphics.hpp>
#include "Lander.hpp"
#include "Level.hpp"
#include "TextAndMessages.hpp"
#include "AIPlayer.hpp"
#include "Lander.hpp"
#include "Terrain.hpp"
#include "Button.hpp"
#include "UI.hpp"


class LanderGame : protected UI
{
public:
	LanderGame();
	LanderGame(unsigned int gameWidth, unsigned int gameHeight);

	void startGame();

	unsigned int getWidth() const;
	unsigned int getHeight() const;

private:
	// Game resolution
	unsigned int fGameWidth;
	unsigned int fGameHeight;

	// + multyplier for the displayed numbers
	float NUMBER_MULTYPLIER = 1000.f;

	// Main objects
	Lander fLander;
	Level fCurrentLevel;
	AIPlayer AICommands;

	// Buttons for levels
	Button EarthButton;
	Button MoonButton;
	Button MarsButton;

	// Main vectors for movement
	sf::Vector2f landerMovementVec;
	sf::Vector2f gravityVec;

	// Default game settings
	float maxImpactX;
	float maxImpactY;
	float maxRotation;
	

	// temp variables
	float tempLanderX;
	float tempLanderY;

	// variables for tempChecks
	float tempMouseX;
	float tempMouseY;
	bool tempMouseButton;

	// is the game running bool
	bool isRunning;

	//window and scale
	sf::RenderWindow window;
	float scaleFactor;

	sf::View mainView;


	sf::Event event;
	sf::Font font;

	sf::Clock clock;
	float deltaT;


	// detections functions
	bool detectColision(const sf::Vector2f& landerUpLeftPos, const Level& map, const sf::Vector2f& texureSize);
	float triangleArea(const sf::Vector2f& point1, const sf::Vector2f& point2, const sf::Vector2f& point3);
	bool pointInTriangle(const sf::Vector2f& point, const sf::Vector2f& triangleA, const sf::Vector2f& triangleB, const sf::Vector2f& triangleC);

	// other funcions
	void openEventEventWindow();
};

