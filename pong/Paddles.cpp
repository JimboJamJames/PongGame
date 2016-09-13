
#include <cstdio>
#include <cstdlib>
#include "Paddles.h"
#include "Header.h"
#include "GameState.h"

void Paddle1::init()
{
	
}
void Paddle1::update()
{
	if (sfw::getKey('I') && y < 400)
		y += sfw::getDeltaTime() * 600;

	if (sfw::getKey('K') && y > 0)
		y -= sfw::getDeltaTime() * 600;

}
void Paddle1::draw() const
{
	sfw::drawLine(x, y, x, y + size, BLUE);
}
void Paddle2::init()
{

}
void Paddle2::update()
{
	if (sfw::getKey('W') && y < 400)
		y += sfw::getDeltaTime() * 900;

	if (sfw::getKey('S') && y > 0)
		y -= sfw::getDeltaTime() * 900;

}
void Paddle2::draw() const
{
	sfw::drawLine(x, y, x, y + size, RED);
}



void Paddle::init(float a_x, float a_y, float a_size, char a_up, char a_down, unsigned a_color)
{
	x     = a_x;
	y     = a_y;
	size  = a_size;
	up    = a_up;
	down  = a_down;
	color = a_color;
}

void Paddle::update()
{
	if (sfw::getKey(up) && y < 400)
		y += sfw::getDeltaTime() * 900;

	if (sfw::getKey(down) && y > 0)
		y -= sfw::getDeltaTime() * 900;
}

void Paddle::draw() const
{
	sfw::drawLine(x, y, x, y + size, color);
}
