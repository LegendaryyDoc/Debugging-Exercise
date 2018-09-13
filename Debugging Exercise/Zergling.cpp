#include "Zergling.h"



Zergling::Zergling()
{
}


Zergling::~Zergling()
{
}

int Zergling::zAttack()
{
	return 5;
}

void Zergling::takeDamage(int damage)
{
	health -= damage;
	if (health < 0)
	{
		health = 0;
	}
}

bool Zergling::isAlive()
{
	if (health > 0)
	{
		return true;
	}
	return false;
}

