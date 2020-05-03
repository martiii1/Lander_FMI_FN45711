#include "LanderGame.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <ctime>
#include <cstring>
#include <sstream>
#include <iostream>

#include "Lander.hpp"
#include "Terrain.hpp"
#include "Button.hpp"


LanderGame::LanderGame() : fCurrentLevel(1280, 720, 100)
{
	fGameWidth = 1280;
	fGameHeight = 720;
}

LanderGame::LanderGame(unsigned int gameWidth, unsigned int gameHeight) : fCurrentLevel(1280, 720, 100.f)
{
	fGameWidth = gameWidth;
	fGameHeight = gameHeight;
}


void LanderGame::startGame()
{
	//test consts
	//float gravity = 9.8f;

	const float maxImpactX = 0.015f;
	const float maxImpactY = 0.1f;
	const float maxRotation = 2.5f;


	
	Lander flander(1500, 50, fCurrentLevel.fLevelGravity);
	

	sf::Vector2f landerMovementVec(0.f, 0.f);
	sf::Vector2f gravityVec(0.f, fCurrentLevel.fLevelGravity);

	sf::Font font;
	if (!font.loadFromFile("images/Arial.ttf"))
		return;

	TextAndMessages startGameMsg(" Lander! \n Press \"enter\" to start the game", 35, fGameWidth / 4, fGameHeight / 50, sf::Color::White);
	TextAndMessages endGameMsg("", 35, fGameWidth / 3, fGameHeight / 6, sf::Color::White);



	sf::Text text1;
	text1.setFont(font);
	text1.setCharacterSize(20);
	text1.setPosition(170.f, 50.f);
	text1.setFillColor(sf::Color::White);

	sf::Text text2;
	text2.setFont(font);
	text2.setCharacterSize(20);
	text2.setPosition(250.f, 50.f);
	text2.setFillColor(sf::Color::White);


	sf::Text rotatiton;
	rotatiton.setFont(font);
	rotatiton.setCharacterSize(20);
	rotatiton.setPosition(50.f, 50.f);
	rotatiton.setFillColor(sf::Color::White);

	sf::Text xVelTesxt;
	xVelTesxt.setFont(font);
	xVelTesxt.setCharacterSize(20);
	xVelTesxt.setPosition(500.f, 50.f);
	xVelTesxt.setFillColor(sf::Color::White);

	sf::Text yVelTesxt;
	yVelTesxt.setFont(font);
	yVelTesxt.setCharacterSize(20);
	yVelTesxt.setPosition(600.f, 50.f);
	yVelTesxt.setFillColor(sf::Color::White);


	sf::Clock clock;
	bool isRunning = false;

	float tempMouseX;
	float tempMouseY;
	bool tempMouseButton;


	Button Earth("images/earth.png", "images/earthP.png", fGameWidth / 8.f * 2, fGameHeight / 2.f);
	Button Moon("images/moon.png", "images/moonP.png", fGameWidth / 8.f * 3, fGameHeight / 2.f);
	Button Mars("images/mars.png", "images/marsP.png", fGameWidth / 8.f * 4, fGameHeight / 2.f);

	Earth.setPos();
	Moon.setPos();
	Mars.setPos();


	sf::RenderWindow window(sf::VideoMode(fGameWidth, fGameHeight), "Lander"); // crating a window
	window.setVerticalSyncEnabled(true); // fps limmiter

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			// if the window is closed or escape key pressed
			if ((event.type == sf::Event::Closed) ||
				((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
			{
				window.close();
				break;
			}

			// if enter is pressed the game begins/restarts
			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Enter))
			{
				if (!isRunning)
				{
					isRunning = true;
					clock.restart();

					// TODO lander reset sruct

					flander.fLanderSprite.setPosition(0, 50); // TODO fix
					landerMovementVec.x = 1.5f; // test
					flander.changeRotation(-90); // test
					fCurrentLevel.newRandomTerrain(fGameWidth, fGameHeight, 100.f); // test

					
					flander.changeGravity(fCurrentLevel.fLevelGravity);
					gravityVec.y = fCurrentLevel.fLevelGravity;

				}
			}
			else
			{
				tempMouseX = sf::Mouse::getPosition(window).x;
				tempMouseY = sf::Mouse::getPosition(window).y;
				tempMouseButton = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);

				if (Earth.isClicked(tempMouseX, tempMouseY, tempMouseButton))  // SEPERATE IN FUNC OR CLASS!
				{
					fCurrentLevel.fLevelGravity = 9.8f;  // Level load here
					fCurrentLevel.fTerrainTexture = fCurrentLevel.fEarthTexture;
				}

				if (Moon.isClicked(tempMouseX, tempMouseY, tempMouseButton))
				{
					fCurrentLevel.fLevelGravity = 1.62f;
					fCurrentLevel.fTerrainTexture = fCurrentLevel.fMoonTexture;
				}

				if (Mars.isClicked(tempMouseX, tempMouseY, tempMouseButton))
				{
					fCurrentLevel.fLevelGravity = 3.711f; // Level load here
					fCurrentLevel.fTerrainTexture = fCurrentLevel.fMarsTexture;
				}

				flander.changeGravity(fCurrentLevel.fLevelGravity);

			}

		}

		if (isRunning)
		{
			float deltaT = clock.restart().asSeconds();

			//detect inputs
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				flander.CalcVecs();
				landerMovementVec += (landerMovementVec + flander.fLanderThrustVector) * deltaT * deltaT;
				flander.EngineOn();
			}
			else
			{
				flander.EngineOff();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				flander.fLanderRotation += 45.f * deltaT;
				if (flander.fLanderRotation > 360.f)
					flander.fLanderRotation = 0;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				flander.fLanderRotation -= 45.f * deltaT;
				if (flander.fLanderRotation < -360.f)
					flander.fLanderRotation = 0;
				
			}
			else
			{
				flander.fLanderRotation = (int)flander.fLanderRotation; // rounds the rotation to int
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
			{
				isRunning = false;
			}

			

			flander.fLanderSprite.setRotation(flander.fLanderRotation);
			flander.CalcVecs();

			landerMovementVec += (landerMovementVec + gravityVec) * deltaT * deltaT; // nearly 1-1 with real life if the lander is correctly setup

			flander.fLanderSprite.move(landerMovementVec);


			//collision detection


			float tempfX = flander.fLanderSprite.getPosition().x;
			float tempfY = flander.fLanderSprite.getPosition().y;

			//TODO:  TURN ON WHEN THE PLAYER IS LOW 
			if(detectColision(sf::Vector2f(tempfX,tempfY), fCurrentLevel,(sf::Vector2f)flander.fLanderTexute.getSize()))
			{

				if (landerMovementVec.x < maxImpactX && landerMovementVec.x > -maxImpactX && landerMovementVec.y < maxImpactY && flander.fLanderRotation < maxRotation)
				{
					landerMovementVec.x = 0;
					landerMovementVec.y = 0;
					endGameMsg.changeColor(sf::Color::Green);
					endGameMsg.chageTxt(" You landed succesfully! ");
					isRunning = false;
				}
				else
				{
					landerMovementVec.x = 0;
					landerMovementVec.y = 0;
					flander.fLanderRotation = 0;
					endGameMsg.changeColor(sf::Color::Red);
					endGameMsg.chageTxt(" You crashed! ");
					isRunning = false;
				}
			}



			//Text for testing purposes
			int tempX = flander.fLanderSprite.getPosition().x;
			int tempY = flander.fLanderSprite.getPosition().y;


			char asdd[20];
			sf::String asd;

			asd = _itoa(tempX, asdd, 10);
			text1.setString(asd);

			asd = _itoa(tempY, asdd, 10);
			text2.setString(asd);


			asd = _itoa(flander.fLanderRotation, asdd, 10);

			rotatiton.setString(asd);


			tempX = landerMovementVec.x * 1000;
			asd = _itoa(tempX, asdd, 10);
			xVelTesxt.setString(asd);

			tempY = landerMovementVec.y * 1000;
			asd = _itoa(tempY, asdd, 10);
			yVelTesxt.setString(asd);


		}

		// Clear the window 
		window.clear(sf::Color(80, 80, 80));

		if (isRunning)
		{
			window.draw(flander.fLanderSprite);

			window.draw(text1);
			window.draw(text2);
			window.draw(xVelTesxt);
			window.draw(yVelTesxt);
			window.draw(rotatiton);


			window.draw(fCurrentLevel.fTerrainTriangles, &fCurrentLevel.getTexure());

		}
		else
		{

			window.draw(startGameMsg.getText());
			window.draw(endGameMsg.getText());


			window.draw(Earth.getSprite());
			window.draw(Moon.getSprite());
			window.draw(Mars.getSprite());

		}


		window.display();
	}
	

}

