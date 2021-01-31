// Workshop 8 - Virtual Functions and Abstract Base Classes
// File: Account.cpp
// Date: 11/15/2018
// Name: Omri Golan
// ID: 101160166
// Section: SGG
// Emai: ogolan1@myseneca.ca
///////////////////////////////////////////////////

#include <iostream>
#include "Account.h"
using namespace std;
using namespace sict;

Account::Account(double initialBalance)
{
	if (initialBalance <= 0.0)
	{
		accountBalance = 0.0;
	}
	else
	{
		accountBalance = initialBalance;
	}
}


bool Account::credit(double amountAdd)
{
	if (amountAdd > 0)
	{
		accountBalance = accountBalance + amountAdd;
		return true;
	}
	else
	{ 
		return false;
	}
	
}

bool Account::debit(double amountRemove)
{
	if (amountRemove >0)
	{
		accountBalance = accountBalance - amountRemove;
		return true;
	}
	else
	{
		return false;
	}
}

double Account::balance() const
{
	return accountBalance;
}


iAccount::~iAccount()
{ }