//Module: Turing Machine
//File: final_states.h
//Application: turing machine application
//Language c++
//OS: linux os ubuntu
//Class: cpts 322
//Author: Trevor Surface
//Date: 4/29/2019.

#ifndef FINAL_STATES_H
#define FINAL_STATES_H

#include "states.h"

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

class Final_States
{
	private:
		vector<string> names;
		//@param stores the names of final states from defintion file

	public:
		Final_States();
		//@param this function takes no parameters
		//@func this is the default constructor for the class
		//@return this funciton has no return
		
		void load(ifstream& definition, bool& valid);
		//@param this function takes a reference to a ifstream definition 
		//and a reference to a bool valid
		//@func this function loads the list of final states into the vector
		//@return this function has no return
		
		void validate(States& states, bool& valid) const;
		//@param this function takes a reference to a States states and a 
		//reference to a boolean valid
		//@func this function validates that every final state is also in 
		//the list of states
		//@return this function has no return	

		void view() const;
		//@param this function takes no parameters
		//@func this function lets the user view the final states in their original
		//format
		//@return this function has no return
		
		bool is_element(string value) const;
		//@param this function takes a string value
		//@func this funciton checks to see if the passed in value is also included
		//in the vector of names
		//@return this function returns a bool
};

#endif
