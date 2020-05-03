#include "Lander.hpp"

Lander::Lander()
{
	if (!fLanderTexute.loadFromFile("images/test1.png"))
	{
		//error
	}

	if (!fLangerWithEngineTexure.loadFromFile("images/LanderWithEngine.png"))
	{
		//error
	}
	

	fThrust = 1500;
	fMass = 50;
	fGravityAcceleration = 9.8f;

	fWeight = fMass * 9.8f;
	fResultantForce = fThrust - fWeight;
	fAcceleration = fResultantForce / fMass;

	fLanderTexute.setSmooth(true);
	fLanderSprite.setTexture(fLanderTexute);
	fLanderSprite.setOrigin(sf::Vector2f(fLanderSprite.getTexture()->getSize().x / 2, fLanderSprite.getTexture()->getSize().y / 2));

	fLanderRotation = 0;
	engineOn = false;

}

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

	fLanderTexute.setSmooth(true);
	fLangerWithEngineTexure.setSmooth(true);

	fLanderSprite.setTexture(fLanderTexute);
	//fLanderSprite.setPosition(0, 0);
	fLanderSprite.setOrigin(sf::Vector2f(fLanderSprite.getTexture()->getSize().x / 2, fLanderSprite.getTexture()->getSize().y / 2));

	fLanderRotation = 0;
	engineOn = false;

}

void Lander::CalcVecs()
{
	fResultantForce = fThrust - fWeight;
	fAcceleration = fResultantForce / fMass;

	fLanderThrustVector.x = std::sin(fLanderRotation * pi / 180) * fAcceleration * 2.f;
	fLanderThrustVector.y = std::cos(fLanderRotation * pi / 180) * fAcceleration * (-2.f); // * 2 seems realistic but why?
}

void Lander::EngineOn()
{
	fLanderSprite.setTexture(fLangerWithEngineTexure);
	engineOn = true;
}

void Lander::EngineOff()
{
	fLanderSprite.setTexture(fLanderTexute);
	engineOn = false;
}

void Lander::changeGravity(float newGravity)
{
	fGravityAcceleration = newGravity;
}

void Lander::changeRotation(int newRotation)
{
	fLanderRotation = newRotation;

}

void Lander::changeThrust(float newThrust)
{
	fThrust = newThrust;
}

void Lander::changeMass(float newMass)
{
	fMass = newMass;
}

float Lander::getLanderWidth()
{
	return (fLanderTexute.getSize().y * fLanderSprite.getScale().y);
}
