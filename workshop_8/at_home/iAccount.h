// Workshop 8 - Virtual Functions and Abstract Base Classes
// File: iAccount.h
// Date: 11/15/2018
// Name: Omri Golan
// ID: 101160166
// Section: SGG
// Emai: ogolan1@myseneca.ca
///////////////////////////////////////////////////

#pragma once
#ifndef SICT_IACCOUNT_H
#define SICT_IACCOUNT_H

namespace sict
{
	class iAccount
	{
		public:
			virtual bool credit(double) = 0;
			virtual bool debit(double) = 0;
			virtual void monthEnd() = 0;
			virtual void display(std::ostream &os) const = 0;
			virtual ~iAccount();
	};
	iAccount* CreateAccount(const char *accountType, double initialBalance);
}

#endif