#include "Header.h"
#include <iostream>
#include "Collisions.h"
#include "Struct.h"
#include "GameState.h"


void main()
{
	sfw::initContext(800, 600, "SFW Draw");
	sfw::setBackgroundColor(BLACK);

	unsigned back = sfw::loadTextureMap("DeepSpace.png");

	GameState gs;

	gs.init();

	while (sfw::stepContext())
	{
		sfw::drawTexture(back, 0, 600, 800, 600,0,false);
		gs.update();
		gs.draw();
	}

	sfw::termContext();
}