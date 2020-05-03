#pragma once
#include<SFML/Graphics.hpp>


class Lander
{
public:
	Lander();
	Lander(float thrust,float mass,float gravity);

	const int pi = 3.14159;
	void CalcVecs();
	void EngineOn();
	void EngineOff();
	void changeGravity(float newGravity);
	void changeRotation(int newRotation);
	void changeThrust(float newThrust);
	void changeMass(float newMass);


	float getLanderWidth();
	float getAcceleration();
	float getThrust();
	float getRotation();



	sf::Texture fLanderTexute;
	sf::Texture fLangerWithEngineTexure;
	sf::Sprite fLanderSprite;
	sf::Vector2f fLanderThrustVector;

	float fThrust;				// IN newtons, N
	float fMass;				// in kilograms, kg
	float fGravityAcceleration; // gravity (m/s*s)
	float fWeight;				// mass * gravity (in N)
	float fResultantForce;		// thrust - weight (in N)
	float fAcceleration;		// int meters per second per second (m/s*s)

	float fLanderRotation;		// rotation in degrees

	bool engineOn;

};

