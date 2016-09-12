#include "Header.h"
#include <iostream>
#include "Collisions.h"
#include "Struct.h"
#include "GameState.h"


void main()
{

	sfw::initContext(800, 600, "SFW Draw");
	Ball circle;
	Paddle1 RightPaddle;
	Paddle2 LeftPaddle;

	float acc = 0;
	char c = '\0';

	
	bool isXPositive = false, isYPositive = true;

	sfw::setBackgroundColor(BLACK);

	GameState gs;

	while (sfw::stepContext())
	{
		updateGameState(gs);
		drawGameState(gs);
			Collision(circle);
			Collision2(circle, LeftPaddle);
			Collision3(circle, RightPaddle);
			if (sfw::getKey('W')&&LeftPaddle.y < 400)
				LeftPaddle.y += sfw::getDeltaTime() * 900;
			
			if (sfw::getKey('S') && LeftPaddle.y > 0)
				LeftPaddle.y -= sfw::getDeltaTime() * 900;


			if (sfw::getKey('I') && RightPaddle.y < 400)
				RightPaddle.y += sfw::getDeltaTime() * 600;

			if (sfw::getKey('K') && RightPaddle.y > 0)
				RightPaddle.y -= sfw::getDeltaTime() * 600;

			
			gs.circle.ballX = gs.circle.ballX + gs.circle.momentumX;
			gs.circle.ballY = gs.circle.ballY + gs.circle.momentumY;

			sfw::drawLine(gs.LeftPaddle.x, gs.LeftPaddle.y, gs.LeftPaddle.x, gs.LeftPaddle.y + gs.LeftPaddle.size, RED);

			sfw::drawLine(gs.RightPaddle.x, gs.RightPaddle.y, gs.RightPaddle.x, gs.RightPaddle.y + gs.RightPaddle.size, RED);

			sfw::drawCircle(gs.circle.ballX, gs.circle.ballY, 10, 20, CYAN);
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
