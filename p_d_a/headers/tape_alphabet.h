//Module: Turing Machine
//File: tape_alphabet.h
//Application: turing machine application
//Language c++
//OS: linux os ubuntu
//Class: cpts 322
//Author: Trevor Surface
//Date: 4/29/2019.

#ifndef TAPE_ALPHABET_H
#define TAPE_ALPHABET_H

#include "validate.h"
#include "uppercase.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Tape_Alphabet
{
	private:
		vector<char> alphabet;
		//@param stores the list of chars associated with the alphabet

	public:
		Tape_Alphabet();
		//@param this funciton takes no parameters
		//@func this function is the default constructor for the class
		//@return this function has no return

		void load(ifstream& definition, bool& valid);
		//@param this functiont takes in a reference to a ifstream definition
		//and a reference to a bool valid
		//@func this function reads from the definition file and loads in the 
		//elementes of the tape alphabet
		//@return this function has no return

		void view() const;
		//@param this funciton takes no parameters
		//@func this function allows the user to view the tape alphabet in 
		//original format
		//@return this function has no return

		bool is_element(char value) const;
		//@param this function takes a char value
		//@func this function checks to see if the passed in value is a member
		//of the vector alphabet and returns true if the value is found
		//@return this function returns a bool

};

#endif
