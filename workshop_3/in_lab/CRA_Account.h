/**********************************************************
// Workshop 3: Classes and Privacy
// File: CRA_Account.h
// Name: Omri Golan
// Student ID: 101160166
// Seneca email: ogolan1@myseneca.ca
// Section: SGG
// Date: 9/27/2018
//
///////////////////////////////////////////////////////////
**********************************************************/

#pragma once

#ifndef CRA_ACCOUNT_H
#define CRA_ACCOUNT_H

namespace sict
{
	const int max_name_length = 40; 
	const int min_sin = 100000000;
	const int max_sin = 999999999;
	const int max_yrs = 4;

	int alternates1[5] = { 0 }, alternates2[5] = { 0 };
	int index1 = 0, index2 = 0, index3 = 0;
	int sum_of_alts = 0, sum_of_alts2 = 0; 
	int sum_of_alts_total = 0, sum_of_alts_total_rounded = 0;
	int sin_check = 0; 
	int sin_arr[9] = { 0 }; 
	int alt_doubles[4] = { 0 }; 

	class CRA_Account
	{
	private:
		char family_name[max_name_length];
		char given_name[max_name_length];
		int SIN;
		int tax_return[max_yrs] = { 0 };
		double balance_or_refund[max_yrs] = { 0 };
		int tax_data;
		

	public:
		void set(const char* familyName, const char* givenName, int sin);
		void set(int year, double balance);
		bool isEmpty() const;
		void display() const;
	};
}

#endif