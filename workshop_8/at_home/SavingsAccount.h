// Workshop 8 - Virtual Functions and Abstract Base Classes
// File: SavingsAccount.h
// Date: 11/15/2018
// Name: Omri Golan
// ID: 101160166
// Section: SGG
// Emai: ogolan1@myseneca.ca
///////////////////////////////////////////////////

#pragma once
#ifndef SICT_SAVINGSACCOUNT_H
#define SICT_SAVINGSACCOUNT_H
#include "Account.h"


namespace sict
{
	class SavingsAccount: public Account
	{
		private:
			double rate;

		public:
			SavingsAccount(double initialSavingsBalance, double interestRate);
			void monthEnd();
			void display(std::ostream &os) const;
	};
}

#endif