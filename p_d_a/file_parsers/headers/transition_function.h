//Module: Push Down Automata
//File: transition_function.h
//Application: push down automata
//Language c++
//OS: linux os ubuntu
//Class: cpts 422
//Author: Trevor Surface
//Date: 10/31/2019.

#ifndef TRANSITION_FUNCTION_H
#define TRANSITION_FUNCTION_H

#include "transition.h"
#include "stack_alphabet.h"
#include "states.h"
#include "final_states.h"

#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Transition_Function
{
	private:
		vector<Transition> transitions;
		//@param stores a vector of transitions from the file

	public:
		Transition_Function();
		//@param this function takes no parameters
		//@func this is the default constructor for the class
		//@return this function has no return

		void load(ifstream& definition, bool& valid);
		//@param this function takes in a reference to an ifstream definition
		//and a reference to a bool valid
		//@func This function loades the valid transitions into the transitions
		//vector local to this class
		//@return this function has no return

		void validate(const Stack_Alphabet& stack_alphabet, const States& states,
				const Final_States& final_states, bool& valid) const;
		//@param This function takes a reference to a tape_alphabet, a refernece
		//to a states, a reference to a final_states, and a reference to a bool valid
		//@func this function uses the validation functions to make sure that each
		//transition is unique and that each transition is valid
		//@return this function has no return

		void view() const;
		//@param this function takes no parameters
		//@func this function allows the user to see the visual of the transition
		//functions using the greek characters
		//@return this function has no return

		vector<Transition> find_transitions(string source_state, char read_character, char read_stack, bool& found) const;

		//@param this function takes a string source state, a characer read character
		//a reference to a string destination, a reference to a character write character
		//a reference to a direction move direction and a reference to a bool found.
		//@func this function tries to find a transition function to the passed in parameters
		//and returns the results if found.
		//@return this function has no return

};

#endif
