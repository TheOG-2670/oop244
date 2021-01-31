// Workshop 8 - Virtual Functions and Abstract Base Classes
// File: SavingsAccount.cpp
// Date: 11/15/2018
// Name: Omri Golan
// ID: 101160166
// Section: SGG
// Emai: ogolan1@myseneca.ca
///////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include "Account.h"
#include "iAccount.h"
#include "SavingsAccount.h"
using namespace std;
using namespace sict;

SavingsAccount::SavingsAccount(double initialSavingsBalance, double interestRate):Account(initialSavingsBalance)
{
	if (interestRate > 0)
	{
		rate = interestRate;

	}
	else
	{
		rate = 0.0;
	}
}

void SavingsAccount::monthEnd()
{
	double interest = 0.0;
	interest = rate * balance();
	credit(interest);
}

void SavingsAccount::display(std::ostream &os) const
{
	os << "Account type: Savings" << endl
		<< "Balance: $" << fixed << setprecision(2) << balance() << endl
		<< "Interest Rate (%): " << fixed << setprecision(2) << (rate*100)<<endl;
}