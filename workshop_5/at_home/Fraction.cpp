// Workshop 5: operator overloading
// File: Fraction.cpp
// Date: 10/16/2018
// Student name: Omri Golan
// Student ID: 101160166
// Section: SGG
// Student email: ogolan1@myseneca.ca
/////////////////////////////////////////////

// TODO: insert header files
#include <iostream>
#include "Fraction.h"
using namespace std;
using namespace sict;

// TODO: continue the namespace
namespace sict
{

	// TODO: implement the default constructor
	Fraction::Fraction()
	{

		numerator = 0;
		denominator = 0;
	}

	// TODO: implement the two-argument constructor
	Fraction::Fraction(int n, int d)
	{
		if (n >0 && d>0)
		{
			numerator = n;
			denominator = d;
			reduce();
		}

		else
		{
			numerator = 0;
			denominator = 0;
		}
		
	}

	// TODO: implement the max query
	int Fraction::max() const
	{
		if (numerator < denominator)
		{
			return denominator;
		}
		else
		{
			return numerator;
		}

	}

	// TODO: implement the min query
	int Fraction::min() const
	{
		if (numerator < denominator)
		{
			return numerator;
		}
		else
		{
			return denominator;
		}

	}

	// gcd returns the greatest common divisor of num and denom
	//
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}

	// TODO: implement the reduce modifier
	void Fraction::reduce()
	{
		int _gcd = gcd();
		if (numerator % _gcd == 0 && denominator % _gcd == 0)
		{
			numerator = numerator / _gcd;
			denominator = denominator / _gcd;
		}
		
	}

	// TODO: implement the display query
	void Fraction::display() const
	{
		if (isEmpty())
		{
			cout << "no fraction stored";
			
		}
		else if((numerator/denominator) == numerator)
		{
			cout << numerator;
		}
		else if ((numerator/denominator) != numerator)
		{
			cout << numerator << "/" << denominator;
		}
	}

	// TODO: implement the isEmpty query
	bool Fraction::isEmpty() const
	{
		if (numerator == 0 && denominator == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// TODO: implement the + operator
	Fraction Fraction::operator+(const Fraction& rhs)
	{
		Fraction numAdd, denomAdd;
		if (isEmpty() == false && rhs.isEmpty() == false)
		{
			int numAdd = (this->numerator*rhs.denominator) + (rhs.numerator*this->denominator);
			int denomAdd = this->denominator * rhs.denominator;
			return Fraction(numAdd, denomAdd);
		}
		else
		{
			return *this;
		}
		
	}

	Fraction Fraction::operator*(const Fraction& rhs)
	{
		Fraction numMult, denomMult;
		if (isEmpty() == false && rhs.isEmpty() == false)
		{
			int numMult = this->numerator * rhs.numerator;
			int denomMult = this->denominator * rhs.denominator;
			
			return Fraction(numMult, denomMult);
		}
		else
		{
			return Fraction();
		}
	}

	bool Fraction::operator==(const Fraction& rhs)
	{
		if ((isEmpty() == false && rhs.isEmpty() == false)
			&& (this->numerator == rhs.numerator) && (this->denominator == rhs.denominator))
		{		
				return true;
		}
		else
		{
			return false;
		}
	}

	bool Fraction::operator!=(const Fraction& rhs)
	{
		if ((isEmpty() == false && rhs.isEmpty() == false)
			&& (this->numerator != rhs.numerator) && (this->denominator != rhs.denominator))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	Fraction Fraction::operator+=(const Fraction& rhs)
	{
			
		if (isEmpty() == false && rhs.isEmpty() == false)
		{

			*this = Fraction::operator+(rhs);

			Fraction &add = *this;
			return add;
		}
		else
		{
			*this = Fraction();
			Fraction &add = *this;
			return add;
		}
	}
}