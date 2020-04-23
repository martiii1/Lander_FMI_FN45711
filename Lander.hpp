#pragma once
#include<SFML/Graphics.hpp>


class Lander
{
public:
	const int pi = 3.14159;
	Lander(float thrust,float mass,float gravity);
	void CalcVecs();
	void EngineOn();
	void EngineOff();


	sf::Texture fLanderTexute;
	sf::Texture fLangerWithEngineTexure;
	sf::Sprite fLanderSprite;
	sf::Vector2f fLanderThrustVector;

	float fThrust;				// IN newtons, N
	float fMass;				// in kilograms, kg
	float fGravityAcceleration;
	float fWeight;				// mass * gravity (in N)
	float fResultantForce;		// thrust - weight (in N)
	float fAcceleration;		// int meters per second per second (m/s*s)

	float fLanderRotation;		// rotation in degrees

};

