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


// TODO: include the necessary headers
#include <iostream>
#include "Kingdom.h"
using namespace std;
//using namespace sict;

// TODO: the sict namespace
namespace sict
{

	// TODO:definition for display(...) 
	void display(const Kingdom &kingdom)
	{
		cout << kingdom.m_name << ", ";
		cout << "population " << kingdom.m_population << endl;
	}
}
    