unsigned int LanderGame::getWidth() const
{
	return fGameWidth;
}

unsigned int LanderGame::getHeight() const
{
	return fGameHeight;
}

bool LanderGame::detectColision(const sf::Vector2f& landerUpLeftPos, const Level& map, const sf::Vector2f& texureSize)
{
	sf::Vector2f landerUpLeft;
	sf::Vector2f landerUpRight;
	sf::Vector2f landerDownLeft;
	sf::Vector2f landerDownRight;


	landerUpLeft = landerUpLeftPos + sf::Vector2f(-texureSize.x/2.f, -texureSize.y/2);
	landerUpRight = landerUpLeftPos + sf::Vector2f(texureSize.x / 2.f, -texureSize.y / 2);
	landerDownLeft = landerUpLeftPos  + sf::Vector2f(-texureSize.x / 2.f, texureSize.y / 2);
	landerDownRight = landerUpLeftPos + sf::Vector2f(texureSize.x / 2.f, texureSize.y / 2);

	size_t numberOfVertex = map.fTerrainTriangles.getVertexCount();


	for (int i = 0; i < numberOfVertex - 3; i++)
	{
		if (pointInTriangle(landerUpLeft, map.fTerrainTriangles[i].position, map.fTerrainTriangles[i + 1].position, map.fTerrainTriangles[i + 2].position))
			return true;

		if (pointInTriangle(landerDownLeft, map.fTerrainTriangles[i].position, map.fTerrainTriangles[i + 1].position, map.fTerrainTriangles[i + 2].position))
			return true;

		if (pointInTriangle(landerUpRight, map.fTerrainTriangles[i].position, map.fTerrainTriangles[i + 1].position, map.fTerrainTriangles[i + 2].position))
			return true;

		if (pointInTriangle(landerDownRight, map.fTerrainTriangles[i].position, map.fTerrainTriangles[i + 1].position, map.fTerrainTriangles[i + 2].position))
			return true;
	}

	return false;
}



float LanderGame::triangleArea(const sf::Vector2f& point1, const sf::Vector2f& point2, const sf::Vector2f& point3)
{
	float det = 0.f;

	det = abs(point1.y * (point3.x - point2.x) + point2.y * (point1.x - point3.x) + point3.y * (point2.x - point1.x));
	
	return (det / 2.f);
}

bool LanderGame::pointInTriangle(const sf::Vector2f& point, const sf::Vector2f& triangleA, const sf::Vector2f& triangleB, const sf::Vector2f& triangleC)
{
	float mainTriangle;
	mainTriangle = triangleArea(triangleA, triangleB, triangleC);

	float tempSumOfTriangles = 0.f;
	tempSumOfTriangles += triangleArea(triangleA, point, triangleB);
	tempSumOfTriangles += triangleArea(triangleB, point, triangleC);
	tempSumOfTriangles += triangleArea(triangleA, point, triangleC);

	if (tempSumOfTriangles > mainTriangle)
		return false;
	else
		return true;
}

