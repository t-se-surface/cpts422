//module: Turing Machine
//File: turing_machine.cpp
//Application: turing machine application
//Language c++
//OS: linux os ubuntu
//Class: cpts 322
//Author: Trevor Surface
//Date: 4/29/2019.

#include "../headers/push_down_automata.h"
#include "../file_parsers/headers/states.h"
#include "../file_parsers/headers/input_alphabet.h"
#include "../file_parsers/headers/stack_alphabet.h"
#include "../file_parsers/headers/transition_function.h"
#include "../file_parsers/headers/final_states.h"
#include "../validation/headers/validate.h"
#include "../validation/headers/uppercase.h"
#include "../headers/instantaneous_description.h"

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

Push_Down_Automata::Push_Down_Automata(string definition_file_name): description({}), valid(true), initial_state(" "),
							current_state(" "), start_character(" "), original_input_string(" "), number_of_transitions(0),
							used(false), operating(false), accepted(false), rejected(false)
{
	ifstream definition;
	definition_file_name.append(".def");
	string value, value2;
	definition.open(definition_file_name);
	if(definition.good())
	{
		int pos = 0;
		while(getline(definition,value))
		{
			int found = value.find(":");
			if((found != -1) && (found > 5))
			{
				if(found > 11)
				{
					value2 = value.substr(found-12, found + 1);
					if(to_uppercase(value2) == "FINAL_STATES:")
					{
						cout << "\nkeyword \"states:\" could not be found\n\n";
						valid = false;
					}
				}
				value2 = value.substr(found - 6, found + 1);
				if(to_uppercase(value2) == "STATES:")
				{
					int length = definition.tellg();
					definition.seekg(length - value.length() + found);
					states.load(definition, valid);
					break;
				}
			}
			else
			{
				description.push_back(value);
				pos += value.length();
			}
		}
		input_alphabet.load(definition, valid);
		stack_alphabet.load(definition, valid);
		transition_function.load(definition, valid);
		if((definition >> value) && (to_uppercase(value) == "INITIAL_STATE:"))
		{
			if((definition >> value) && (is_valid_string(value)))
				initial_state = value;
			else
			{
				cout << "\ninitial state " << value << " is not a legal state.\n\n";
				valid = false;
			}
		}
		if((definition >> value) && (to_uppercase(value) == "START_CHARACTER:"))
		{
			if((definition >> value) && (is_valid_string(value)))
				start_character = value;
			else
			{
				cout << "\nstart character " << value << " is not a legal character.\n\n";
				valid = false;
			}
		}
		if((definition >> value) && (to_uppercase(value) == "FINAL_STATES:"))
			final_states.load(definition, valid);
		else
		{
			cout << "\nkeyword \"final_states:\" could not be found.\n\n";
			valid = false;
		}
		if(valid)
		{
			final_states.validate(states, valid);
		}
		if(valid)
			cout << "\n" << definition_file_name << " loaded successfully.\n\n";
	}
	else
	{
		cout << "\nan error occured with file " << definition_file_name << "\n\n";
		valid = false;
	}
	definition.close();
}

void Push_Down_Automata::view_definition() const
{
	for(int i = 0; i < description.size(); ++i)
		cout << description[i] << "\n";
	states.view();
	input_alphabet.view();
	transition_function.view();
	cout << "q0 = " << initial_state << "\n\n";
	final_states.view();
}

void Push_Down_Automata::view_instantaneous_description(int maximum_number_of_cells) const
{
	if((used || operating) && (original_input_string != " "))
	{
		cout << "   " << number_of_transitions << ".";
		cout << "[" << current_state << "]";
		cout <<"\n";
	}
	else
	{
		cout << "turing machine is not operating.\n";
	}
}

void Push_Down_Automata::initialize(string input_string)
{

	if(!used || !operating)
	{
		original_input_string = input_string;
		accepted = false;
		rejected = false;
		current_state = initial_state;
		number_of_transitions = 0;
		if(!used)
			used = !used;
		if(!operating)
			operating = !operating;
	}
}

void Push_Down_Automata::perform_transitions(int maximum_number_of_transitions)
{
	bool found = false;
	string destination_state;
	char write_character;
	vector<Instantaneous_Description> temp_ID;
	vector<Instantaneous_Description> result_ID;

	for(int i = 0; i < maximum_number_of_transitions; ++i)
	{
		for(vector<Instantaneous_Description>::iterator it = instantaneous_descriptions.begin(); it != instantaneous_descriptions.end(); ++it)
		{
			if(final_states.is_element(it->state()))
			{
				accepted = true;
				operating = false;
				return;
			}

			temp_ID = it->perform_transition(transition_function, crashes, found);

			for(vector<Instantaneous_Description>::iterator it2 = temp_ID.begin(); it2 != temp_ID.end(); ++it2)
			{
				result_ID.push_back((*it2));
			}

			if(found)
			{
				current_state = destination_state;
				++number_of_transitions;
			}
			else
			{
				rejected = true;
				operating = false;
				return;
			}
		}
	}
	instantaneous_descriptions = result_ID;
}

void Push_Down_Automata::terminate_operation()
{
	if(operating)
	{
		operating = !operating;
		cout << "user has terminated operation on string in " << number_of_transitions << " transitions.\n\n";
		accepted = false;
		rejected = false;
	}
	else
		cout << "turing machine is currently not operating.\n\n";
}

string Push_Down_Automata::input_string() const
{
	return original_input_string;
}

int Push_Down_Automata::total_number_of_transitions() const
{
	return number_of_transitions;
}

bool Push_Down_Automata::is_valid_definition() const
{
	return valid;
}

bool Push_Down_Automata::is_valid_input_string(string& value) const
{
	for(int i = 0; i < value.size(); ++i)
	{
		if(!input_alphabet.is_element(value[i]))
		{
			cout << "\ninvalid input string " << value << "\n\n";
			return false;
		}
	}
	return true;
}

bool Push_Down_Automata::is_used() const
{
	return used;
}

bool Push_Down_Automata::is_operating() const
{
	return operating;
}

bool Push_Down_Automata::is_accepted_input_string() const
{
	return accepted;
}

bool Push_Down_Automata::is_rejected_input_string() const
{
	return rejected;
}