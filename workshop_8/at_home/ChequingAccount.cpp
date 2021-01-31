// Workshop 8 - Virtual Functions and Abstract Base Classes
// File: ChequingAccount.cpp
// Date: 11/18/2018
// Name: Omri Golan
// ID: 101160166
// Section: SGG
// Emai: ogolan1@myseneca.ca
///////////////////////////////////////////////////

#include "ChequingAccount.h"
using namespace std;
using namespace sict;

ChequingAccount::ChequingAccount(double initialAccountBalance, double transactionFee, double monthEndFee): Account(initialAccountBalance)
{
	if (transactionFee > 0.0 && monthEndFee > 0.0)
	{
		transFee = transactionFee;
		monthFee = monthEndFee;
	}
	else
	{
		transFee = 0.0;
		monthFee = 0.0;
	}
}

bool ChequingAccount::credit(double amountAdd)
{
	if (amountAdd >0.0)
	{
		Account::credit(amountAdd);
		accountBalance = accountBalance - transFee;

		return true;
	}
	else
	{
		return false;
	}
	
}

bool ChequingAccount::debit(double amountRemove)
{
	if (amountRemove > 0.0)
	{
		Account::debit(amountRemove);
		accountBalance = accountBalance - transFee;
		return true;
	}
	else
	{
		return false;
	}
}

void ChequingAccount::monthEnd()
{
	accountBalance = accountBalance - monthFee;
}

void ChequingAccount::display(std::ostream &os) const
{
	os << "Account type: Chequing" << endl
		<< "Balance: $" << fixed << setprecision(2) << balance() << endl
		<< "Per Transaction Fee: " << fixed << setprecision(2) << transFee << endl
		<< "Monthly Fee: " << fixed << setprecision(2) << monthFee <<endl;
}