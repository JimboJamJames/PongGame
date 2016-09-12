#include "Header.h"
#include <iostream>
#include "Collisions.h"
#include "Struct.h"
#include "GameState.h"


void main()
{
	sfw::initContext(800, 600, "SFW Draw");
	sfw::setBackgroundColor(BLACK);

	GameState gs;

	gs.init();

	while (sfw::stepContext())
	{
		gs.update();
		gs.draw();
	}

	sfw::termContext();
}