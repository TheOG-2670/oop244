// Workshop 9 - Function Templates
// File: Data.h
// Date: 11/22/2018
// Name: Omri Golan
// Section: SGG
// ID: 101160166
// Email: ogolan1@gmail.com
///////////////////////////////////////////////////

#pragma once
#ifndef SICT_DATA_H
#define SICT_DATA_H

#include <iostream>
#include <iomanip>
#include <cstring>

namespace sict
{
	// These numbers define: 
	// a) the range of data we expect to see in this workshop
	//    0 to 1 billion
	//    use them in the min and max function
	// b) the output column width for a single data field

	const int LARGEST_NUMBER = 1000000000;
	const int SMALLEST_NUMBER = 0;
	const int COLUMN_WIDTH = 15;

	// max returns the largest item in data
	//
	template <typename maxVal>
	maxVal max(const maxVal *data, int n)
	{
		maxVal largestNum = 0;
		maxVal largest = data[n - 1];
		for (int index = n; index >= 0; index--)
		{
			if (largest > data[index] && data[index] > SMALLEST_NUMBER && data[index] < LARGEST_NUMBER)
			{
				largestNum = largest;
			}
			else
			{
				largestNum = data[index];
			}
		}
		return largestNum;
	}

	// min returns the smallest item in data
	//
	template <typename minVal>
	minVal min(const minVal *data, int n)
	{
		minVal smallestNum = 0;
		minVal smallest = data[0];
		for (int index = 0; index < n; index++)
		{
			if (smallest < data[index + 1] && smallest > SMALLEST_NUMBER && smallest < LARGEST_NUMBER)
			{
				smallestNum = smallest;
				return smallestNum;
			}
			else
			{
				smallestNum = data[index];
				
			}

		}
		return smallestNum;
	}



	// sum returns the sum of n items in data
	//    
	template <typename sumVal>
	sumVal sum(const sumVal *data, int n)
	{
		sumVal sumNum = 0;
		for (int index = 0; index < n; index++)
		{
			sumNum = sumNum + data[index];
		}
		return sumNum;
	}

	// average returns the average of n items in data
	//
	template <typename avgVal>
	double average(const avgVal *data, int n)
	{
		double averageNum = 0.0;
		averageNum = sum(data, n) / n;
		return averageNum;
	}

	// read extracts n items from input and stores them in data
	// - the items are comma separated
	// - this function assumes that a comma exists at the next field to be read
	// - for example: ,data1, data2,data3, ...., datan
	//
	template <typename readVals>
	bool read(std::istream &input, readVals *data, int n)
	{

		for (int index = 0; index < n; index++)
		{
			input.ignore();
			input >> data[index];

			if (input.fail() == true)
			{
				return false;
			}
		}
		return true;
	}

	// display inserts n items of data into std::cout
	//
	template <typename displayVals>
	void display(const char *name, const displayVals *data, int n)
	{
		std::cout << std::setw(20) << name;
		for (int index = 0; index < n; index++)
		{
			std::cout << std::setw(15) << data[index];
		}
		std::cout << std::endl;
	}

	template <typename crime>
	bool readRow(std::istream &input, const char *name, crime *data, int n)
	{
		bool ok = input.bad() == false;

		//hold name of row
		char rowname[2000];

		//continuously read input until an error is encountered
		if (ok == true)
		{
			//read individual characters of a string until a comma is reached
			input.get(rowname, sizeof(rowname), ',');

			//if the 'rowname' and 'name' are different, return an error
			if (strcmp(rowname, name) == 1)
			{
				std::cout << "cannot parse row for " << name << std::endl;
				//ignore characters up to newline
				input.ignore(2000, '\n');
				ok = false;
			}
		}

		if (ok == true)
		{
			ok = read(input, data, n);
		}
		input.ignore(2000, '\n');

		return ok;
	}


	//bool readRow(std::istream& input, const char* name, int* data, int n);
	//bool readRow(std::istream& input, const char* name, double* data, int n);
	void answers(const int*, const int*, const int*, const double*, const int*, const int n);
}


#endif