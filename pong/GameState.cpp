#include "GameState.h"

void GameState::init()
{
	RightPaddle.init(750, 300, 200, 'I', 'K', BLUE);
	LeftPaddle.init(50, 300, 200, 'W','S', RED);
}

void GameState::update()
{
	Collision(circle);
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
}