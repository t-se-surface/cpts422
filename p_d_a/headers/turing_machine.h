//module: Turing Machine
//File: turing_machine.cpp
//Application: turing machine application
//Language c++
//OS: linux os ubuntu
//Class: cpts 322
//Author: Trevor Surface
//Date: 4/29/2019.

#ifndef TURING_MACHINE_H
#define TURING_MACHINE_H

#include "tape.h"
#include "input_alphabet.h"
#include "tape_alphabet.h"
#include "transition_function.h"
#include "states.h"
#include "final_states.h"

#include <string>
#include <vector>

using namespace std;

class Turing_Machine
{
	private:
		Tape tape;
		//@param creates instance of tape
		
		Input_Alphabet input_alphabet;
		//@param creates instance of input_alphabet

		Tape_Alphabet tape_alphabet;
		//@param creates instance of tape_alphabet

		Transition_Function transition_function;
		//@param creates instance of transition_function

		States states;
		//@param creates instance of states

		Final_States final_states;
		//@param creates instance of final_states

		vector<string> description;
		//@param list of strings to hold description from definition file

		string initial_state;
		//@param string that saves the initial state from definition file

		string current_state;
		//@param string that saves the current state from transitions

		string original_input_string;
		//@param string keeps track of last input string
	
		int number_of_transitions;
		//@param int keeps track of the number of transitions

		bool valid;
		//@param bool that provides valid turing machine
		
		bool used;
		//@param bool that provides if turing machine is being used

		bool operating;
		//@param bool that provides if turing machine is operating

		bool accepted;
		//@param bool that provides if the input string is accepted

		bool rejected;
		//@param bool that provides if the input string is rejected

	public:
		Turing_Machine(string definition_file_name);
		//@param this function takes in a string definition file name
		//@func this function tries to open the file passed into the turing machine
		//and builds the turing machine validating everything in the def file as
		//it builds
		//@return this function is void
		
		void view_definition() const;
		//@param this function takes no parameters
		//@func this function provides a visual for the user of the def file. Formatted
		//with mathmatical intention, using greek symbols
		//@return this function is void

		void view_instantaneous_description(int maximum_number_of_cells) const;
		//@param this function takes an int maximum number of cells
		//@func this function provides to the user the instantaneous description
		//@return this function is void

		void initialize(string input_string);
		//@param this function takes a string input string
		//@func this function checks if the turing machine is used, if it is not, it
		//then initializes the string and starts operation on the string
		//@return this function is void

		void perform_transitions(int maximum_number_of_transitions);
		//@param this function takes an int maximum number of transitions
		//@func this function is what looks for a transition and then performs the 
		//transition
		//@return this function is void
		
		void terminate_operation();
		//@param this function takes no input
		//@func this function checks if the turing machine is running, it then terminates
		//without accepting of rejecting the string
		//@return this function is void
		
		string input_string() const;
		//@param this function takes no input
		//@func this fucntion returns the used input string
		//@return this function returns a string 
		
		int total_number_of_transitions() const;
		//@param this function takes no input
		//@func this function returns the number of transitions performed
		//@return this function returns an int
		
		bool is_valid_definition() const;
		//@param this function takes no input
		//@func this function returns true if the turing machine is valid
		//@returnthis function returns a bool
		
		bool is_valid_input_string(string& value) const;
		//@param this function takes a reference to a string value
		//@func this function returns true if the passed in value is a valid string
		//@returnthis function returns a bool
		
		bool is_used() const;
		//@param this function takes no input
		//@func this function returns the value of the used bool
		//@returnthis function returns a bool
		
		bool is_operating() const;
		//@param this function takes no input
		//@func this function returns the value of the operating bool 
		//@returnthis function returns a bool
		
		bool is_accepted_input_string() const;
		//@param this function takes no input
		//@func this function returns the value of the accepted bool
		//@returnthis function returns a bool
		
		bool is_rejected_input_string() const;
		//@param this function takes no input
		//@func this function returns the value of the rejected bool
		//@return this function returns a bool
};	
#endif
