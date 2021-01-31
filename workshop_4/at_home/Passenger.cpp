// Workshop 4 - Constructors - Passenger Implementation
// File: Passenger.cpp
// Student name: Omri Golan
// Date: 10/9/2018
// Section: SGG
// Seneca email: ogolan1@myseneca.ca

// TODO: add your headers here
#define _CRT_SECURE_NO_WARNINGS
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
		year_of_departure = 0;
		month_of_departure = 0;

		for (int index = 0; index < 2; index++)
		{
			day_of_departure[index] = 0;
		}
	};	

	Passenger::Passenger(const char *passengerName, const char *destinationName)
	{
		
		if (nullptr != passengerName && passengerName[0] != '\0'
			&& nullptr != destinationName && destinationName[0] != '\0')
		{

				strncpy(passenger_name, passengerName, 19);
				passenger_name[18] = '\0';
			
				strncpy(destination_name, destinationName, 19);
				year_of_departure = 2018;
				month_of_departure = 10;

				for (int index = 0; index < 2; index++)
				{
					if (index == 1)
					{
						day_of_departure[index] = 1;
					}
					else
					{
						day_of_departure[index] = 0;
					}
				}
		}

		else
		{
			passenger_name[0] = '\0';
			destination_name[0] = '\0';
		}
	};

	Passenger::Passenger(const char *passengerName, const char *desinationName, int yearDepart, int monthDepart, int dayDepart)
	{
		if ((nullptr != passengerName) && (passengerName[0] != '\0') && (nullptr != desinationName) 
			&& (desinationName[0] != '\0') && (yearDepart != 0) && (monthDepart != 0) && (dayDepart != 0))
		{
			strncpy(passenger_name, passengerName, 19);
			passenger_name[18] = '\0';
			strncpy(destination_name, desinationName, 19);

			if ((yearDepart >= 2018 && yearDepart <= 2020) 
				&& (monthDepart >= 1 && monthDepart <= 12) 
				&& (dayDepart >= 1 && dayDepart <= 31))
			{
				year_of_departure = yearDepart;
				month_of_departure = monthDepart;

				for (int index = 0; index < 2; index++)
				{
					if (index == 0)
					{
						day_of_departure[index] = dayDepart / 10;
					}
					else
					{
						day_of_departure[index] = dayDepart % 10;
					}
				}
			}

			else
			{
				for (int index = 0; index < 2; index++)
				{
					day_of_departure[index] = 0;
				}
				
				month_of_departure = 0;
				year_of_departure = 0;
			}
		}

		else
		{
			passenger_name[0] = '\0';
			destination_name[0] = '\0';
		}
	};

	const char* Passenger::name() const
	{
		if (passenger_name[0] != '\0')
		{
			return passenger_name;
		}
		else
		{
			return 0;
		}
	}	

	bool Passenger::canTravelWith(const Passenger& passenger) const
	{
		if ((this->year_of_departure == passenger.year_of_departure)
			&& (this->month_of_departure == passenger.month_of_departure))
		{
			for (int index = 0; index < 2; index++)
			{
				if(this->day_of_departure[index] == passenger.day_of_departure[index])
				{
					return true;
				}
			}
			return true;
		}	
		else
		{
			return false;
		}
	}


	void Passenger::display() const
	{
		if ((passenger_name[0] != '\0') && (destination_name[0] != '\0') 
			&& (year_of_departure != 0) && (month_of_departure != 0) && (day_of_departure != 0))
		{
			cout << passenger_name << " - " << destination_name << " on " << year_of_departure <<
				"/" << month_of_departure << "/"; 
			
			for (int index = 0; index < 2; index++)
			{
				cout << day_of_departure[index];
			}
			cout << endl;
		}
		else
		{
			cout << "No passenger!" << endl;
		}
	}

}