// Workshop 4 - Constructors - Passenger Header
// File: Passenger.h
// Student name: Omri Golan
// Date: 10/9/2018
// Section: SGG
// Seneca email: ogolan1@myseneca.ca


// TODO: add header file guard here
#pragma once
#ifndef PASSENGER_H
#define PASSENGER_H

// TODO: declare your namespace here
namespace sict
{
	// TODO: define the Passenger class here
	class Passenger
	{
	private:
		char passenger_name[19];
		char destination_name[19];
		int year_of_departure;
		int month_of_departure;
		int day_of_departure[2];

	public:
		Passenger();
		Passenger(const char *passengerName, const char *desinationName);
		Passenger(const char *passengerName, const char *desinationName, int yearDepart, int monthDepart, int dayDepart);
		const char* name() const;
		bool canTravelWith(const Passenger&) const;
		bool isEmpty() const;
		void display() const;
	};

}
#endif