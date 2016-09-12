#include <cstdio>
#include <cstdlib>
#include "GameState.h"

void main()
{
	GameState gs;
	gs.init();

	gs.start();
	while (!gs.isGameOver())
	{
		gs.update();
		gs.drawRound();
	}
	gs.drawWinner();
	getchar();
}