#include <SFML/Graphics.hpp>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iostream>
#include "Lander.hpp"
#include "Terrain.hpp"


// add class for text and maybe lvls 

int main()
{
	//test consts
	const float pi = 3.14159f;
	const int gameWidth = 1280;
	const int gameHeight = 720;
	const float gravity = 9.8f;

	const float maxImpactX = 0.01f;
	const float maxImpactY = 0.1f;
	const float maxRotation = 2.5f;


	Lander lander(1500,50, gravity);
	Terrain map(gameWidth,gameHeight);

	sf::Vector2f landerMovementVec(0.f, 0.f);
	sf::Vector2f gravityVec(0.f, gravity);

	sf::Font font;
	if (!font.loadFromFile("images/Arial.ttf"))
		return -1;

	sf::Text startGameMsg;
	startGameMsg.setFont(font);
	startGameMsg.setCharacterSize(35);
	startGameMsg.setPosition(gameWidth / 4.f, gameHeight / 50.f);
	startGameMsg.setFillColor(sf::Color::White);

	startGameMsg.setString(" Lander! \n Press \"enter\" to start the game");


	sf::Text endGameMsg;
	endGameMsg.setFont(font);
	endGameMsg.setCharacterSize(35);
	endGameMsg.setPosition(gameWidth / 3.f, gameHeight / 2.f);


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

	
	sf::RenderWindow window(sf::VideoMode(gameWidth, gameHeight), "Lander"); // crating a window
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
					lander.fLanderSprite.setPosition(gameWidth / 2, gameHeight / 2);
					map.fTerrainSprite.setPosition(0, gameHeight - map.fTerrainTexure.getSize().y);
				}
			}

		}

		if (isRunning)
		{
			float deltaT = clock.restart().asSeconds();

			//detect inputs
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) )
			{
				lander.CalcVecs();
				landerMovementVec += (landerMovementVec + lander.fLanderThrustVector ) * deltaT * deltaT;
				lander.EngineOn();
			}
			else
			{
				lander.EngineOff();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				lander.fLanderRotation += 60.f * deltaT;
				if (lander.fLanderRotation > 360.f)
					lander.fLanderRotation = 0;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				lander.fLanderRotation -= 60.f * deltaT;
				if (lander.fLanderRotation > 360.f)
					lander.fLanderRotation = 0;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
			{
				isRunning = false;
			}



			lander.fLanderSprite.setRotation(lander.fLanderRotation);
			lander.CalcVecs();

			landerMovementVec += (landerMovementVec + gravityVec) * deltaT * deltaT; // nearly 1-1 with real life if the lander is correctly setup
			
			lander.fLanderSprite.move(landerMovementVec);


			//collision detection

			if (lander.fLanderSprite.getGlobalBounds().intersects(map.fTerrainSprite.getGlobalBounds()))
			{
				if (landerMovementVec.x < maxImpactX && landerMovementVec.y < maxImpactY && lander.fLanderRotation < maxRotation)
				{
					landerMovementVec.x = 0;
					landerMovementVec.y = 0;
					endGameMsg.setFillColor(sf::Color::Green);
					endGameMsg.setString(" You landed succesfully! ");
					isRunning = false;
				}
				else
				{
					landerMovementVec.x = 0;
					landerMovementVec.y = 0;
					endGameMsg.setFillColor(sf::Color::Red);
					endGameMsg.setString(" You crash landed! ");
					isRunning = false;
				}
			}


			 

			//Text for testing purposes
			int tempX = lander.fLanderSprite.getPosition().x;
			int tempY = lander.fLanderSprite.getPosition().y;

			char asdd[20];
			sf::String asd;

			asd = _itoa(tempX,asdd,10);
			text1.setString(asd);

			asd = _itoa(tempY, asdd, 10);
			text2.setString(asd);


			asd = _itoa(lander.fLanderRotation,asdd,10);
			rotatiton.setString(asd);
		

			tempX = landerMovementVec.x * 1000;
			asd = _itoa(tempX, asdd, 10);
			xVelTesxt.setString(asd);

			std::cout << landerMovementVec.y << std::endl;
			tempY = landerMovementVec.y * 1000;
			asd = _itoa(tempY, asdd, 10);
			yVelTesxt.setString(asd);


		}

		// Clear the window 
		window.clear(sf::Color(80, 80, 80));

		if (isRunning)
		{
			window.draw(lander.fLanderSprite);
			window.draw(map.fTerrainSprite);

			window.draw(text1);
			window.draw(text2);
			window.draw(xVelTesxt);
			window.draw(yVelTesxt);
			window.draw(rotatiton);
		}
		else
		{
			window.draw(startGameMsg);
			window.draw(endGameMsg);
		}


		window.display();
	}

	return 0;
}
