#include "GameState.h"

GameState createGameState()
{
	return GameState();
}

void updateGameState(GameState &gs)
{
	Collision(gs.circle);
	Collision2(gs.circle, gs.LeftPaddle);
	Collision3(gs.circle, gs.RightPaddle);


	if (sfw::getKey('W') && gs.LeftPaddle.y < 400)
		gs.LeftPaddle.y += sfw::getDeltaTime() * 900;

	if (sfw::getKey('S') && gs.LeftPaddle.y > 0)
		gs.LeftPaddle.y -= sfw::getDeltaTime() * 900;


	if (sfw::getKey('I') && gs.RightPaddle.y < 400)
		gs.RightPaddle.y += sfw::getDeltaTime() * 600;

	if (sfw::getKey('K') && gs.RightPaddle.y > 0)
		gs.RightPaddle.y -= sfw::getDeltaTime() * 600;


	gs.circle.ballX = gs.circle.ballX + gs.circle.momentumX;
	gs.circle.ballY = gs.circle.ballY + gs.circle.momentumY;

}

void drawGameState(const GameState &gs)
{
	sfw::drawLine(gs.LeftPaddle.x, gs.LeftPaddle.y, gs.LeftPaddle.x, gs.LeftPaddle.y + gs.LeftPaddle.size, RED);

	sfw::drawLine(gs.RightPaddle.x, gs.RightPaddle.y, gs.RightPaddle.x, gs.RightPaddle.y + gs.RightPaddle.size, RED);

	sfw::drawCircle(gs.circle.ballX, gs.circle.ballY, 10, 20, CYAN);
}