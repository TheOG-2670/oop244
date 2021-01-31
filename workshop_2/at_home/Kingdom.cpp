/***********************************************************
//Workshop 2: Dynamic Memory
//File: Kingdom.cpp
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


namespace sict
{

	/*displays user-defined kingdom name and population number in
	  following format: KINGDOM_NAME, population POPULATION_NUMBER*/
	void display(const Kingdom &kingdom)
	{
		cout << kingdom.m_name << ", ";
		cout << "population " << kingdom.m_population << endl;
	}

	/*displays all user-defined kingdoms in 'kingdomArray[]' with calculated
	  total sum of all kingdom populations*/
	void display(const Kingdom kingdomArray[], int count)
	{
		int totalPopulation = 0;

		cout << "------------------------------" << endl;
		cout << "Kingdoms of SICT" << endl;
		cout << "------------------------------" << endl;

		for (int index=0; index < count; index++)
		{
			cout << index+1 << ". " << kingdomArray[index].m_name << ", ";
			cout << "population " << kingdomArray[index].m_population << endl;
			totalPopulation = totalPopulation + kingdomArray[index].m_population;
		}

		cout << "------------------------------" << endl;
		cout << "Total population of SICT: " << totalPopulation << endl;
		cout << "------------------------------" << endl;
	}
}
    
