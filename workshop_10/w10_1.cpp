// File: w10.cpp
// Date: 12/06/2018
// Name: Omri Golan
// Section: SGG
// ID: 101160166
// Email: ogolan1@myseneca.ca
/////////////////////////////////////////

#include <iostream>
#include "grade.h"

int main()
{

	int maxMark = 100;
	double mark = 69.55;
	int mark2 = 69;

	Student fred(mark);
	
		std::cout << gradeIt(mark, maxMark) << std::endl;
		std::cout << gradeIt(mark2, maxMark) << std::endl;
		std::cout << gradeIt(fred, maxMark) << std::endl;


	return 0;
}