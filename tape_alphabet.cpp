//Module: Turing Machine
//File: tape_alphabet.cpp
//Application: turing machine application
//Language c++
//OS: linux os ubuntu
//Class: cpts 322
//Author: Trevor Surface
//Date: 4/29/2019.

#include "tape_alphabet.h"
#include "validate.h"
#include "uppercase.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

Tape_Alphabet::Tape_Alphabet(): alphabet({})
{}

void Tape_Alphabet::load(ifstream& definition, bool& valid)
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
			cout << "tape character " << value << " is not a valid input alphabet character.\n\n";
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

void Tape_Alphabet::view() const
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

bool Tape_Alphabet::is_element(char value) const
{
	for(int i = 0; i < alphabet.size(); ++i)
		if(value == alphabet[i])
			return true;
	return false;
}
