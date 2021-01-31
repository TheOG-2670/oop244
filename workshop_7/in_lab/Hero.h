// Workshop 7 - Derived Classes
// File Hero.h
// Date 11/9/2018
// Name Omri Golan
// Email ogolan1@myseneca.ca
// Section SGG
// ID 101160166
/////////////////////////////////////////////////////

#include <iostream>
#pragma once
#ifndef SICT_HERO_H
#define SICT_HERO_H

namespace sict
{
	const int MAX_ROUNDS = 100;

	class Hero
	{
		private:
			char heroName[40];
			int heroHealth;
			int heroAttackStrength;
			

		public:
			Hero();
			Hero(const char *name, int health, int attack);
			void operator-=(int attack);
			bool isAlive() const;
			int attackStrength() const;
			const char *name();
			friend std::ostream& operator<<(std::ostream &os, const Hero &hero);
			
	};

	
	const Hero& operator*(const Hero &first, const Hero &second);
}

#endif //SICT_HERO_H