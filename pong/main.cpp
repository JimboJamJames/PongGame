#include "Header.h"
#include <iostream>

using namespace sfw;
struct Ball
{
	float ballX = 400, ballY = 300;
	float momentumX = 10;
	float momentumY = 10;

};
struct Paddle2
{
	float x = 50, y = 300;
	float size = 200;
};
struct Paddle1
{
	float x = 750, y = 300;
	float size = 200;
};
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
		if (circle.ballY - 10 <= LeftPaddle.y +200 &&circle.ballY + 10 >= LeftPaddle.y)
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
void main()
{
	Ball circle;
	Paddle1 RightPaddle;
	Paddle2 LeftPaddle;
	sfw::initContext(800, 600, "SFW Draw");
	float acc = 0;
	char c = '\0';

	
	bool isXPositive = false, isYPositive = true;

	sfw::setBackgroundColor(BLACK);

	
	while (sfw::stepContext())
	{
			Collision(circle);
			Collision2(circle, LeftPaddle);
			Collision3(circle, RightPaddle);
			if (sfw::getKey('W')&&LeftPaddle.y < 400)
				LeftPaddle.y += sfw::getDeltaTime() * 900;
			
			if (sfw::getKey('S') && LeftPaddle.y > 0)
				LeftPaddle.y -= sfw::getDeltaTime() * 900;

			sfw::drawLine(LeftPaddle.x, LeftPaddle.y, LeftPaddle.x, LeftPaddle.y + LeftPaddle.size, PURPLE);

			if (sfw::getKey('I') && RightPaddle.y < 400)
				RightPaddle.y += sfw::getDeltaTime() * 600;

			if (sfw::getKey('K') && RightPaddle.y > 0)
				RightPaddle.y -= sfw::getDeltaTime() * 600;

			sfw::drawLine(RightPaddle.x, RightPaddle.y, RightPaddle.x, RightPaddle.y + RightPaddle.size, RED);
			
			circle.ballX = circle.ballX + circle.momentumX;
			circle.ballY = circle.ballY + circle.momentumY;
	
			sfw::drawCircle(circle.ballX, circle.ballY, 10, 20, WHITE);
	}
sfw::termContext();
}

