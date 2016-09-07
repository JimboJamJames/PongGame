#pragma once
#include "Struct.h"
void Collision(Ball &circle)
{
	if (circle.ballX + 10 >= 800)
	{
		circle.momentumX = circle.momentumX * -1;
	}
	if (circle.ballX - 10 <= 0)
	{
		circle.momentumX = circle.momentumX * -1;
	}
	if (circle.ballY + 10 >= 600)
	{
		circle.momentumY = circle.momentumY * -1;
	}
	if (circle.ballY - 10 <= 0)
	{
		circle.momentumY = circle.momentumY * -1;
	}
}
void Collision2(Ball &circle, const Paddle2 LeftPaddle)
{
	if (circle.ballX - 10 <= LeftPaddle.x &&circle.ballX + 10 >= LeftPaddle.x + 10)
	{
		if (circle.ballY - 10 <= LeftPaddle.y + 200 && circle.ballY + 10 >= LeftPaddle.y)
		{
			circle.momentumX = circle.momentumX * -1;
		}
	}

}
void Collision3(Ball &circle, const Paddle1 RightPaddle)
{
	if (circle.ballX + 10 >= RightPaddle.x &&circle.ballX - 10 <= RightPaddle.x + 10)
	{
		if (circle.ballY - 10 <= RightPaddle.y + 200 && circle.ballY + 10 >= RightPaddle.y)
		{
			circle.momentumX = circle.momentumX * -1;
		}
	}

}