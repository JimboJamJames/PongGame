#include "Option.h"
#include "Header.h"
#include <cstdio>
#include "constdecl.h"

void Option::init(int a_font) { font = a_font; }
void Option::play() { select = 0; }

void Option::draw()
{
	sfw::drawString(font, "Prepare for War", 80, 140, 16, 16, 0, 0, WHITE);
	sfw::drawString(font, "GOTO (G)ame!", 80, 140, 16, 16, 0, 0, select == 1 ? RED : WHITE);
	sfw::drawString(font, "GOTO (A)way!", 80, 140, 16, 16, 0, 0, select == 0 ? WHITE : RED);
}
APP_STATE Option::next()
{
	if (sfw::getKey('G')) return ENTER_GAME;
	if (sfw::getKey('A')) return ENTER_DEPART;

		if (sfw::getKey(KEY_ENTER))
		{
			if (select == 0) return ENTER_DEPART;
			if (select == 1) return ENTER_GAME;
		}
		return OPTION;
}
