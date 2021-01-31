/***********************************************************
//Workshop 2: Dynamic Memory
//File: w2_at_home.cpp
//Name: Omri Golan
//Student ID: 101160166
//Seneca email: ogolan1@myseneca.ca
//Date of Completion: 9/24/2018
//
///////////////////////////////////////////////////////////
***********************************************************/

#include <iostream>
#include "Kingdom.h"

using namespace std;
using namespace sict;

void read(Kingdom&);

int main() {
	int count = 0; // the number of kingdoms in the array


	Kingdom *pKingdom = nullptr;

	cout << "==========\n"
		<< "Input data\n"
		<< "==========\n"
		<< "Enter the number of Kingdoms: ";
	cin >> count;
	cin.ignore();

	if (count < 1) return 1;


	pKingdom = new Kingdom[count];

	for (int i = 0; i < count; ++i) {
		cout << "Kingdom #" << i + 1 << ": " << endl;

		read(pKingdom[i]);
	}
	cout << "==========" << endl << endl;

	// testing that "display(...)" works
	cout << "------------------------------" << endl
		<< "The 1st Kingdom entered is" << endl
		<< "------------------------------" << endl;
	display(pKingdom[0]);
	cout << "------------------------------" << endl << endl;

	// expand the array of Kingdoms by 1 element

	Kingdom *pKingdomNew;
	pKingdomNew = new Kingdom[count + 1];
	

	for (int index = 0; index < count; index++)
	{
		pKingdomNew[index] = pKingdom[index];
	}

	delete[] pKingdom;

	pKingdom = pKingdomNew;
	// add the new Kingdom
		cout << "==========\n"
			<< "Input data\n"
			<< "==========\n"
			<< "Kingdom #" << count + 1 << ": " << endl;

		read(pKingdom[count]);
		count++;

	cout << "==========\n" << endl;

	// testing that the overload of "display(...)" works
	display(pKingdom, count);
	cout << endl;


	delete[] pKingdom;

	return 0;
}

// read accepts data for a Kingdom from standard input

void read(Kingdom& kingdom) {
	cout << "Enter the name of the Kingdom: ";
	cin.get(kingdom.m_name, 32, '\n');
	cin.ignore(2000, '\n');
	cout << "Enter the number of people living in " << kingdom.m_name << ": ";
	cin >> kingdom.m_population;
	cin.ignore(2000, '\n');
}
