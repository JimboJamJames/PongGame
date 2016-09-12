#pragma once

class Zombie
{
private:
	char name[64], prior[64];
	int health, attack, critRate, kills;

public:
	void init(const char a_name[], const char a_occ[]);

	void takeDamage(int dmg);

	int  rollAttack()     const;
	void draw(bool brief) const;
	bool isAlive()        const;
};