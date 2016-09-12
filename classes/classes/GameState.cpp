#include "GameState.h"
#include <cstdlib>
#include <cstdio>

void GameState::init()
{
	zombies[0].init("Madam", "Librarian");
	zombies[1].init("Susan", "Astronaut");
	zombies[2].init("Billy", "Reaper");
	zombies[3].init("Krypto", "Super Dog");
}

void GameState::start()
{
	printf("The contestants are:\n");
	drawStatus();
	printf("\nLet the battle Begin! Who will emerge victorious!\n");
}

void GameState::drawStatus() const
{
	for (int i = 0; i < Z_COUNT; ++i)
		zombies[i].draw(false);
}

void GameState::drawRound() const
{
	printf("\nCombat Round: \n");
	for (int i = 0; i < Z_COUNT; ++i)
		zombies[i].draw(false);
}


void GameState::update()
{
	for (int i = 0; i < Z_COUNT; ++i)
		if (zombies[i].isAlive())
			zombies[rand() % Z_COUNT].takeDamage(zombies[i].rollAttack());

}

bool GameState::isGameOver() const
{
	int livingZombies = 0;
	for (int i = 0; i < Z_COUNT; ++i)
		if (zombies[i].isAlive())
			livingZombies++;

	return livingZombies == 1;
}

void GameState::drawWinner() const
{
	printf("\n\n The battle is over!! \n");
	for (int i = 0; i < Z_COUNT; ++i)
		if (zombies[i].isAlive())
			zombies[i].draw(false);

	printf("The victor has emerged!");
}