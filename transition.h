//Module: Turing Machine
//File: transition.h
//Application: turing machine application
//Language c++
//OS: linux os ubuntu
//Class: cpts 322
//Author: Trevor Surface
//Date: 4/29/2019.

#ifndef TRANSITION_H
#define TRANSITION_H

#include "direction.h"
#include <string>

using namespace std;

class Transition
{
	private:
		string source;
		//@param stores the source state from the file
		
		char read;
		//@param stores the read character from the file
		
		string destination;
		//@param stores the destination state from the file
		
		char write;
		//@param stores the write character from the file
		
		direction move;
		//@param stores the move direction from the file
	
	public:
		Transition(string source_state, char read_character,
				string destination_state, char write_character, direction move_direction);
		//@param this function this function takes in a string source state
		//char read character, string destination, char write character, and a 
		//direction move direction
		//@func this function is the main constructor for the transition
		//@return this function has no return

		string source_state() const;
		//@param this function takes in no parameters
		//@func this function returns the value of the source state 
		//@return this function returns a string 
		
		char read_character() const;
		//@param this function takes in no parameters
		//@func this function returns the value of the read character
		//@return this function returns a character
		
		string destination_state() const;
		//@param this function takes in no parameters
		//@func this function returns the value of the destination state
		//@return this function returns a string
		
		char write_character() const;
		//@param this function takes in no parameters
		//@func this function returns the value of the write character
		//@return this function returns a character
		
		direction move_direction() const;
		//@param this function takes in no parameters
		//@func this function returns the value of the move direction
		//@return this function returns a direction
};
#endif
