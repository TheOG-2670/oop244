// File: w10.cpp
// Date: 12/02/2018
// Name: Omri Golan
// Section: SGG
// ID: 101160166
// Email: ogolan1@myseneca.ca
/////////////////////////////////////////

#include <iostream>
#include "grade.h"

char gradeIt(int mark, int maxMark);

int main()
{
	int t1Marks[] = {28,44,12,30};
	int t1MaxMark = 47;

	double t2Marks[] = {28.0, 22.5, 24.8, 21.6};
	double t2MaxMark = 47.0;

	char t3Marks[] = { 'A', 'D', 'C', 'F' };
	char t3MaxMark = 'A';

	for (int i = 0; i < 4; i++)
	{
		std::cout << gradeIt(t1Marks[i], t1MaxMark) << " ";
		std::cout << gradeIt(t2Marks[i], t2MaxMark) << " ";
		std::cout << gradeIt(t3Marks[i], t3MaxMark) << std::endl;
	}
	std::cout << std::endl;

	return 0;
}