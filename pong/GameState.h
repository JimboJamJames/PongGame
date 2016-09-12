#pragma once
#include "Struct.h"
#include <iostream>
#include "Header.h"
#include "Collisions.h"


struct GameState
{
	Ball circle;
	Paddle1 RightPaddle;
	Paddle2 LeftPaddle;

	float acc = 0;
	char c = '\0';


	bool isXPositive = false, isYPositive = true;
};

GameState createGameState();

void updateGameState(GameState &gs);
void drawGameState(const GameState &gs);