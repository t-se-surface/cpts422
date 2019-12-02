//Module: Push Down Automata
//File: stack_alphabet.cpp
//Application: push down automata
//Language c++
//OS: linux os ubuntu
//Class: cpts 422
//Author: Trevor Surface
//Date: 10/31/2019.

#include "../headers/stack_alphabet.h"
#include "../../validation/headers/validate.h"
#include "../../validation/headers/uppercase.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;


Stack_Alphabet::Stack_Alphabet(): alphabet({})
{}

void Stack_Alphabet::load(ifstream& definition, bool& valid)
{
	string value;
	while ((definition >> value) && (to_uppercase(value) != "TRANSITION_FUNCTION:"))
	{	
		if(is_valid_char(value))
		{
			alphabet.push_back(value[0]);	
		}
		else
		{
			cout << "stack character " << value << " is not a valid input.\n\n";
			valid = false;
		}
	}
	if(to_uppercase(value) == "TRANSITION_FUNCTION:")
		return;
	else 
	{
		cout << "\nkeyword \"transition_function:\" could not be found\n\n";
		valid = false;
	}	

}

void Stack_Alphabet::view() const
{
	cout << "\u0393 = {";
	for(int i = 0; i < alphabet.size(); ++i)
	{
		cout << alphabet[i];
		if(i < alphabet.size() -1)
			cout << ", ";
	}
	cout << "}\n\n";
}

bool Stack_Alphabet::is_element(char value) const
{
	for(int i = 0; i < alphabet.size(); ++i)
		if(value == alphabet[i])
			return true;
	return false;
}