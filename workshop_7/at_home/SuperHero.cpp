// Workshop 7 - Derived Classes
// File SuperHero.cpp
// Date 11/11/2018
// Name Omri Golan
// Email ogolan1@myseneca.ca
// Section SGG
// ID 101160166
/////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "SuperHero.h"
using namespace std;
using namespace sict;

namespace sict
{
	SuperHero::SuperHero()
	{
		superHeroAttackBonus = 0;
		superHeroDefendStrength = 0;
	}

	SuperHero::SuperHero(const char *name, int health, int attack, int attackBonus, int defend) : Hero(name, health, attack)
	{
		if (attackBonus > 0 && defend > 0)
		{

			superHeroAttackBonus = attackBonus;
			superHeroDefendStrength = defend;
		}


		else
		{

			superHeroAttackBonus = 0;
			superHeroDefendStrength = 0;
		}
	}


	int SuperHero::attackStrength() const
	{
		if (Hero::attackStrength() > 0)
		{
			return Hero::attackStrength()+superHeroAttackBonus;
		}
		else
		{
			return 0;
		}
	}

	int SuperHero::defend() const
	{
		if (superHeroDefendStrength > 0)
		{
			return superHeroDefendStrength;
		}
		else
		{
			return 0;
		}
	}


	const SuperHero& operator*(const SuperHero& first, const SuperHero& second)
	{

		SuperHero localFirst = first, localSecond = second;

		cout << "Super Fight! ";
		cout << localFirst.name() << " vs " << localSecond.name();

		for (int index = 0; index < MAX_ROUNDS; index++)
		{
			
			localFirst -= localSecond.attackStrength() - localFirst.defend();
			localSecond -= localFirst.attackStrength() - localSecond.defend();

			//first is dead
			if (localFirst.isAlive() == false)
			{
				cout << " : Winner is " << localSecond.name() << " in " << index+1 << " rounds." << endl;
				return second;
			}
			//second is dead or max round limit reached
			else if (localSecond.isAlive() == false || index == MAX_ROUNDS)
			{
				//declare first as winner
				cout << " : Winner is " << localFirst.name() << " in " << index + 1 << " rounds." << endl;
				return first; //return first
			}
		
		}
		return first;
		return second;

	}


}