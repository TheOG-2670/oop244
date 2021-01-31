// Workshop 4 - Constructors - Passenger Implementation
// File: Passenger.cpp
// Student name: Omri Golan
// Date: 10/4/2018
// Section: SGG
// Seneca email: ogolan1@myseneca.ca

// TODO: add your headers here
#include <iostream>
#include <cstring>
#include "Passenger.h"

using namespace std;

// TODO: continue your namespace here
namespace sict
{
	// TODO: implement the default constructor here
	Passenger::Passenger()
	{
		passenger_name[0] = '\0';
		destination_name[0] = '\0';
	};	
	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char *passengerName, const char *destinationName)
	{
		if (nullptr != passengerName && passengerName[0] != '\0' && nullptr != destinationName && destinationName[0] != '\0')
		{
				strncpy(passenger_name, passengerName, 19);
				passenger_name[18] = '\0';
			
				strncpy(destination_name, destinationName, 19);

		}

		else
		{
			passenger_name[0] = '\0';
			destination_name[0] = '\0';

		}
	};

	// TODO: implement isEmpty query here
	bool Passenger::isEmpty() const
	{
		if (passenger_name[0] == '\0' && destination_name[0] == '\0')
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// TODO: implement display query here
	void Passenger::display() const
	{
		if (passenger_name[0] != '\0' && destination_name[0] != '\0')
		{
				cout << passenger_name << " - " << destination_name << endl;	
		}
		else
		{
			cout << "No passenger!" << endl;
		}
	}

}