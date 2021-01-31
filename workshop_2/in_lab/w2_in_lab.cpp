/***********************************************************
// Workshop 2: Dynamic Memory
// File: w2_in_lab.cpp
// Date: 9/20/2018
// Author: Omri Golan
// Section: SGG 
//
// 
///////////////////////////////////////////////////////////
***********************************************************/

#include <iostream>
#include "Kingdom.h"

using namespace std;
using namespace sict;

void read(sict::Kingdom& kingdom);

int main() {

	int count = 0; // the number of kingdoms in the array

	// TODO: declare the pKingdom pointer here (don't forget to initialize it)
	Kingdom *pKingdom = nullptr; //kingdom pointer of type Kingdom struct declared and initialized to nullptr
	

	cout << "==========\n"
		<< "Input data\n"
		<< "==========\n"
		<< "Enter the number of Kingdoms: ";
	cin >> count;
	cin.ignore();

	if (count < 1) return 1;

	// TODO: allocate dynamic memory here for the pKingdom pointer
	pKingdom = new Kingdom[count]; //allocate dynamic memory for kingdom pointer array of new type Kingdom struct

	for (int i = 0; i < count; ++i) {
		cout << "Kingdom #" << i + 1 << ": " << endl;
		// TODO: add code to accept user input for Kingdom i
		read(pKingdom[i]); //read function uses kingdom pointer as variable reference to Kingdom structure and pointer uses i to loop through each kingdom structure
		//pKingdom, Kingdom &kingdom => pKingdom->kingdom
	}
	cout << "==========" << endl << endl;

	// testing that "display(...)" works
	cout << "------------------------------" << endl
		<< "The 1st kingdom entered is" << endl
		<< "------------------------------" << endl;
	sict::display(pKingdom[0]); //displays information of first kingdom structure through kingdom pointer
	cout << "------------------------------" << endl << endl;

	// TODO: deallocate the dynamic memory here
	delete[] pKingdom; //deallocate dynamic memory for kingdom pointer
	pKingdom = nullptr; //set kingdom pointer to null (empty)

	return 0;
}

// read accepts data for a Kingdom from standard input
//
void read(sict::Kingdom& kingdom) {

	cout << "Enter the name of the Kingdom: ";
	cin.get(kingdom.m_name, 32, '\n');
	cin.ignore(2000, '\n');
	cout << "Enter the number of people living in " << kingdom.m_name << ": ";
	cin >> kingdom.m_population;
	cin.ignore(2000, '\n');
}
