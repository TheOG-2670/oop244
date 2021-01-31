// Workshop 6 - Class with a Resource
// file: Contacts.cpp
// Name: Omri Golan
// Date: 12/17/2018
// ID: 101160166
// email: ogolan1@myseneca.ca
// section: SGG
// *PRACTICE COPY
/////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include "Contact.h"
using namespace std;
using namespace sict;

namespace sict
{
	Contact::Contact() //default constructor
	{
		contactName[0] = '\0';
		validPhoneNumbers = nullptr;
		numOfValidNums = 0;
	}

	Contact::Contact(const char *name, const long long *phoneNums, int num) //parameterized constructor
	{
		if (name != nullptr && name[0] != '\0') //check if contact name exists
		{
			strncpy(contactName, name, MAX_CHAR); //copy contact name to class variable

			phoneValidation(phoneNums, num); //run through phone number validation

		}
		else
		{
			*this = Contact(); //set cuurent object to empty state
		}
	}


	void Contact::phoneValidation(const long long *phoneNums, int num)
	{
		string currentPhone;
		long long validNums[10] = { 0 };
		numOfValidNums = 0;
		int indexCount = 0;
	

		for (int index = 0; index < num; index++) //run through all phone numbers in original array
		{

			currentPhone = to_string(phoneNums[index]); //convert current phone number to string

			if (currentPhone.length() > 10 && currentPhone.length() < 13) //check length of phone number
			{

				numOfValidNums++; //increase valid phone number count

				if (validNums[index - indexCount] == 0) //move phone number up array to replace 0s where invalid phone numbers are
				{
					validNums[index - indexCount] = phoneNums[index];
				}

			}
				
			else
			{
				indexCount++; //increase index count for invalid phone numbers
			}
			
		}

		validPhoneNumbers = new long long[numOfValidNums]; //allocate new memory for dynamic array to hold valid phone numbers
		for (int index = 0; index < numOfValidNums; index++)
		{
			validPhoneNumbers[index] = validNums[index]; //copy valid phone numbers to new array
		}


	}


	Contact::~Contact() //deallocate dynamic memory from valid phone number array
	{
		delete[] validPhoneNumbers;
		validPhoneNumbers = nullptr;
	}


	bool Contact::isEmpty() const 
	{
		if (contactName[0]=='\0' || contactName == nullptr) //check if current object is empty via contact's name
		{
			return true;
		}
		else
		{
			return false;
		}
	}


	Contact::Contact(const Contact &c)
	{
		*this = c;
	}


	Contact& Contact::operator=(const Contact &c)
	{
		if (this != &c)
		{
			strncpy(contactName, c.contactName, MAX_CHAR - 1);
			numOfValidNums = c.numOfValidNums;
			validPhoneNumbers = c.validPhoneNumbers;

			phoneValidation(validPhoneNumbers, numOfValidNums);
		}
		
		return *this;
	}


	Contact& Contact::operator+=(const long long newNumber)
	{
		string currentPhone;
		static long long tempArray[10];

		currentPhone = to_string(newNumber);

		
		if (currentPhone.length() > 10 && currentPhone.length() < 13)
		{
			numOfValidNums++;

			for (static int index = 0; index < numOfValidNums; index++)
			{
				tempArray[index] = newNumber;
			}

			validPhoneNumbers = new long long[numOfValidNums];
			for (int index = 0; index < numOfValidNums; index++)
			{
				validPhoneNumbers[index] = tempArray[index];
			}
			
		}

		return *this;
	}


	void Contact::display() const
	{
		if (isEmpty() == true)
		{
			cout << "Empty contact!" << endl; //print if current object's contact name is empty
		}
		else
		{
			cout << contactName << endl; //print contact name

			for (int index = 0; index < numOfValidNums; index++) //run through array of valid phone numbers
			{
				string currentPhone = to_string(validPhoneNumbers[index]); //convert each phone number to string

				if (currentPhone.length() < 12) //phone numbers 11 characters long
				{
					cout << "(+" << currentPhone[0] << ") "; //country code

					for (int index1 = 1; index1 < currentPhone.length(); index1++) //rest of phone number
					{
						if (index1 == 4) //space after area code
						{
							cout << " ";
						}
						else if (index1 == 7) //dash between first 3 and last 4 numbers
						{
							cout << '-';
						}
						cout << currentPhone[index1];
					}
				}
				else if (currentPhone.length() < 13) //phone number 12 characters long
				{
					cout << "(+" << currentPhone[0] << currentPhone[1] << ") "; //country code
					
					for (int index1 = 2; index1 < currentPhone.length(); index1++) //rest of phone number
					{
						if (index1 == 5) //space after area code
						{
							cout << " ";
						}
						else if (index1 == 8) //dash between first 3 and last 4 numbers
						{
							cout << '-';
						}

						cout << currentPhone[index1];
					}

				}
				cout << endl;
			}
		}
	}
		
	
}