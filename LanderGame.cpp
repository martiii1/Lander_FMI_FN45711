#include "LanderGame.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <ctime>
#include <cstring>
#include <sstream>
#include <iostream>


LanderGame::LanderGame() : fCurrentLevel(1280, 720, 100)
{

	fLander.changeThrust(1500);
	fLander.changeMass(50);
	fLander.changeGravity(fCurrentLevel.fLevelGravity);

	fGameWidth = 1280;
	fGameHeight = 720;

	// Default game settings
	maxImpactX = 0.015f;
	maxImpactY = 0.1f;
	maxRotation = 2.5f;
	NUMBER_MULTYPLIER = 1000.f;

	//vector zeriong
	landerMovementVec = sf::Vector2f(0.f, 0.f);
	gravityVec = sf::Vector2f(0.f, fCurrentLevel.fLevelGravity);
	isRunning = false;


}

LanderGame::LanderGame(unsigned int gameWidth, unsigned int gameHeight) : fCurrentLevel(gameWidth, gameHeight, 100.f)
{

	fLander.changeThrust(1500);
	fLander.changeMass(50);
	fLander.changeGravity(fCurrentLevel.fLevelGravity);

	fGameWidth = gameWidth;
	fGameHeight = gameHeight;

	// Default game settings
	maxImpactX = 0.015f;
	maxImpactY = 0.1f;
	maxRotation = 3.f;
	NUMBER_MULTYPLIER = 1000.f;

	//vector zeriong
	landerMovementVec = sf::Vector2f(0.f, 0.f);
	gravityVec = sf::Vector2f(0.f, fCurrentLevel.fLevelGravity);
	isRunning = false;

}


