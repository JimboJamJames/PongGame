#pragma once

enum APP_STATE
{
	TERMINATE,

	ENTER_SPLASH, SPLASH, // Intro Screen
	ENTER_DEPART, DEPART, // Say  goodbye!
	ENTER_OPTION, OPTION, // main menu
	ENTER_ACTION, ACTION, // Game state
};