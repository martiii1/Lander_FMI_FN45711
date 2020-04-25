#include "LanderGame.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iostream>

#include "Lander.hpp"
#include "Terrain.hpp"
#include "Button.hpp"


LanderGame::LanderGame()
{
	fLander;
	fCurrentLevel;
	fGameWidth = 1280;
	fGameHeight = 720;
	fLander;
	fCurrentLevel;
}

LanderGame::LanderGame(unsigned int gameWidth, unsigned int gameHeight)
{
	fGameWidth = gameWidth;
	fGameHeight = gameHeight;

}


void LanderGame::startGame()
{
	//test consts
	float gravity = 9.8f;

	const float maxImpactX = 0.01f;
	const float maxImpactY = 0.1f;
	const float maxRotation = 2.5f;


	Lander lander(1500, 50, gravity);
	

	sf::Vector2f landerMovementVec(0.f, 0.f);
	sf::Vector2f gravityVec(0.f, gravity);

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
					lander.fLanderSprite.setPosition(fGameWidth / 2, fGameHeight / 2);
					fCurrentLevel.setSpritePosition(0, fGameHeight - fCurrentLevel.getTexure().getSize().y);
					lander.changeGravity(gravity);
					gravityVec.y = gravity;

				}
			}
			else
			{
				tempMouseX = sf::Mouse::getPosition(window).x;
				tempMouseY = sf::Mouse::getPosition(window).y;
				tempMouseButton = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);

				if (Earth.isClicked(tempMouseX,tempMouseY,tempMouseButton))
					gravity = 9.8f;  // Level load here

				if (Moon.isClicked(tempMouseX, tempMouseY, tempMouseButton))
					gravity = 0.5f;

				if(Mars.isClicked(tempMouseX, tempMouseY, tempMouseButton))
					gravity = 4.5f; // Level load here



			}

		}

		if (isRunning)
		{
			float deltaT = clock.restart().asSeconds();

			//detect inputs
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				lander.CalcVecs();
				landerMovementVec += (landerMovementVec + lander.fLanderThrustVector) * deltaT * deltaT;
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
				if (lander.fLanderRotation < -360.f)
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

			if (lander.fLanderSprite.getGlobalBounds().intersects(fCurrentLevel.getSprite().getGlobalBounds()))
			{
				if (landerMovementVec.x < maxImpactX && landerMovementVec.y < maxImpactY && lander.fLanderRotation < maxRotation)
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
					lander.fLanderRotation = 0;
					endGameMsg.changeColor(sf::Color::Red);
					endGameMsg.chageTxt(" You crashed! ");
					isRunning = false;
				}
			}




			//Text for testing purposes
			int tempX = lander.fLanderSprite.getPosition().x;
			int tempY = lander.fLanderSprite.getPosition().y;

			char asdd[20];
			sf::String asd;

			asd = _itoa(tempX, asdd, 10);
			text1.setString(asd);

			asd = _itoa(tempY, asdd, 10);
			text2.setString(asd);


			asd = _itoa(lander.fLanderRotation, asdd, 10);
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
			window.draw(fCurrentLevel.getSprite());

			window.draw(text1);
			window.draw(text2);
			window.draw(xVelTesxt);
			window.draw(yVelTesxt);
			window.draw(rotatiton);

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

unsigned int LanderGame::getWidth()
{
	return fGameWidth;
}

unsigned int LanderGame::getHeight()
{
	return fGameHeight;
}
