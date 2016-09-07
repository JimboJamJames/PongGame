#pragma once
#include "Struct.h"
#include <iostream>
#include "Header.h"


struct GameState
{
	Paddle1 player1;
	float topBoundary, bottomBooundary;
	int p1score, p2score;
};

GameState createGameState();

void updateGameState(GameState &gs);
{

}
void drawGameState(const GameState &gs);
{

}