#include <iostream>
#include "Contact.h"
using namespace std;
using namespace sict;

int main(void)
{
	cout << "----------------------------------------" << endl;
	cout << "Maximum no of characters in a name: " << sict::MAX_CHAR << endl;
	cout << "----------------------------------------" << endl;
	cout << "Testing the default constructor!" << endl;
	sict::Contact empty;
	empty.display();
	cout << "----------------------------------------" << endl;

	cout << "----------------------------------------" << endl;
	cout << "Testing an invalid contact!" << endl;
	cout << "----------------------------------------" << endl;
	Contact bad(nullptr, nullptr, 0);
	bad.display();
	Contact alsoBad("", nullptr, 0);
	alsoBad.display();
	cout << "----------------------------------------" << endl;
	cout << "----------------------------------------" << endl;
	cout << "Testing the constructor with parameters!" << endl;
	cout << "----------------------------------------" << endl;
	Contact temp("A contact with a very looooong name!", nullptr, 0);
	temp.display();
	cout << "----------------------------------------" << endl;

	cout << "----------------------------------------" << endl;
	cout << "Testing a valid contact!" << endl;
	long long phoneNumbers[] = { 1416123456LL, 14161234567LL,
		1416234567890LL, 14162345678LL, -1LL, 124163456789LL };
	Contact someContact("John Doe", phoneNumbers, 7);
	someContact.display();
	cout << "----------------------------------------" << endl;

	return 0
}