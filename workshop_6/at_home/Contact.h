// Workshop 6 - Class with a Resource
// file: Contacts.cpp
// Name: Omri Golan
// Date: 12/17/2018
// ID: 101160166
// email: ogolan1@myseneca.ca
// section: SGG
// *PRACTICE COPY
/////////////////////////////


#pragma once
#ifndef CONTACT_H
#define CONTACT_H

namespace sict
{
	const int MAX_CHAR = 20; //max number of characters for contact's name

	class Contact
	{
		private:		
			char contactName[MAX_CHAR-1]; //holds contacts name, excluding null byte ('\0')
			long long *validPhoneNumbers; //pointer to dynamic array of phone numbers
			int numOfValidNums; //current number of phone numbers in array
			void phoneValidation(const long long *phoneNumbers, int num);


		public:
			Contact();
			Contact(const char *name, const long long *phoneNums, int num);
			~Contact();
			bool isEmpty() const;
			void display() const;
			Contact(const Contact &c);
			Contact& operator=(const Contact &c);
			Contact& operator+=(const long long newNumber);
			
	};
}

#endif