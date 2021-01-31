// Workshop 8 - Virtual Functions and Abstract Base Classes
// File: Allocator.cpp
// Date: 11/18/2018
// Name: Omri Golan
// ID: 101160166
// Section: SGG
// Emai: ogolan1@myseneca.ca
///////////////////////////////////////////////////

#include <iostream>
#include "iAccount.h"
#include "Account.h"
#include "SavingsAccount.h"
#include "ChequingAccount.h"
using namespace std;

namespace sict
{
	const double interest = 0.05;
	const double transaction_fee = 0.50;
	const double month_fee = 2.00;

	iAccount* CreateAccount(const char *accountType, double initialBalance)
	{

		if (accountType[0] == 'S' || accountType[0] == 's')
		{
			SavingsAccount *newAccount;
			newAccount = new SavingsAccount(initialBalance, interest);
			return newAccount;
		}

		else if (accountType[0] == 'c' || accountType[0] == 'C')
		{
			ChequingAccount *newCAccount;
			newCAccount = new ChequingAccount(initialBalance, transaction_fee, month_fee);
			return newCAccount;
		}
		else
		{
			return nullptr;
		}
	}
}
