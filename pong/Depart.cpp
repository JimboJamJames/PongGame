#include "Depart.h"
#include "Header.h"
#include <cstdio>

void Depart::init(int a_font) { font = a_font; }
void Depart::draw()
{
	char buffer[80];
	sprintf_s(buffer, "press A to go away");
	sfw::drawString(font, buffer, 100, 100, 16, 16);
}

APP_STATE Depart::next()
{
	if (sfw::getKey('a'))
		return TERMINATE;

	return DEPART;
}