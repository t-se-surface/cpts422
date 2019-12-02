//Module: Main interface
//File: commands.h
//Application: turing machine application
//Language c++
//OS: linux os ubuntu
//Class: cpts 322
//Author: Trevor Surface
//Date: 4/29/2019.

#include "../headers/commands.h"
#include "../headers/configuration_settings.h"
#include "../headers/push_down_automata.h"
#include "../file_parsers/headers/states.h"
#include "../file_parsers/headers/input_alphabet.h"
#include "../file_parsers/headers/final_states.h"
#include "../file_parsers/headers/transition_function.h"
#include "../validation/headers/validate.h"

#include <vector>
#include <string>
#include <fstream>

using namespace std;

Commands::Commands(string file_name): valid(true), configuration_settings(file_name, valid), 
       			input_strings({}), running(true), push_down_automata(file_name), 
			name_of_push_down_automata(file_name), is_input_string_changed(false)
{
	ifstream definition;
	if(push_down_automata.is_valid_definition() && valid)
	{
		file_name.append(".str");
		string value;
		definition.open(file_name); 
	
		while(definition >> value)
		{
			//May provide check for input strings here, make sure no unnecessary characters
			if(list_check(value))
				input_strings.push_back(value);
		}
		
	}
}

bool Commands::is_running() const
{
	if(push_down_automata.is_valid_definition())
		return running;
}

void Commands::delete_helper()
{
	string input;
	int validation = 0;
	cout << "please indicate which string to delete by number: ";
	getline(cin, input);
	if(input.empty())
	{
		cout << "\n";
		return;
	}
	try
	{
		validation = is_valid_number(input);
	}
	catch(exception& error)
	{
		cout << "\ncoud not convert " << error.what() << ".\n\n";
		return;
	}	
	
	validation = is_valid_number(input);
	if((validation < 0) || (validation > input_strings.size()))
	{
		cout << "\ninvalid number\n\n";
		return;
	}
	cout << "\n" << input_strings[validation - 1] << " was removed from list of strings.\n\n";
	input_strings.erase(input_strings.begin() + validation - 1);
	is_input_string_changed = true;
}

void Commands::exit_helper()
{
	if(is_input_string_changed)
	{
		string file = name_of_push_down_automata;
		ofstream outfile;
		file.append(".str");
		outfile.open(file);
		for(int i = 0; i < input_strings.size(); ++i)
			outfile << input_strings[i] << "\n";
		cout << "new file written\n";
	}
	running = false;
}

void Commands::help_helper() const
{
	cout << "(d)elete	deletes input string from list\n";
	cout << "e(x)it		exit application\n";
	cout << "(h)elp		help user\n";
	cout << "(i)nsert	insert new input string into list\n";
	cout << "(l)ist		list input strings\n";
	cout << "(r)un		run turing machine on input string\n";
	cout << "s(e)t		set maximum number of transitions to preform\n";
	cout << "sho(w)		show status of application\n";
	cout << "(t)runcate	truncate instantaneous descricptions\n";
	cout << "(v)iew		view turing machine\n";
	cout << "(q)uit		quit operation of the turing machine on input string\n\n";
}

void Commands::insert_helper()
{
	string value; 
	cout << "please enter a new string: ";
	getline(cin, value);
	if(value.empty())
	{
		cout << "\n";
		return;
	}
	if(!push_down_automata.is_valid_input_string(value))
	{
		cout << "\nstring " << value << " was not added to the list of input strings.\n\n";
	}
	else
	{
		if(list_check(value))
		{
			input_strings.push_back(value);
			cout << "\n" << input_strings.size() << ". " << value << "\n\n";
			is_input_string_changed = true;
		}
	}
}

void Commands::list_helper() const
{
	if(input_strings.size() > 0)
		for(int i = 0; i < input_strings.size(); ++i)
			cout << i+1 << ". " <<  input_strings[i] << "\n";
	else
		cout << "there are no input strings to display.\n";
	cout << "\n";
}

