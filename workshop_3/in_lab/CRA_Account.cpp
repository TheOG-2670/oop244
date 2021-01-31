/**********************************************************
// Workshop 3: Classes and Privacy
// File: CRA_Account.cpp
// Name: Omri Golan
// Student ID: 101160166
// Seneca email: ogolan1@myseneca.ca
// Section: SGG
// Date: 9/27/2018
//
///////////////////////////////////////////////////////////
**********************************************************/

#include <iostream>
#include <cstring>
#include "CRA_Account.h"
using namespace std;


namespace sict
{
	void CRA_Account::set(const char* familyName, const char* givenName, int sin)
	{

		if (sin >= min_sin && sin <= max_sin)
		{

			for (index1 = 8; index1 >= 0; index1--)
			{
				sin_arr[index1] = sin % 10;
				sin = sin / 10;
			}

			for (int index1 = 0; index1 < 9; index1++)
			{
				if (index1 % 2 != 0)
				{

					while (index2 < 4)
					{
						
						
						if (alternates1[index2] != 0)
						{
							
							alternates1[index2 + 1] = sin_arr[index1];
							index2++;
							break;
						}
						
						else
						{
							alternates1[index2] = sin_arr[index1];
							index2++;
							break;
						}
					}
				}

				else
				{
					while (index3 < 4)
					{

						if (alternates2[index3] != 0)
						{
							alternates2[index3 + 1] = sin_arr[index1];
							index3++;
							break;
						}
						else
						{
							alternates2[index3] = sin_arr[index1];
							index3++;
							break;
						}
					}
				}
			}

			for (int index1 = 0; index1 < sizeof(alternates1[4]); index1++)
			{
				alt_doubles[index1] = alternates1[index1] * 2;
				
			}

			for (int index1 = 0; index1 < sizeof(alt_doubles[4]); index1++)
			{
				sum_of_alts = sum_of_alts + (alt_doubles[index1] / 10);
				sum_of_alts = sum_of_alts + (alt_doubles[index1] % 10);
			}
			

			for (int index1 = 0; index1 < sizeof(alternates2[4]); index1++)
			{
				sum_of_alts2 = sum_of_alts2 + (alternates2[index1] / 10);
				sum_of_alts2 = sum_of_alts2 + (alternates2[index1] % 10);
			}
			
			sum_of_alts_total = sum_of_alts + sum_of_alts2;
			sum_of_alts_total_rounded = sum_of_alts_total;
			

			while (1)
			{
				if ((sum_of_alts_total_rounded % 10) == 0)
				{
					break;
				}
				sum_of_alts_total_rounded++;
			}
			

			sin_check = sum_of_alts_total_rounded - sum_of_alts_total;
			
			
			if (sin_arr[8] == sin_check)
			{
				for (index1 = 0; index1 <= 8; index1++)
				{
					sin = sin * 10 + sin_arr[index1];
				}
				
			}

			SIN = sin;
			tax_data = 0;
		}

		if (familyName != '\0' && givenName != '\0')
		{
			strncpy(family_name, familyName, max_name_length);
			family_name[max_name_length] = '\0';
			strncpy(given_name, givenName, max_name_length);
			given_name[max_name_length] = '\0';
		}

		else
		{
			family_name[max_name_length]='\0';
			given_name[max_name_length]='\0';
			SIN = 0;
		}

	}

	void CRA_Account::set(int year, double balance)
	{
		if (tax_data == 0)
		{
			for (int index = 0; index < max_yrs; index++)
			{
				tax_return[index] = { 0 };
				balance_or_refund[index] = { 0 };
			}
		}

			if (tax_data >= 0)
			{
				for (int index=tax_data; index < max_yrs; index++)
				{
					if(tax_return[index] != 0 && balance_or_refund[index] != 0)
					{
						tax_return[index + 1] = year;
						balance_or_refund[index + 1] = balance;
						break;
					}
					else
					{
						tax_return[index] = year;
						balance_or_refund[index] = balance;
						break;
					}
					
				}
			}
		tax_data++;
	}

	bool CRA_Account::isEmpty() const
	{
		if (SIN == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void CRA_Account::display() const
	{

		cout << "Family Name: " << family_name << endl;
		cout << "Given Name : " << given_name << endl;
		cout << "CRA Account: " << SIN << endl;

		for (int index = 0; index < tax_data; index++)
		{
			if (balance_or_refund[index] > 2)
			{
				
				cout << "Year (" << tax_return[index] << ") balance owing: " << balance_or_refund[index] << endl;
			}

			else if (balance_or_refund[index] > 2)
			{
				cout << "Year (" << tax_return[index] << ") refund due: " << balance_or_refund[index] << endl;
			}

			else if (tax_data == 0)
			{
				cout << "Account object is empty!" << endl;
			}

			else
			{
				cout << "Year (" << tax_return[index] << ") No balance owing or refund due!" << endl;
			}
		}
		
	}
}
