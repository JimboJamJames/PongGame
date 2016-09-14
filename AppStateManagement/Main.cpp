#include "sfwdraw.h"
#include "constdecl.h"
#include "Splash.h"
#include "Depart.h"
#include "Option.h"

void main()
{
	sfw::initContext(800, 600, "NSFW Draw");
	unsigned font = sfw::loadTextureMap("./res/fontmap.png", 16, 16);

	Splash splash;
	Depart depart;
	Option option;

	splash.init(font);
	depart.init(font);
	option.init(font);

	APP_STATE state = ENTER_SPLASH;

	bool quit = false;
	while (sfw::stepContext() && !quit)
	{
		switch (state)
		{
			// The Game State
		case ENTER_ACTION:
			// action.play();
		case ACTION:
			// action.step();
			// action.draw();
			// state = action.next();

			// Main Menu
		case ENTER_OPTION:
			option.play();
		case OPTION:
			option.step();
			option.draw();
			state = option.next();
			break;

			// Enter the program state
		case ENTER_SPLASH:
			splash.play();
		case SPLASH:
			splash.step();
			splash.draw();
			state = splash.next();
			break;

			// Leaving the application
		case ENTER_DEPART:
			depart.play();
		case DEPART:
			depart.step();
			depart.draw();
			state = depart.next();
			break;

		case TERMINATE: quit = true;
		}
	}
	sfw::termContext();
}