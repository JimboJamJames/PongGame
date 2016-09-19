
#include <cstdio>
#include <cstdlib>
#include "Paddles.h"
#include "Header.h"
#include "GameState.h"
#include <string>

void Paddle::init(float a_x, float a_y, float a_size, char a_up, char a_down, unsigned a_color, unsigned a_font)
{
	x     = a_x;
	y     = a_y;
	size  = a_size;
	up    = a_up;
	down  = a_down;
	color = a_color;
	font = a_font;
	score = 0;
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
	sfw::drawLine(x, y, x, y + size, WHITE);
	
}
