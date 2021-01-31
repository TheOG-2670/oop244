/***********************************************************
//Workshop 2: Dynamic Memory
//File: Kingdom.h
//Name: Omri Golan
//Student ID: 101160166
//Seneca email: ogolan1@myseneca.ca
//Date of Completion: 9/24/2018
//
///////////////////////////////////////////////////////////
***********************************************************/


#ifndef KINGDOM_H
#define KINGDOM_H


namespace sict
{

	struct Kingdom
	{
		char m_name[32];
		int m_population;
	};


	void display(const Kingdom &kingdom);

	void display(const Kingdom kingdomArray[], int count);
	
}

#endif