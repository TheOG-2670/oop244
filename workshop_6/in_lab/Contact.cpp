// Workshop 6 - Class with a Resource
// file: Contacts.cpp
// Name: Omri Golan
// Date: 11/4/2018
// ID: 101160166
// email: ogolan1@myseneca.ca
// section: SGG

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Contact.h"
using namespace std;
using namespace sict;

namespace sict
{
	Contact::Contact()
	{
		name[0] = { '\0' };
		phoneNumbers = nullptr;
		number = 0;
	}

	Contact::Contact(const char *name_, long long *phoneNums, int num)
	{
		if (name_ != '\0')
		{
			strncpy(name, name_, MAX_CHAR);
		}
		else
		{
			name[0] = '\0';
		}
			
		if (phoneNums != nullptr && num != 0)
		{
			number = num;
			phoneNumbers = phoneNums;
			phoneNumCheck(phoneNumbers);
		}
		
		else
		{
			phoneNumbers = nullptr;
			number = 0;
		}
	}

	void Contact::phoneNumCheck(long long *phone)
	{
		long long valid = 0, countryCode = 0;
		int count = 0, arrCount = 0;
		
		phoneNumbers = new long long[arrCount];
		for (int index = 0; index < number; index++)
		{
			
			valid = 0;
			countryCode = 0;
			count = 0;
			
			while (phone[index] > 0)
			{
				valid = valid * 10 + phone[index] % 10;
				phone[index] = phone[index] / 10;
				count++;
			}

			
			if (count > 10 && count < 13)
			{
				
				count = 0;
				phoneNumbers[arrCount] = 0;
					
				while (valid > 0)
				{
					
					countryCode = countryCode * 10 + valid % 10;

					if (countryCode==1 || countryCode == 12)
					{
						phoneNumbers[arrCount] = phoneNumbers[arrCount] * 10 + countryCode % 10;
					}
					
					if (count == 2)
					{
						arrCount++;
						phoneNumbers[arrCount] = 0;
					}

					else if (count >= 4 && count <= 6 )
					{
						phoneNumbers[arrCount] = phoneNumbers[arrCount] * 10 + countryCode % 10;
					}

					if (count == 6)
					{
						arrCount++;
						phoneNumbers[arrCount] = 0;

					}
					else if (count >= 7 && count <= 10)
					{
						phoneNumbers[arrCount] = phoneNumbers[arrCount] * 10 + countryCode % 10;
					}

					if (count == 10)
					{
						arrCount++;
						phoneNumbers[arrCount] = 0;
					}
				
					
					count++;
					valid = valid /10;
				}
				
			}
			
		}
		number = arrCount;
	}

	Contact::~Contact()
	{
		delete[] phoneNumbers;
		phoneNumbers = nullptr;
	}

	bool Contact::isEmpty() const
	{
		if (name[0] != '\0' || phoneNumbers != nullptr || number != 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	void Contact::display() const
	{
	
		if (isEmpty() == false && name[0]!='\0')
		{
			cout << name << endl;
		}
		else
		{
			cout << "Empty contact!" << endl;
		}

		if (isEmpty() == false && phoneNumbers!=nullptr)
		{
			for (int index = 0; index < number; index++)
			{
				if (phoneNumbers[index] == 1 || phoneNumbers[index] == 12)
				{
					cout << "(+" << phoneNumbers[index] << ") ";
				}
				else if (phoneNumbers[index - 1] == 1 || phoneNumbers[index - 1] == 12)
				{
					cout << 416 << " ";
				}
				else if (phoneNumbers[index] != 416)
				{
					if (phoneNumbers[index] == 2)
					{
						cout << phoneNumbers[index - 1] << "-000" << phoneNumbers[index] << endl;
					}
					else
					{
						cout << phoneNumbers[index - 1] << "-" << phoneNumbers[index] << endl;
					}

				}


			} 
		}
		
	
	}
}