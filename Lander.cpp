#include "Lander.hpp"

Lander::Lander(float thrust, float mass,float graviy) // Thrust in N and mass in kg, gravity in m/s*s
{
	
	if (!fLanderTexute.loadFromFile("images/test1.png"))
	{
		//error
	}

	if (!fLangerWithEngineTexure.loadFromFile("images/LanderWithEngine.png"))
	{
		//error
	}

	fThrust = thrust;
	fMass = mass;
	fGravityAcceleration = graviy;

	fWeight = mass * graviy;
	fResultantForce = thrust - fWeight;
	fAcceleration = fResultantForce / mass;


	fLanderSprite.setTexture(fLanderTexute);
	//fLanderSprite.setPosition(0, 0);
	fLanderSprite.setOrigin(sf::Vector2f(fLanderSprite.getTexture()->getSize().x / 2, fLanderSprite.getTexture()->getSize().y / 2));

	fLanderRotation = 0;
}

void Lander::CalcVecs()
{
	fResultantForce = fThrust - fWeight;
	fAcceleration = fResultantForce / fMass;

	fLanderThrustVector.x = std::sin(fLanderRotation * pi / 180) * fAcceleration*2.f;
	fLanderThrustVector.y = std::cos(fLanderRotation * pi / 180) * fAcceleration * (-2.f); // * 2 seems realistic but why?
}

void Lander::EngineOn()
{
	fLanderSprite.setTexture(fLangerWithEngineTexure);
}

void Lander::EngineOff()
{
	fLanderSprite.setTexture(fLanderTexute);
}
