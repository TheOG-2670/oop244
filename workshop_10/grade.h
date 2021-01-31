// File: w10.cpp
// Date: 12/06/2018
// Name: Omri Golan
// Section: SGG
// ID: 101160166
// Email: ogolan1@myseneca.ca
/////////////////////////////////////////


#pragma once
#ifndef GRADE_H
#define GRADE_H

//w10_1
class Student
{
	private:
		double mark;
	
	public:
		Student(double i)
		{
			mark = i;
		}
		double getMark()
		{
			return mark;
		}
};


//main program file: w10
//integer values
//regular function
/*char gradeIt(int mark, int maxMark)
{
	double totalMark = (static_cast<double>(mark) / static_cast<double>(maxMark)) * 100;
	totalMark = static_cast<int>(totalMark);
	if (totalMark <= 50)
	{
		return 'F';
	}
	if (totalMark > 50 && totalMark <= 59)
	{
		return 'D';
	}
	else if (totalMark > 59 && totalMark <= 69)
	{
		return 'C';
	}
	else if (totalMark > 69 && totalMark <= 79)
	{
		return 'B';
	}
	else
	{
		return 'A';
	}

}*/

//main program file: w10_1
//double values
//template function
template <typename TA, typename TB> //define two different generic types for function template
char gradeIt(const TA mark, const TB maxMark) //set variables to those types
{
	/*cast receiving 'mark' variable type to double, divide by 'maxMark', multiply by 100 and store 
	in double 'totalMark' variable*/
	double totalMark = (static_cast<double>(mark) / (maxMark)) * 100; 
	
	/*check 'totalMark' variable against different percentage ranges and return corresponding
	letter grade*/
	if (totalMark <= 50)
	{
		return 'F';
	}
	if (totalMark > 50 && totalMark <= 59)
	{
		return 'D';
	}
	else if (totalMark > 59 && totalMark <= 69)
	{
		return 'C';
	}
	else if (totalMark > 69 && totalMark <= 79)
	{
		return 'B';
	}
	else
	{
		return 'A';
	}
}


//main program file: w10
//character values
//explicit specialized function
/*	
char gradeIt<char>(char mark, char maxMark)
{
	return mark;
}*/


//w10_1
char gradeIt(Student &mark, int maxMark) //receiving parameters: reference to 'Student' class, maxMark value
{
	/*runs through 'getMark()' Student class member function to get mark value and then runs through
	'gradeIt()' member function to check mark value from 'getMark()' against perentages and return 
	corresponding letter grade*/
	return gradeIt<double, int>(mark.getMark(), maxMark);

}


#endif