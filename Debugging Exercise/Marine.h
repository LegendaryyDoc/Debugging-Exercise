#pragma once

class Marine
{
public:
	Marine();
	~Marine();

	bool isAlive();

	int health = 50;
	int mAttack();
	void takeDamage(int damage);

};

