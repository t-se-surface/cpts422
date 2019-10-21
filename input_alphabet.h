//Module: Turing Machine
//File: input_alphabet.h
//Application: turing machine application
//Language c++
//OS: linux os ubuntu
//Class: cpts 322
//Author: Trevor Surface
//Date: 4/29/2019.

#ifndef INPUT_ALPHABET_H
#define INPUT_ALPHABET_H

#include "tape_alphabet.h"
#include "validate.h"
#include "uppercase.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Input_Alphabet
{
	private:
		vector<char> alphabet;
		//@param stores the characters of the alphabet associated with the 
		//input alphabet
	public:
		Input_Alphabet();
		//@param this function takes no parameters
		//@func this function is the default constructor for the class
		//@return this function has no return

		void load(ifstream& definition, bool& valid);
		//@param this function takes a reference to an ifstream definition, and
		//a reference to a bool valid
		//@func this function loads the characters form the defintion file into 
		//the alphabet vector
		//@return this function has no return

		void validate(const Tape_Alphabet& tape_alphabet,  bool& valid) const;
		//@param this function takes a reference to a tape_alphabet, and a 
		//reference to a boolean valid
		//@func this function uses the tape_alphabet to validate if every element
		//of the input alphabet is also a member of the tape_alphabet
		//@return this function has no return 

		void view() const;
		//@param this function takes no parameters 
		//@func this function allows the user to view the input alphabet characters
		//in original format
		//@return this function has no return

		bool is_element(const char value) const;
		//@param this function takes a character value
		//@func this function checks the passed in value against the vector alphabet
		//and returns true if the value is found as part of the list.
		//@return this function returns a boolean

};

#endif
