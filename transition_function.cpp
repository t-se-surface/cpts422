//Module: Turing Machine
//File: transition_function.cpp
//Application: turing machine application
//Language c++
//OS: linux os ubuntu
//Class: cpts 322
//Author: Trevor Surface
//Date: 4/29/2019.

#include "transition_function.h"
#include "transition.h"
#include "tape_alphabet.h"
#include "states.h"
#include "final_states.h"
#include "validate.h"
#include "uppercase.h"
#include "direction.h"

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
		string source_state, read_character, destination_state, write_character, direction;
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
		if((definition >>value) && is_valid_string(value))
			destination_state = value;
		else
		{
			cout << "the destination state " << value << " is an invalid destination state.\n\n";
			valid = false;
		}
		if((definition >> value) && (is_valid_char(value)))
			write_character = value;
		else
		{
			cout << "the write character " << value << " is an invalid write character.\n\n";
			valid = false;
		}
		if((definition >> value) && (is_valid_direction(to_uppercase(value))))
			direction = value;
		else
		{
			cout << "the direction " << value << " is an invalid direction.\n\n";
			valid = false;	
		}
		if((!source_state.empty()) && (!read_character.empty()) && (!destination_state.empty() 
					&& (!write_character.empty()) && (!direction.empty())))
		{
			Transition transition(source_state, read_character[0], destination_state, write_character[0], direction[0]);
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

void Transition_Function::validate(const Tape_Alphabet& tape_alphabet, const States& states, 
		const Final_States& final_states, bool& valid) const
{
	for(int i = 0; i < transitions.size(); ++i)
	{
		if(final_states.is_element(transitions[i].source_state()))
		{
			cout << "source state " << transitions[i].source_state() << " is in final states.\n";
			valid = false;
		}
		if(!states.is_element(transitions[i].source_state()))
		{
			cout << "source state " << transitions[i].source_state() << " is not in the set of states.\n";
			valid = false;
		}
		if(!tape_alphabet.is_element(transitions[i].read_character()))
		{
			cout << "read character " << transitions[i].read_character() << " is not in the tape alphabet.\n";
			valid = false;	
		}
		if(!states.is_element(transitions[i].destination_state()))
		{
			cout << "destination state " << transitions[i].destination_state() << " is not in the set of states.\n";
			valid = false;
		}	
		if(!tape_alphabet.is_element(transitions[i].write_character()))
		{
			cout << "write character " << transitions[i].write_character() << " is not in the tape alphabet.\n";
			valid = false;
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
		cout << ", " << transitions[i].write_character();
		cout << ", " << transitions[i].move_direction() << ")\n";
	}
	cout << "\n";
}

void Transition_Function::find_transition(string source_state, char read_character, 
		string& destination_state, char& write_character, 
		direction& move_direction, bool& found) const
{
	for(int i = 0; i < transitions.size(); ++i)
		if((transitions[i].source_state() == source_state)
		&& (transitions[i].read_character() == read_character))
		{
			destination_state = transitions[i].destination_state();
			write_character = transitions[i].write_character();
			move_direction = transitions[i].move_direction();
			found = true;
			return;
		}
	found = false;
}
