#include "Collisions.h"
#include "Ball.h"
#include "Paddles.h"

// returns 0 when no score occurs, 1 and 2 when players score (respectively)
int Collision(Ball &circle)
{
	if (circle.ballX + 10 >= 800)
	{
		circle.momentumX = circle.momentumX * -1;
		circle.ballX = 400;
		circle.ballY = 300;
		return 1;
	}
	if (circle.ballX - 10 <= 0)
	{
		circle.momentumX = circle.momentumX * -1;
		circle.ballX = 400;
		circle.ballY = 300;
		return 2;
	}
	if (circle.ballY + 10 >= 600)
	{
		circle.momentumY = circle.momentumY * -1;
	}
	if (circle.ballY - 10 <= 0)
	{
		circle.momentumY = circle.momentumY * -1;
	}

	return 0;
}

void Collision2(Ball &circle, const Paddle LeftPaddle)
{
	if (circle.ballX - 10 <= LeftPaddle.x &&circle.ballX + 10 >= LeftPaddle.x + 10)
	{
		if (circle.ballY - 10 <= LeftPaddle.y + 200 && circle.ballY + 10 >= LeftPaddle.y)
		{
			circle.momentumX = circle.momentumX * -1;
		}
	}

}

void Collision3(Ball &circle, const Paddle RightPaddle)
{
	if (circle.ballX + 10 >= RightPaddle.x &&circle.ballX - 10 <= RightPaddle.x + 10)
	{
		if (circle.ballY - 10 <= RightPaddle.y + 200 && circle.ballY + 10 >= RightPaddle.y)
		{
			circle.momentumX = circle.momentumX * -1;
		}
	}

}