// A Debugging Exercise by Marc Chee (marcc@aie.edu.au)
// 18/12/2016

// Marines are trying to "de-bug" an area (haha . . . haha)
// However something's up with this code . . . figure out what's going wrong
// When you're finished, there should be no compiler errors or warnings
// The encounter should also run and finish correctly as per the rules in the comments

// In many cases there are differences between what's in otherwise identical sections
// for Marines and Zerglings. It's good to be able to tell what the differences are
// and why they might be important.

// What's efficient and inefficient? Why?
// What uses more memory and what doesn't? Why?

// Last modified by Terry Nguyen (terryn@aie.edu.au)
// 10/09/2018

#include <iostream>
#include "Marine.h"
#include "Zergling.h"

using std::cout;
using std::endl;

size_t squadSize = 10;
size_t swarmSize = 20;

// Is there a Marine Alive?
bool marineAlive(Marine * squadArr, size_t arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		if (squadArr[i].isAlive())
		{
			return true;
		}
	}
	return false;
}

// Is there a zergling Alive
bool zerglingAlive(Zergling * swarmArr, size_t arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		if (swarmArr[i].isAlive())
		{
			return true;
		}
	}
	return false;
}

int main()
{
	Marine squad[10];
	Zergling swarm[20];

	cout << "A squad of marines approaches a swarm of Zerglings and opens fire! The Zerglings charge!"  << endl;
	// Attack each other until only one team is left alive
	while (marineAlive(squad, 10) && zerglingAlive(swarm, 20)) // If anyone is left alive to fight . . .
	{
		
		if (marineAlive(squad, 10) && zerglingAlive(swarm, 20)) // if there's at least one marine alive
		{
			for (size_t i = 0; i < squadSize; i++) // go through the squad
			{
				// each marine will attack the first zergling in the swarm
				cout << "A marine fires for " << squad[i].mAttack() << " damage. " << endl;
				int damage = squad[i].mAttack();
				swarm[swarmSize-1].takeDamage(damage);
				if (swarm[swarmSize-1].isAlive()) // if the zergling dies, it is marked as such
				{
					cout << "Zergling Lives" << endl;
					cout << "Swarm size " << swarmSize << endl;
					
				}
				else
				{
					cout << "The zergling target dies" << endl;
					swarmSize--;
					cout << "Swarm size " << swarmSize << endl;
				}
			}
		}
		
		if (zerglingAlive(swarm, 20) && marineAlive(squad, 10)) // if there's at least one zergling alive
		{
			for (size_t i = 0; i < swarmSize; i++) // loop through zerglings
			{
				cout << "A zergling attacks for " << swarm[i].zAttack() << " damage." << endl;
				int damage = swarm[i].zAttack();
				squad[squadSize-1].takeDamage(damage);
				if (squad[squadSize-1].isAlive())
				{
					cout << "Marine Lives" << endl;
					cout << "Squad size " << squadSize << endl;
				}
				else
				{

					cout << "The marine succumbs to his wounds." << endl;
					squadSize--;
					cout << "Squad size " << squadSize << endl;
					break;
				}
			}
		}
	}

	// Once one team is completely eliminated, the fight ends and one team wins
	cout << "The fight is over. " << endl;
	if (!marineAlive(squad, 10))
	{
		cout << "The Zerg win." << endl;
	}
	else
	{
		cout << "The Marines win." << endl;
	}
	return 0;
}




