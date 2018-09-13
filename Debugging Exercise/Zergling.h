#pragma once

class Zergling
{
public:
	Zergling();
	~Zergling();

	int health = 50;
	int zAttack();
	void takeDamage(int damage);

	bool isAlive();

};

