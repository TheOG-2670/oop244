// Workshop 7 - Derived Classes
// File Hero.cpp
// Date 11/9/2018
// Name Omri Golan
// Email ogolan1@myseneca.ca
// Section SGG
// ID 101160166
/////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Hero.h"
using namespace std;
using namespace sict;

namespace sict
{
	Hero::Hero() //default constructor initialize hero details
	{
		heroName[0] = '\0';
		heroHealth = 0;
		heroAttackStrength = 0;
	}

	Hero::Hero(const char *name, int health, int attack) //grab hero info
	{
		if (name != nullptr && health > 0 && attack > 0) //check if info is valid
		{
			
			strncpy(heroName, name, 39); //copy hero's name to 'heroName' class variable

			heroHealth = health;// copy hero's health to 'heroHealth' class variable

			heroAttackStrength = attack; //copy hero's attack strength to 'heroAttackStrength' class variable
		}
		else //if any data is invalid, set hero to safe empty state
		{
			
			heroName[0] = '\0';
			heroHealth = 0;
			heroAttackStrength = 0;
		}
	}

	void Hero::operator-=(int attack) //left hero attacked by right hero
	{
		if (attack > 0) //attack value is above 0
		{
			if (heroHealth <= 0) //hero's health is 0 or less
			{
				heroHealth = 0; //set hero's health to 0
			}
			else
			{
				heroHealth = heroHealth - attack; //deplete hero's health by attack value
			}
			
			
		}
	}

	bool Hero::isAlive() const //check if hero is still alive
	{
		if (heroHealth > 0)
		{
			return true; //return true if hero's health is above 0
		}
		else
		{
			return false;
		}
	}

	int Hero::attackStrength() const //get hero's attack strength
	{
		if (heroAttackStrength > 0)
		{
			return heroAttackStrength;
		}
		else
		{
			return 0;
		}
	}

	const char *Hero::name() //get hero's name
	{
		return heroName;
	}


	std::ostream& operator<<(std::ostream &os, const Hero& hero)
	{
		Hero localName = hero; //temporary object to hold 'hero' class reference

		if (strcmp(localName.name(), "")) //if name is not empty
		{
			
			return os << localName.name(); //send 'hero' object to output stream
		}
		else
		{
			return os << "No hero" << endl;; //if name is empty, display message
			
		}
	
	}


	const Hero& operator*(const Hero &first, const Hero &second)
	{
		Hero localFirst = first, localSecond = second; //assign Hero class references to local objects
		int roundNumber=0; //increasing round number


		cout << "Ancient Battle! ";
		cout<< localFirst.name() << " vs " << localSecond.name() <<" : "; //print hero names

		for (int index = roundNumber; index < MAX_ROUNDS; index++) //attack rounds
		{
	
				localFirst -= localSecond.attackStrength(); //second attacks first
				localSecond -= localFirst.attackStrength(); //first attacks second

				if (localFirst.isAlive() == false) //first is dead
				{
					//declare second as winner
					cout << "Winner is " << localSecond.name() << " in " << index+1<<" rounds."<<endl;
					return second; //return second
				}

				//second is dead or max round limit reached
				else if (localSecond.isAlive() == false || index == MAX_ROUNDS) 
				{
					//declare first as winner
					cout << "Winner is " << localFirst.name() << " in " << index+1<< " rounds." << endl;
					return first; //return first
				}
			
		}

		return first;
		return second;
	}

}