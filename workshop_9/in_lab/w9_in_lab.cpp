// Workshop 9 - Function Templates
// File: Data.h
// Date: 11/22/2018
// Name: Omri Golan
// Section: SGG
// ID: 101160166
// Email: ogolan1@gmail.com
///////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include "Data.h"

using namespace std;
using namespace sict;

//////////////////
// File format:
// - first line is number of columns
// - each record is Name, data1, data2, data3 ,...

// main answers questions about the data in file crimedata.csv
// - reads the first line with the number of data items
// - allocates memory for the data values in each file record
// - reads the data for each record
//   - ensures that it is reading the correct row. If the name
//     does not match the row, return false and exits prematurely
// - displays the data for each record
// - answers questions about the data
// - deallocates the memory
//


int main(void)
{
	ifstream finput("crimedata.csv");

	if (!finput)
	{
		cerr << "cannot open file crimedata.csv" << endl;
		return 1;
	}

	int n = 0;
	finput >> n;
	finput.ignore(2000, '\n');

	// allocate memory for n items
	int* year = new int[n];
	int* population = new int[n];
	int* violentCrime = new int[n];
	double* violentCrimeRate = new double[n];
	int* grandTheftAuto = new int[n];
	double* grandTheftAutoRate = new double[n];

	////////////////////
	// Note: this is a simple file reader
	// - read each row in the same order it is found in the file
	//
	if (!readRow(finput, "Year", year, n))
	{
		return 1;
	}

	if (!readRow(finput, "Population", population, n))
	{
		return 1;
	}
	if (!readRow(finput, "ViolentCrime", violentCrime, n))
	{
		return 1;
	}
	if (!readRow(finput, "ViolentCrime_Rate", violentCrimeRate, n))
	{
		return 1;
	}
	if (!readRow(finput, "GrandTheftAuto", grandTheftAuto, n))
	{
		return 1;
	}
	if (!readRow(finput, "GrandTheftAuto_Rate", grandTheftAutoRate, n))
	{
		return 1;
	}
	cout << endl;

	// display the data
	display("Year", year, n);
	display("Population", population, n);
	display("ViolentCrime", violentCrime, n);
	display("ViolentCrimeRate", violentCrimeRate, n);
	display("GrandTheftAuto", grandTheftAuto, n);
	display("GrandTheftAutoRate", grandTheftAutoRate, n);

	// Answer the validation questions
	answers(year, population, violentCrime, violentCrimeRate, grandTheftAuto, n);

	// deallocate memory
	delete[] year;
	delete[] population;
	delete[] violentCrime;
	delete[] violentCrimeRate;
	delete[] grandTheftAuto;
	delete[] grandTheftAutoRate;

	// execution successful
	return 0;
}