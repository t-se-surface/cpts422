//Module: Push Down Automata
//File: transition.h
//Application: push down automata
//Language c++
//OS: linux os ubuntu
//Class: cpts 422
//Author: Trevor Surface
//Date: 10/31/2019.

#ifndef TRANSITION_H
#define TRANSITION_H

#include <string>

using namespace std;

class Transition
{
	private:
		string source;
		//@param stores the source state from the file

		char read;
		//@param stores the read character from the file

		char read_stack;
		//@param stores the read stack character from the file

		string destination;
		//@param stores the destination state from the file

		string push;
		//@param stores the push character from the file

	public:
		Transition(string source_state, char read_character, char read_stack_character,
				string destination_state, string push_stack_string);
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

		char read_stack_character() const;

		string destination_state() const;
		//@param this function takes in no parameters
		//@func this function returns the value of the destination state
		//@return this function returns a string

		string push_stack_characters() const;

};
#endif
