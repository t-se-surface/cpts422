//Module: Turing Machined
//File: states.h
//Application: turing machine application
//Language c++
//OS: linux os ubuntu
//Class: cpts 322
//Author: Trevor Surface
//Date: 4/29/2019.

#ifndef STATES_H
#define STATES_H

#include "../../validation/headers/validate.h"
#include "../../validation/headers/uppercase.h"

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

class States
{
	private:
		vector<string> names;
		//@param stores the names of states from defintion file

	public:
		States();
		//@param this function takes no parameters
		//@func this is the default constructor for the class
		//@return this funciton has no return

		void load(ifstream& definition, bool& valid);
		//@param this function takes a reference to a ifstream definition 
		//and a reference to a bool valid
		//@func this function loads the list of states into the vector
		//@return this function has no return
		
		void view() const;
		//@param this function takes no parameters
		//@func this function lets the user view the states in their original
		//format
		//@return this function has no return
		
		bool is_element(string value) const;
		//@param this function takes a string value
		//@func this funciton checks to see if the passed in value is also included
		//in the vector of names
		//@return this function returns a bool
};

#endif
