#include "Marine.h"



Marine::Marine()
{
}


Marine::~Marine()
{
}

int Marine::mAttack()
{
	return 9;
}

void Marine::takeDamage(int damage)
{
	health -= damage;
	if (health < 0)
	{
		health = 0;
	}
}

bool Marine::isAlive()
{
	if (health > 0)
	{
		return true;
	}
	return false;
}

