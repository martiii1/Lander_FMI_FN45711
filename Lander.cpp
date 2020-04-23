#include "Lander.hpp"

Lander::Lander(float thrust, float mass,float graviy) // Thrust in N and mass in kg, gravity in m/s*s
{
	
	if (!fLanderTexute.loadFromFile("test1.png"))
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
