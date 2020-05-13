#include "AIPlayer.hpp"


AIPlayer::AIPlayer()
{
	isRunning = false;
	left = false;
	right = false;
	up = false;
	tempRot = 0;
	distanceBeforeStop = 0;
	fXSpeed;
	fYspeed;
	distanceBeforeStop = 0;
	distanceToGround = 0;

	maxImpactY = 0.1f; // add settings class
}


#define AVERAGE_ERROR_SPEED 0.03f
#define MIN_ERROR_SPEED 0.0005f
void AIPlayer::calcNextMove(Lander &lander, sf::Vector2f &movementVec)
{
	tempRot = (int)lander.getRotation();
	fXSpeed = movementVec.x;
	fYspeed = movementVec.y;
	
	if (stopSidewaysMotion())
	{
		finalBurn(movementVec);
	}

	

}

#define EPSILON 0.001f
bool AIPlayer::stopSidewaysMotion()
{
	stopRightMotion();
	stopLeftMotion();

	//up = false;
	//right = false;
	//left = false;

	if (fXSpeed < EPSILON)
	{
		turnStraightUp();
		return true;
	}
	return false;

	
}

void AIPlayer::turnStraightUp()
{
	if (tempRot != 0)
	{
		if (tempRot > 180 && tempRot > -180)
		{
			right = false;
			left = true;
			return;
		}
		else
		{
			left = false;
			right = true;
			return;
		}
	}

	right = false;
	left = false;
}

bool AIPlayer::stopLeftMotion()
{

	if (fXSpeed < -AVERAGE_ERROR_SPEED)					// LEFT motion big change
	{
		if (tempRot == 90 || tempRot == -270)
		{
			right = false;
			left = false;
			up = true;
			return false;
		}
		else
		{
			up = false;

			if (tempRot < -90 && tempRot > -270)
			{
				left = false;
				right = true;
				return false;
			}
			else
			{
				right = false;
				left = true;
				return false;
			}
		}
	}
	else if (fXSpeed < -MIN_ERROR_SPEED)					// LEFT motion minor change
	{
		if (tempRot == 10 || tempRot == -350)
		{
			right = false;
			left = false;
			up = true;
			return false;
		}
		else
		{
			up = false;

			if (tempRot < 190 && tempRot > 10)
			{
				right = false;
				left = true;
				return false;
			}
			else
			{
				left = false;
				right = true;
				return false;
			}
		}
	}
	else
	{
		return true;
	}

}

bool AIPlayer::stopRightMotion()
{
	if (fXSpeed > AVERAGE_ERROR_SPEED)						// RIGHT motion big change
	{
		if (tempRot == -90 || tempRot == 270)
		{
			right = false;
			left = false;
			up = true;
			return false;
		}
		else
		{
			up = false;

			if (tempRot < 90 && tempRot > -90)
			{
				right = false;
				left = true;
				return false;
			}
			else
			{
				left = false;
				right = true;
				return false;
			}

		}

	}
	else if (fXSpeed > MIN_ERROR_SPEED)						// RIGHT minor motion minor change
	{
		if (tempRot == -10 || tempRot == 350)
		{
			right = false;
			left = false;
			up = true;
			return false;
		}
		else
		{
			up = false;

			if (tempRot < 170 && tempRot > -10)
			{
				right = false;
				left = true;
				return false;
			}
			else
			{
				left = false;
				right = true;
				return false;
			}

		}

	}
	else
	{
		return true;
	}

}

void AIPlayer::finalBurn(sf::Vector2f& movementVec)
{

		up = false;

		if (tempRot < 0)
		{
			left = false;
			right = true;
			return;
		}
		else if (tempRot > 0)
		{
			right = false;
			left = true;
			return;
		}

		if (tempRot == 0)							// suicide burn
		{
			//distanceBeforeStop = (movementVec.y * movementVec.y) / (lander.getAcceleration() * 2.f); // FIX !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

			//if (distanceBeforeStop >= 0.035f)
			//{

			if (movementVec.y > maxImpactY * 0.95f)
			{
				up = true;
				return;
			}
			else
			{
				up = false;
				return;
			}

		}

}

