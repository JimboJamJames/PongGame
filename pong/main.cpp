#include "Header.h"
#include <iostream>
#include "Collisions.h"
#include "Struct.h"
#include "GameState.h"
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

			sfw::drawLine(LeftPaddle.x, LeftPaddle.y, LeftPaddle.x, LeftPaddle.y + LeftPaddle.size, RED);

			if (sfw::getKey('I') && RightPaddle.y < 400)
				RightPaddle.y += sfw::getDeltaTime() * 600;

			if (sfw::getKey('K') && RightPaddle.y > 0)
				RightPaddle.y -= sfw::getDeltaTime() * 600;

			sfw::drawLine(RightPaddle.x, RightPaddle.y, RightPaddle.x, RightPaddle.y + RightPaddle.size, RED);
			
			circle.ballX = circle.ballX + circle.momentumX;
			circle.ballY = circle.ballY + circle.momentumY;
	
			sfw::drawCircle(circle.ballX, circle.ballY, 10, 20, CYAN);
	}
sfw::termContext();
}
void gameState()
{
	sfw::initContext(800, 600, "NSFW Draw");
	sfw::setBackgroundColor(BLACK);

	GameState gs = createGameState();

	while (sfw::stepContext())
	{
		updateGameState(gs);
		drawGameState(gs);
	}
	sfw::termContext();
}
