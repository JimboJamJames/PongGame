#include "Header.h"
#include <iostream>
#include "Collisions.h"
#include "Struct.h"
#include "GameState.h"
#include "Splash.h"
#include "Option.h"
#include "constdecl.h"
#include "Depart.h"

using namespace sfw;

void main()
{
	sfw::initContext(800, 600, "SFW Draw");
	sfw::setBackgroundColor(BLACK);
	unsigned front = sfw::loadTextureMap("./StartUp.jpg");
	unsigned back = sfw::loadTextureMap("./DeepSpace.png");
	unsigned font = sfw::loadTextureMap("./fontmap.png", 16,16);
	GameState gs;
	Splash splash;
	Depart depart;
	Option option;

	splash.init(font);
	option.init(font);
	depart.init(font);

	APP_STATE state = ENTER_SPLASH;

	gs.init(font);
	

	bool quit = false;
	while (sfw::stepContext() && !quit)
	{
		sfw::drawTexture(back, 0, 600, 800, 600, 0, false);

		switch (state)
		{
		case ENTER_SPLASH:
			splash.play();
		case SPLASH:
			splash.step();
			splash.draw();
			state = splash.next();
			drawTexture(front, 0, 600, 800, 600, 0, false, 0, 0x88888888);
			setBackgroundColor(WHITE);
			break;
		case GAME:
			gs.update();
			
			drawTexture(back, 400, 0, 400, 600, 0, false, 0, 0x88888888);
			gs.draw();
			

			setBackgroundColor(WHITE);
			break;
		

		case TERMINATE: quit = true;
		}
	}

	sfw::termContext();
}