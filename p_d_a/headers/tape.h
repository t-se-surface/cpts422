//Module: Turing Machine
//File: tape.h
//Application: turing machine application
//Language c++
//OS: linux os ubuntu
//Class: cpts 322
//Author: Trevor Surface
//Date: 4/29/2019.

#ifndef TAPE_H
#define TAPE_H

#include "input_alphabet.h"
#include "tape_alphabet.h"
#include "direction.h"
#include "uppercase.h"
#include "validate.h"

#include <string>
#include <fstream>

using namespace std;

class Tape
{
	private:
		string cells;
		//@param stores the string of cells

		int current_cell;
		//@param stores the index to the current cell
		
		char blank_character;
		//@param stores the blank character
		
	public:
		Tape();
		//@param this function takes no parameters
		//@func this function is the default constructor for the class
		//@return this function has no return

		void load(ifstream& definition, bool& valid);
		//@param
		//@func this function loads the blank character
		//@return this function has no return

 		void validate(const Input_Alphabet& input_alphabet, const Tape_Alphabet& tape_alphabet, bool& valid) const;
		//@param
 		//@func this function validates every element of the inpur alphabet and
		//tape alphabet
		//@return this function has no return

		void view() const;
		//@param this function takes no parameters
		//@func this function provides a viewing of the blank character in 
		//proper syntax
		//@return this function has no return

		void initialize(string input_string);
		//@param
		//@func this function initializes the input string and performs the
		//first transition
		//@return this function has no return

		void update(char write_character, direction move_direction);
		//@param
		//@func this function updates the string with the write character
		//and the move direction for the tape head
		//@return this function has no return

		string left(int maximum_number_of_cells) const;
		//@param
		//@func this function provides the left side of the tape head
		//and truncates it if neccessary
		//@return this function returns a string

		string right(int maximum_number_of_cells) const;
		//@param
		//@func this function provides the right side of the tape head
		//and truncates if it is neccessary
		//@return this function returns a string

		char current_character() const;
		//@param this function takes no parameters
		//@func this function returns the value of the current character
		//@return this function returns a character

		bool is_first_cell() const;
		//@param this function takes no parameters
		//@func this function returns true if the cell it is currently pointing at
		//is the first cell
		//@return this function returns a boolean

};

#endif
