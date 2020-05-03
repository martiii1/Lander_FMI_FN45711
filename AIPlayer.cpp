#include "AIPlayer.hpp"


AIPlayer::AIPlayer()
{
	isRunning = false;
	left = false;
	right = false;
	up = false;
}


#define MIN_ERROR_SPEED 0.005f
void AIPlayer::calcNextMove(Lander &lander, sf::Vector2f &movementVec)
{
	int tempRot = (int)lander.getRotation();

	left = false;
	right = false;
	up = false;

	if (movementVec.x > MIN_ERROR_SPEED)						// kill sidways motion
	{
		if (tempRot == -90 || tempRot == 270)
		{
			up = true;
			return;
		}
		else
		{
			if (tempRot < 90 && tempRot > -90)
			{
				left = true;
				return;
			}
			else
			{
				right = true;
				return;
			}

		}

	}
	else if (movementVec.x < -MIN_ERROR_SPEED)					// kill sidways motion
	{
		if (tempRot == 90 || tempRot == -270)
		{
			up = true;
			return;
		}
		else
		{
			up = false;

			if (tempRot < -90 && tempRot > -270)
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
	}
	else											// suicide burn preparation
	{
		left = false;
		right = false;
		up = false;


		if (tempRot < 0)
		{
			left = false;
			right = true;
		}
		else if (tempRot > 0)
		{
			right = false;
			left = true;
		}

		if (tempRot == 0)							// suicide burn
		{


		}
			


	}
}

