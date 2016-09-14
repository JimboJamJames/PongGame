#include "Header.h"
#include <iostream>
#include "Collisions.h"
#include "Struct.h"
#include "GameState.h"
#include "Splash.h"
#include "Option.h"
#include "constdecl.h"

using namespace sfw;

void main()
{
	sfw::initContext(800, 600, "SFW Draw");
	sfw::setBackgroundColor(BLACK);
	unsigned font = sfw::loadTextureMap("./res/StartUp.png", 16, 16);
	unsigned back = sfw::loadTextureMap("DeepSpace.png");

	GameState gs;
	Splash splash;
	Option option;

	splash.init(font);
	option.init(font);

	APP_STATE state = ENTER_SPLASH;

	gs.init();
	splash.init(font);

	while (sfw::stepContext())
	{
		sfw::drawTexture(back, 0, 600, 800, 600, 0, false);
		gs.update();
		gs.draw();

		/*switch (state)
		{
		case ENTER_SPLASH:
			splash.play();
		case SPLASH:
			splash.step();
			splash.draw();
			state = splash.next();
			drawTexture(back, 0, 600, 800, 600, 0, false, 0, 0x88888888);
			setBackgroundColor(BLACK);
			break;
		case GAME:
			splash.step();
			splash.draw();
			state = splash.next();
			drawTexture(back, 400, 0, 400, 600, 0, false, 0, 0x88888888);
			setBackgroundColor(BLACK);
			break;
		}*/
	}

	sfw::termContext();
}