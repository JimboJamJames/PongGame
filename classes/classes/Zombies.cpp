#include "Zombies.h"
#include <cstdio>
#include <cstdlib>

int randRange(int min, int max) { return rand() % (max - min) + min; }

void Zombie::init(const char a_name[], const char a_occ[])
{
	sprintf_s(name, "%s", a_name);
	sprintf_s(prior, "%s", a_occ);
	health = randRange(90, 150);
	attack = randRange(10, 25);
	critRate = randRange(5, 25);
	kills = 0;
}

void Zombie::draw(bool brief) const
{
	printf("%s %s %d\n", name, prior, health);

	if (!brief)
		printf("\tHealth: %d\n\tAttack: %d\n", health, attack);
}

bool Zombie::isAlive() const { return health > 0; }

void Zombie::takeDamage(int dmg) { health -= dmg; }

int Zombie::rollAttack() const { return attack; }