/***********************************************************
// Workshop 2: Dynamic Memory
// File: w2_in_lab.cpp
// Date: 9/20/2018
// Author: Omri Golan
// Section: SGG
//
//
///////////////////////////////////////////////////////////
***********************************************************/

// TODO: header safeguards
#ifndef KINGDOM_H
#define KINGDOM_H

// TODO: sict namespace
namespace sict
{
	// TODO: define the structure Kingdom in the sict namespace
	struct Kingdom
	{
		char m_name[32];
		int m_population;
	};

	// TODO: declare the function display(...),
	//         also in the sict namespace
	void display(const Kingdom &kingdom);
	
}
#endif