void Commands::run_helper()
{
	string input;
	int validation = -1;
	if((!push_down_automata.is_used()) || (!push_down_automata.is_operating()))
	{
		cout << "please indicate a string to run by number: ";
		getline(cin, input);
		if(input.empty())
		{
			cout << "\n";
			return;
		}
		try
		{
			validation = is_valid_number(input);
		}
		catch(exception& error)
		{
			cout << "\ncoud not convert " << error.what() << ".\n\n";
			return;
		}
		if(validation > input_strings.size())
		{
			cout << "\ninput out of bounds of list\n\n";
			return;
		}
		push_down_automata.initialize(input_strings[validation-1]);
		cout << "\n";
		push_down_automata.view_instantaneous_description(configuration_settings.truncation_value());
		push_down_automata.perform_transitions(configuration_settings.number_of_transitions());
		push_down_automata.view_instantaneous_description(configuration_settings.truncation_value());
		cout << "\n";
		return;
	}
	if((push_down_automata.is_used()) && (push_down_automata.is_operating()))
	{
		push_down_automata.perform_transitions(configuration_settings.number_of_transitions());
		push_down_automata.view_instantaneous_description(configuration_settings.truncation_value());
		cout << "\n";
		if(push_down_automata.is_accepted_input_string())
		{
			cout << "the string " << push_down_automata.input_string() << " has been accepted in ";
	       		cout << push_down_automata.total_number_of_transitions() << " transitions.\n\n";	
			return;
		}
		if(push_down_automata.is_rejected_input_string())
		{
			cout << "no transition could be performed the string ";
			cout << push_down_automata.input_string() << " is rejected in ";
			cout << push_down_automata.total_number_of_transitions() << " transitions.\n\n";
			return;
		}
		return;
	}
}

void Commands::set_helper()
{
	string input;
	int validation = configuration_settings.number_of_transitions();
	cout << "maximum number of transitions is [" << configuration_settings.number_of_transitions() << "]: ";
	getline(cin, input);
	if(input.empty())
	{
		cout << "\n";
		return;
	}
	try
	{
		validation = is_valid_number(input);
	}
	catch(exception& error)
	{
		cout << "\ncoud not convert " << error.what() << ".\n\n";
		return;
	}
	
	validation = is_valid_number(input);
	if(validation < 0)
	{
		cout << "invlaid number\n\n";
		return;
	}
	//configuration_settings.number_of_transitions() = validation;
	cout << "\nmaximum number of transitions set to: " << configuration_settings.number_of_transitions() << "\n\n";
}

void Commands::show_helper() const
{
	cout << "CPTS350, SEM: 2, YEAR: 2019\n"; 
	cout <<	"INST: NIEL CORRIGAN.\n";
	cout << "AUTH: TREVOR SURFACE\n";
	cout << "V. 1.0.1\n\n";
	cout << "Maximum transitions set " << configuration_settings.number_of_transitions() << ".\n";
	cout << "truncate value set " << configuration_settings.truncation_value() << ".\n\n";
	cout << "TM::" << name_of_push_down_automata << "\n\n"; 
	if(!push_down_automata.is_used())
	{
		cout << "the turing machine has not been used.\n\n";
	}
	if((push_down_automata.is_used()) && (push_down_automata.is_operating()))
	{
		cout << "input string: " << push_down_automata.input_string() << "\n";
		cout << "transitions: " << push_down_automata.total_number_of_transitions() << "\n\n";
	}
	if((push_down_automata.is_used()) && (!push_down_automata.is_operating()))
	{
		cout << "input string: " << push_down_automata.input_string();
		cout << " was";
		
		if(push_down_automata.is_accepted_input_string())
		{
			cout << " accepted";
		}
		if(push_down_automata.is_rejected_input_string())
		{
			cout << " rejected";
		}
		if((!push_down_automata.is_accepted_input_string()) && (!push_down_automata.is_rejected_input_string()))
		{
			cout << " neither accepted or rejected";
		}
 		cout << " in " << push_down_automata.total_number_of_transitions() << " transitions.\n\n";
	}
}

void Commands::truncate_helper()
{
	string input;
    int validation = configuration_settings.truncation_value();
	cout << "current truncation value is [" << configuration_settings.truncation_value() << "]: ";
	getline(cin, input);
	if(input.empty())
	{
		cout << "\n";
		return;
	}
	try
	{
		validation = is_valid_number(input);
	}
	catch(exception& error)
	{
		cout << "\ncoud not convert " << error.what() << ".\n\n";
		return;
	}	
	
	validation = is_valid_number(input);
	if(validation < 0)
	{
		cout << "invlaid number\n\n";
		return;
	}
	//configuration_settings.truncation_value() = validation;
	cout << "\nnew truncation value set to " << configuration_settings.truncation_value() << "\n\n";
}

void Commands::view_helper() const 
{
	push_down_automata.view_definition();
}

void Commands::quit_helper()
{
	push_down_automata.terminate_operation();
}

bool Commands::list_check(string& value)
{
		for(int i = 0; i < input_strings.size(); ++i)
		{
			if(value == input_strings[i])
			{
				cout << "\nduplicate string found at " <<  i +  1;
			       	cout << " string: " << value << " discarded.\n\n";
				is_input_string_changed = true;
				return false;	
			}
		}
		return true;
}
