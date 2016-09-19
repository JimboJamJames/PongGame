#include "GameState.h"

void GameState::init(int a_font)
{
	RightPaddle.init(750, 300, 200, 'I', 'K', RED, a_font);
	LeftPaddle.init(50, 300, 200, 'W','S', RED, a_font);
	font = a_font;
}

void GameState::update()
{
	switch (Collision(circle))
	{
	case 1: LeftPaddle.score++; break;
	case 2: RightPaddle.score++; break;
	}


	Collision2(circle, LeftPaddle);
	Collision3(circle, RightPaddle);

	LeftPaddle.update();
	RightPaddle.update();
	circle.update();
}


void GameState::draw() const
{
	LeftPaddle.draw();
	RightPaddle.draw();
	circle.draw();

	drawScore();
}

void GameState::drawScore() const
{
	char buffer[50];
	char buffer2[50];
	sprintf_s(buffer, 50, "P1 :: %d", LeftPaddle.score);
	sprintf_s(buffer2, 50, "P2 :: %d", RightPaddle.score);
	sfw::drawString(font, buffer, 200, 550, 16, 16, 0.0f, '\000', RED);
	sfw::drawString(font, buffer2, 470, 550, 16, 16, 0.0f, '\000', RED);
}
