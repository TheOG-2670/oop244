// Workshop 8 - Virtual Functions and Abstract Base Classes
// File: ChequingAccount.h
// Date: 11/18/2018
// Name: Omri Golan
// ID: 101160166
// Section: SGG
// Emai: ogolan1@myseneca.ca
///////////////////////////////////////////////////

#pragma once
#ifndef SICT_CHEQUINGACCOUNT_H
#define SICT_CHEQUINGACCOUNT_H

#include <iostream>
#include <iomanip>
#include "Account.h"

namespace sict
{
	class ChequingAccount: public Account
	{
		private:
			double transFee;
			double monthFee;
	

		public:
			ChequingAccount(double initialAccountBalance, double transactionFee, double monthEndFee);
			bool credit(double);
			bool debit(double);
			void monthEnd();
			void display(std::ostream &os) const;
	};
}

#endif