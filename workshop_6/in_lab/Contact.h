// Workshop 6 - Class with a Resource
// file: Contacts.h
// Name: Omri Golan
// Date: 11/4/2018
// ID: 101160166
// email: ogolan1@myseneca.ca
// section: SGG


#pragma once
#ifndef CONTACT_H
#define CONTACT_H

namespace sict
{
	const int MAX_CHAR = 20;

	class Contact
	{
		private:		
			char name[MAX_CHAR];
			long long *phoneNumbers;
			int number;
			void phoneNumCheck(long long *phone);


		public:
			Contact();
			Contact(const char *name_, long long *phoneNums, int num);
			~Contact();
			bool isEmpty() const;
			void display() const;
	};
}

#endif