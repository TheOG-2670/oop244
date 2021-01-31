// Workshop 5: operator overloading
// File: Fraction.h
// Date: 10/11/2018
// Student name: Omri Golan
// Student ID: 101160166
// Section: SGG
// Student email: ogolan1@myseneca.ca
/////////////////////////////////////////////

// TODO: header file guard
#ifndef FRACTION_H
#define FRACTION_H

// TODO: create namespace
namespace sict
{

	// TODO: define the Fraction class
	class Fraction {
		// TODO: declare instance variables 
		int numerator;
		int denominator;

		// TODO: declare private member functions
		int max() const;
		int min() const;
		int gcd() const;
		void reduce();

	public:
		// TODO: declare public member functions
		Fraction();
		Fraction(int n, int d);
		bool isEmpty() const;
		void display() const;

		// TODO: declare the + operator overload
		Fraction operator+(const Fraction& rhs);

	};

}
#endif