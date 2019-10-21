//Module: Main Interface
//File: commands.h
//Application: turing machine application
//Language c++
//OS: linux os ubuntu
//Class: cpts 322
//Author: Trevor Surface
//Date: 4/29/2019.



#ifndef COMMANDS_H
#define COMMANDS_H

#include "turing_machine.h"
#include "tape.h"
#include "states.h"
#include "input_alphabet.h"
#include "tape_alphabet.h"
#include "final_states.h"
#include "transition_function.h"

#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Commands
{
	private:
		bool running;
		//@param this initiates the run of the program

		bool is_input_string_changed;
		//@param this sets when the list of inputs strings is altered

		int maximum_number_of_transitions;
		//@param configuration setting for number of transitions

		int maximum_truncation_value;
		//@param configuration setting for truncation of instantaneous description
		
		string name_of_turing_machine;
		//@param stores the name of turing machine for later use 

		vector<string> input_strings;
		//@param stores the list of input string from the .str file

		Turing_Machine turing_machine;
		//@param this provides the instance of the turing machine itself

	public:
		Commands(string file_name);
		//@param this function takes in a string file name
		//@func this is the default constructor that loads the files
		//@return this function has no return value

		bool is_running() const;
		//@param this function takes no arguments
		//@func this function returns the value of the private running boolean
		//@return this function returns a bool 

		void delete_helper();
		//@param this function takes no parameters
		//@func this function allows the user to delete a string from the list of 
		//input strings
		//@return this function has no return
		
		void exit_helper();
		//@param this function takes no parameters
		//@func this function allows the user to exit the application
		//@return this function has no return
		
		void help_helper() const;
		//@param this function takes no parameters
		//@func this function allows the user to see the character for each command
		//and what the command does
		//@return this function has no return
		
		void insert_helper();
		//@param this function takes no parameters
		//@func this function allows the user to insert a new string into the 
		//list of input strings
		//@return this function has no return
		
		void list_helper() const;
		//@param this function takes no parameters
		//@func this function allows the user to see the list of input strings
		//currently stored int he commands program
		//@return this function has no return
		
		void run_helper();
		//@param this function takes no parameters
		//@func this function allows the user to actually run transitions on
		//an input string, or select an input string to use
		//@return this function has no return
		
		void set_helper();
		//@param this function takes no parameters
		//@func this function allows the user to change to amount of transitions 
		//performed on the input string
		//@return this function has no return
		
		void show_helper() const;
		//@param this function takes no parameters
		//@func this function allows the user to see important information about
		//the current turing machine 
		//@return this function has no return
		
		void truncate_helper();
		//@param this function takes no parameters
		//@func this function allows the user to change the truncation value
		//@return this function has no return
		
		void view_helper() const;
		//@param this function takes no parameters
		//@func this function allows the user to see the contents of the 
		//definition file in original format
		//@return this function has no return
		
		void quit_helper();
		//@param this function takes no parameters
		//@func this function allows the user to quit operation on an input 
		//string
		//@return this function has no return

		bool list_check(string& value);
		//@param this function takes a reference to a string value
		//@func this function checks the passed in value to the list of strings 
		//to validate the passed in string
		//@return this function returns a bool
};

#endif