void LanderGame::startGame()
{
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

	isRunning = false;


	EarthButton.create("images/earth.png", "images/earthP.png", fGameWidth / 8.f * 2, fGameHeight / 2.f);
	MoonButton.create("images/moon.png", "images/moonP.png", fGameWidth / 8.f * 3, fGameHeight / 2.f);
	MarsButton.create("images/mars.png", "images/marsP.png", fGameWidth / 8.f * 4, fGameHeight / 2.f);

	EarthButton.setPos();
	MoonButton.setPos();
	MarsButton.setPos();

	window.create(sf::VideoMode(fGameWidth, fGameHeight), "Lander");
	window.setVerticalSyncEnabled(true);

	view1 = window.getDefaultView();

	scaleFactor = 0.5;
	fCurrentLevel.changeScaleFactor(scaleFactor);
	
	
	fLander.fLanderSprite.scale(scaleFactor, scaleFactor);
	while (window.isOpen())
	{
		if(!isRunning)
			openEventEventWindow();

		if (isRunning)
		{
			deltaT = clock.restart().asSeconds();

			AICommands.calcNextMove(fLander, landerMovementVec);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
			{
				AICommands.isRunning = true;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
			{
				AICommands.isRunning = false;

				view1.zoom(1.01f);
				window.setView(view1);

				// restore the default view
				//window.setView(window.getDefaultView());
			}


			//detect inputs
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || (AICommands.up && AICommands.isRunning))
			{
				fLander.CalcVecs();
				landerMovementVec += (landerMovementVec + fLander.fLanderThrustVector) * deltaT * deltaT;
				fLander.EngineOn();
			}
			else
			{
				fLander.EngineOff();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || (AICommands.right && AICommands.isRunning))
			{
				fLander.fLanderRotation += 45.f * deltaT;
				if (fLander.fLanderRotation > 360.f)
					fLander.fLanderRotation = 0;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || (AICommands.left && AICommands.isRunning))
			{
				fLander.fLanderRotation -= 45.f * deltaT;
				if (fLander.fLanderRotation < -360.f)
					fLander.fLanderRotation = 0;
				
			}
			else
			{
				fLander.fLanderRotation = (int)fLander.fLanderRotation; // rounds the rotation to int for easier calculations
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
			{
				isRunning = false;
			}

			fLander.fLanderSprite.setRotation(fLander.fLanderRotation);
			fLander.CalcVecs();

			landerMovementVec += (landerMovementVec + gravityVec) * deltaT * deltaT; // nearly 1-1 with real life if the lander is correctly set up

			fLander.fLanderSprite.move(landerMovementVec);


			//collision detection

			tempLanderX = fLander.fLanderSprite.getPosition().x;
			tempLanderY = fLander.fLanderSprite.getPosition().y;

			//TODO:  TURN ON WHEN THE PLAYER IS LOW 

			if(detectColision(sf::Vector2f(tempLanderX,tempLanderY), fCurrentLevel,(sf::Vector2f)fLander.fLanderTexute.getSize()))
			{

				if (landerMovementVec.x < maxImpactX && landerMovementVec.x > -maxImpactX && landerMovementVec.y < maxImpactY && fLander.fLanderRotation < maxRotation)
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
					fLander.fLanderRotation = 0;
					endGameMsg.changeColor(sf::Color::Red);
					endGameMsg.chageTxt(" You crashed! ");
					isRunning = false;
				}
			}



			//Text for testing purposes
			int tempX = fLander.fLanderSprite.getPosition().x;
			int tempY = fLander.fLanderSprite.getPosition().y;


			char asdd[20];
			sf::String asd;

			asd = _itoa(tempX, asdd, 10);
			text1.setString(asd);

			asd = _itoa(tempY, asdd, 10);
			text2.setString(asd);


			asd = _itoa(fLander.fLanderRotation, asdd, 10);

			rotatiton.setString(asd);


			tempX = landerMovementVec.x * NUMBER_MULTYPLIER;
			asd = _itoa(tempX, asdd, 10);
			xVelTesxt.setString(asd);

			tempY = landerMovementVec.y * NUMBER_MULTYPLIER;
			asd = _itoa(tempY, asdd, 10);
			yVelTesxt.setString(asd);


		}

		// Clear the window 
		window.clear(sf::Color(80, 80, 80));

		if (isRunning)
		{
			window.draw(fLander.fLanderSprite);

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

			window.draw(EarthButton.getSprite());
			window.draw(MoonButton.getSprite());
			window.draw(MarsButton.getSprite());

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

	sf::Vector2f landerDownMid;


	landerUpLeft.x = landerUpLeftPos.x + (-texureSize.x) * fLander.fLanderSprite.getScale().x / 2.f;
	landerUpLeft.y = landerUpLeftPos.y + (-texureSize.y) * fLander.fLanderSprite.getScale().y / 2.f;

	landerUpRight.x = landerUpLeftPos.x + (texureSize.x) * fLander.fLanderSprite.getScale().x / 2.f;
	landerUpRight.y = landerUpLeftPos.y + (-texureSize.y) * fLander.fLanderSprite.getScale().y / 2.f;

	landerDownLeft.x = landerUpLeftPos.x + (-texureSize.x) * fLander.fLanderSprite.getScale().x / 2.f;
	landerDownLeft.y = landerUpLeftPos.y + (texureSize.y) * fLander.fLanderSprite.getScale().y / 2.f;

	landerDownRight.x = landerUpLeftPos.x + (texureSize.x) * fLander.fLanderSprite.getScale().x / 2.f;
	landerDownRight.y = landerUpLeftPos.y + (texureSize.y) * fLander.fLanderSprite.getScale().y / 2.f;

	landerDownMid.x = landerUpLeftPos.x * fLander.fLanderSprite.getScale().x;
	landerDownMid.y = landerUpLeftPos.y + (texureSize.y) * fLander.fLanderSprite.getScale().y / 2.f;

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

		if (pointInTriangle(landerDownMid, map.fTerrainTriangles[i].position, map.fTerrainTriangles[i + 1].position, map.fTerrainTriangles[i + 2].position))
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

void LanderGame::openEventEventWindow()
{
	while (window.pollEvent(event))
	{
		// if the window is closed or escape key pressed
		if ((event.type == sf::Event::Closed) ||
			((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
		{
			window.close();
			return;
		}

		// if enter is pressed the game begins/restarts
		if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Enter))
		{
			if (!isRunning)
			{
				isRunning = true;
				clock.restart();

				// TODO lander reset
				fLander.fLanderSprite.setPosition(0, 50); // TODO fix
				landerMovementVec.x = 1.5f;

				fLander.changeRotation(-90);

				fCurrentLevel.newRandomTerrain(fGameWidth, fGameHeight, 100.f); // test

				fLander.changeGravity(fCurrentLevel.fLevelGravity);

				gravityVec.y = fCurrentLevel.fLevelGravity;

				AICommands.isRunning = false;

			}
		}
		else
		{
			tempMouseX = sf::Mouse::getPosition(window).x;
			tempMouseY = sf::Mouse::getPosition(window).y;

			tempMouseButton = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);

			if (EarthButton.isClicked(tempMouseX, tempMouseY, tempMouseButton))  // SEPERATE IN FUNC OR CLASS!
			{
				fCurrentLevel.fLevelGravity = 9.8f;  // Level load here
				fCurrentLevel.fTerrainTexture = fCurrentLevel.fEarthTexture;
			}

			if (MoonButton.isClicked(tempMouseX, tempMouseY, tempMouseButton))
			{
				fCurrentLevel.fLevelGravity = 1.62f;
				fCurrentLevel.fTerrainTexture = fCurrentLevel.fMoonTexture;
			}

			if (MarsButton.isClicked(tempMouseX, tempMouseY, tempMouseButton))
			{
				fCurrentLevel.fLevelGravity = 3.711f; // Level load here
				fCurrentLevel.fTerrainTexture = fCurrentLevel.fMarsTexture;
			}

			fLander.changeGravity(fCurrentLevel.fLevelGravity);
		}

	}
}

