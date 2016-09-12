#include "GameState.h"

void GameState::init()
{
	
}

void GameState::update()
{
	Collision(circle);
	Collision2(circle, LeftPaddle);
	Collision3(circle, RightPaddle);


	if (sfw::getKey('W') && LeftPaddle.y < 400)
		LeftPaddle.y += sfw::getDeltaTime() * 900;

	if (sfw::getKey('S') && LeftPaddle.y > 0)
		LeftPaddle.y -= sfw::getDeltaTime() * 900;


	if (sfw::getKey('I') && RightPaddle.y < 400)
		RightPaddle.y += sfw::getDeltaTime() * 600;

	if (sfw::getKey('K') && RightPaddle.y > 0)
		RightPaddle.y -= sfw::getDeltaTime() * 600;


	circle.update();
}


void GameState::draw() const
{
	sfw::drawLine(LeftPaddle.x, LeftPaddle.y, LeftPaddle.x, LeftPaddle.y + LeftPaddle.size, RED);

	sfw::drawLine(RightPaddle.x, RightPaddle.y, RightPaddle.x, RightPaddle.y + RightPaddle.size, RED);

	circle.draw();
}