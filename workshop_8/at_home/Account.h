// Workshop 8 - Virtual Functions and Abstract Base Classes
// File: Account.h
// Date: 11/15/2018
// Name: Omri Golan
// ID: 101160166
// Section: SGG
// Emai: ogolan1@myseneca.ca
///////////////////////////////////////////////////

#pragma once
#ifndef SICT_ACCOUNT_H
#define SICT_ACCOUNT_H
#include "iAccount.h"

namespace sict
{
	class Account : public iAccount
	{

		protected:
			double accountBalance;
			double balance() const;

		public:
			Account(double initialBalance);
			bool credit(double amountAdd);
			bool debit(double amountRemove);
	};
}

#endif