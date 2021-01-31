// Workshop 8 - Virtual Functions and Abstract Base Classes
// File: Allocator.cpp
// Date: 11/15/2018
// Name: Omri Golan
// ID: 101160166
// Section: SGG
// Emai: ogolan1@myseneca.ca
///////////////////////////////////////////////////

#include <iostream>
#include "iAccount.h"
#include "Account.h"
#include "SavingsAccount.h"
using namespace std;

namespace sict
{
	const double INTEREST = 0.05;
	iAccount* CreateAccount(const char *accountType, double initialBalance)
	{

		if (accountType[0] == 'S' || accountType[0] == 's')
		{
			SavingsAccount *newAccount;
			newAccount = new SavingsAccount(initialBalance, INTEREST);
			return newAccount;
		}
		else
		{
			return nullptr;
		}
	}
}
