//Module: Push Down Automata
//File: transition_function.cpp
//Application: push down automata
//Language c++
//OS: linux os ubuntu
//Class: cpts 422
//Author: Trevor Surface
//Date: 10/31/2019.

#include "../headers/transition_function.h"
#include "../headers/transition.h"
#include "../headers/stack_alphabet.h"
#include "../headers/states.h"
#include "../headers/final_states.h"
#include "../../validation/headers/validate.h"
#include "../../validation/headers/uppercase.h"

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

Transition_Function::Transition_Function(): transitions({})
{}

void Transition_Function::load(ifstream& definition, bool& valid)
{
	string value;
	while((definition >> value) && (to_uppercase(value) != "INITIAL_STATE:"))
	{
		string source_state, read_character, read_stack, destination_state, push_stack;
		if(is_valid_string(value))
			source_state = value;
		else
		{
			cout << "the source state " << value << " is an invalid source state.\n\n";
			valid = false;
		}
		if((definition >> value) && is_valid_char(value))
			read_character = value;
		else
		{
			cout << "the read character " << value << " is an invalid read character.\n\n";
			valid = false;
		}
		if((definition >> value) && is_valid_char(value))
			read_stack = value;
		else
		{
			cout << "the stack character " << value << "is an invalid stack character.\n\n";
			valid = false;
		}
		if((definition >>value) && is_valid_string(value))
			destination_state = value;
		else
		{
			cout << "the destination state " << value << " is an invalid destination state.\n\n";
			valid = false;
		}
		if((definition >> value) && (is_valid_string(value)))
			push_stack = value;
		else
		{
			cout << "the push stack " << value << " is an invalid push stack.\n\n";
			valid = false;
		}
		if((!source_state.empty()) && (!read_character.empty()) && (!read_stack.empty()) && (!destination_state.empty()) 
					&& (!push_stack.empty()))
		{
			Transition transition(source_state, read_character[0], read_stack[0], destination_state, push_stack);
			transitions.push_back(transition);
		}
	}
	if((to_uppercase(value) == "INITIAL_STATE:"))
	{
		int length = definition.tellg(); 
		definition.seekg(length - value.length());
		return;
	}
	else
	{
		int length = definition.tellg();
		definition.seekg(length - value.length());	
		cout << "\nkeyword \"initial_state:\" could not be found\n\n";
		valid = false;
	}
}

void Transition_Function::validate(const Stack_Alphabet& stack_alphabet, const States& states, 
		const Final_States& final_states, bool& valid) const
{
	for(int i = 0; i < transitions.size(); ++i)
	{
		if(!states.is_element(transitions[i].source_state()))
		{
			cout << "source state " << transitions[i].source_state() << " is not in the set of states.\n";
			valid = false;
		}
		if(!states.is_element(transitions[i].destination_state()))
		{
			cout << "destination state " << transitions[i].destination_state() << " is not in the set of states.\n";
			valid = false;
		}
		if(!stack_alphabet.is_element(transitions[i].read_stack_character()))
		{
			cout << "read stack character " << transitions[i].read_stack_character() << " is not in the stack alphabet.\n";
			valid = false;
		}
		for(int j = 0; j < transitions[i].push_stack_characters().length(); ++j)
		{
			if(!stack_alphabet.is_element(transitions[i].push_stack_characters()[j]))
			{
				cout << "push stack character " << transitions[i].push_stack_characters()[j] << " is not in stack alphabet.\n";
				valid = false;
			}
		}
	}
}
void Transition_Function::view() const
{
	for(int i = 0; i < transitions.size(); ++i)
	{
		cout << "\u03B4 (" << transitions[i].source_state();
		cout << ", " << transitions[i].read_character() << ")";
		cout << " = (" << transitions[i].destination_state();
		//cout << ", " << transitions[i].write_character();
		//cout << ", " << transitions[i].move_direction() << ")\n";
	}
	cout << "\n";
}

void Transition_Function::find_transition(string source_state, char read_character, char read_stack,
				string& destination_state, string& push_stack, bool& found) const
{
	for(int i = 0; i < transitions.size(); ++i)
		if((transitions[i].source_state() == source_state)
		&& (transitions[i].read_character() == read_character))
		{
			destination_state = transitions[i].destination_state();
			push_stack = transitions[i].push_stack_characters();
			found = true;
			return;
		}
	found = false;
}
