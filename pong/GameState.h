#pragma once
#include "Struct.h"
#include <iostream>
#include "Header.h"
#include "Collisions.h"
#include "Ball.h"

struct GameState
{
	Ball circle;
	Paddle1 RightPaddle;
	Paddle2 LeftPaddle;

	float acc = 0;
	char c = '\0';


	bool isXPositive = false, isYPositive = true;

	void init();		// load files, setup players, etc.
	void update();		// input, collision, movement
	void draw() const;
};