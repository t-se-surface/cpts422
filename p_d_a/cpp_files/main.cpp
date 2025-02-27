//module: Main interface
//File: commands.h
//Application: turing machine application
//Language c++
//OS: linux os ubuntu
//Class: cpts 322
//Author: Trevor Surface
//Date: 4/29/2019.

#include "../headers/push_down_automata.h"
#include "../file_parsers/headers/states.h"
#include "../file_parsers/headers/input_alphabet.h"
#include "../file_parsers/headers/final_states.h"
#include "../file_parsers/headers/transition_function.h"
#include "../headers/commands.h"

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	const int success(0);
	if(argc != 2)
	{
		cout << "\nplease specify a file name.\n\n";
		return success;
	}
	string input;
	bool validation;
	bool valid;
	Commands command(argv[1]);
	while(command.is_running())
	{
		cout << "command: ";
		getline(cin, input);
		cout << "\n";
		if(input.empty())
		{
			cout << input << "\n";
			valid = false;
		}
		else
			valid = true;
		if(valid)
		{
			try
			{
				validation = is_valid_char(input);
			}
			catch(exception& error)
			{
				cout << "\ncoud not convert " << error.what() << ".\n\n";
				validation = false;
			}
			if(validation)
			{
				if(input[0] == 'q' || input[0] == 'Q') //yes
					command.quit_helper();
				if(input[0] == 'o' || input[0] == 'O')
				 	command.open_helper();
				if(input[0] == 'c' || input[0] == 'C')
					command.close_helper();
				if(input[0] == 'h' || input[0] == 'H') //yes
					command.help_helper();
				if(input[0] == 'l' || input[0] == 'L') //yes
					command.list_helper();
				if(input[0] == 'i' || input[0] == 'I') //yes
					command.insert_helper();
				if(input[0] == 'p' || input[0] == 'P')
					command.display_helper();
				if(input[0] == 'r' || input[0] == 'R') //yes
					command.run_helper();
				if(input[0] == 'w' || input[0] == 'W') //yes
					command.show_helper();
				if(input[0] == 'v' || input[0] == 'V') //yes
					command.view_helper();
				if(input[0] == 'x' || input[0] =='X') //yes
					command.exit_helper();
		//		else //find way to include, may change to case statement with to uppercase
		//		{
		//			cout << "\tplease use a valid use character.\n";
		//			cout << "\tfor list of characters use (h).\n\n";
		//		}
			}
		}
	}
	cout << "exit successful\n";
	return success;
}
