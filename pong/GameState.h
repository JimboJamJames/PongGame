#pragma once
#include "Struct.h"
#include <iostream>
#include "Header.h"
#include "Collisions.h"
#include "Ball.h"
#include "Paddles.h"

class GameState
{
public: 
	Ball circle;
	
	Paddle RightPaddle, LeftPaddle;

	float acc = 0;
	char c = '\0';
	int font;

	bool isXPositive = false, isYPositive = true;

	void init(int a_font);		// load files, setup players, etc.
	void update();		// input, collision, movement
	void draw() const;
	void drawScore() const;
};