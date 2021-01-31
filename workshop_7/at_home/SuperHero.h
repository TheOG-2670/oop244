// Workshop 7 - Derived Classes
// File SuperHero.h
// Date 11/11/2018
// Name Omri Golan
// Email ogolan1@myseneca.ca
// Section SGG
// ID 101160166
/////////////////////////////////////////////////////

#include "Hero.h"
#pragma once
#ifndef SICT_SUPERHERO_H
#define SICT_SUPERHERO_H


namespace sict
{
	class SuperHero: public Hero
	{
		private:
			int superHeroAttackBonus;
			int superHeroDefendStrength;

		public:
			SuperHero();
			SuperHero(const char *name, int health, int attack, int attackBonus, int defend);
			int attackStrength() const;
			int defend() const;

	};

	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}

#endif