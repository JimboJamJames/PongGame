#include "Ball.h"
#include <cstdio>
#include <cstdlib>
#include "Header.h"

void Ball::init()
{
}

void Ball::update()
{
	ballX = ballX + momentumX;
	ballY = ballY + momentumY;
}

void Ball::draw() const
{
	sfw::drawCircle(ballX, ballY, 30, 30, RED);
}