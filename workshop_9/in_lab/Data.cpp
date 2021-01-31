// Workshop 9 - Function Templates
// File: Data.cpp
// Date: 11/22/2018
// Name: Omri Golan
// Section: SGG
// ID: 101160166
// Email: ogolan1@gmail.com
///////////////////////////////////////////////////

#include "Data.h"
using namespace std;

namespace sict
{

	// answers outputs statistics for visual validation of data
	//
	void answers(const int* year, const int* population, const int* violentCrime,
		const double* violentCrimeRate, const int* grandTheftAuto, const int n)
	{
		// Q1: print the population change in millions of people
		// - print answer correct to 2 decimal places.
		// e..g "6.31 million";
		// note that population is an integer, so dividing by 1000000 would yield "6"
		//cout << endl;

		cout << "Population change from " << min(year, n) << " to " << max(year, n) << " is " << fixed << setprecision(2)
			<< static_cast<double>(max(population,n) - min(population,n)) / 1000000 << " million" << endl;


		// Q2. print whether violent crime rate has gone up or down between 2000 and 2005

		int violenceDown = 0, violenceUp = 0;
		for (int index = 0; index < n; index++)
		{
			if (violentCrime[index] > violentCrime[index + 1])
			{
				violenceDown++;
			}
			else
			{
				violenceUp++;
			}
		}

		if (violenceDown >= 2)
		{
			cout << "Violent Crime trend is down" << endl;
		}
		else
		{
			cout << "Violent Crime trend is up" << endl;
		}


		// Q3 print the GTA number accurate to 0 decimal places

		cout << "There are " << fixed << setprecision(2) <<
			static_cast<double>(average(grandTheftAuto, n) / 1000000) <<
			" million Grand Theft Auto incidents on average a year" << endl;


		// Q4. Print the min and max violentCrime rates
		cout << "The Minimum Violent Crime rate was " << static_cast<int>(min(violentCrimeRate, n)) << endl;
		cout << "The Maximum Violent Crime rate was " << static_cast<int>(max(violentCrimeRate, n)) << endl;


	}

}