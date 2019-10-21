//Module: Turing Machine
//File: input_alphabet.cpp
//Application: turing machine application
//Language c++
//OS: linux os ubuntu
//Class: cpts 322
//Author: Trevor Surface
//Date: 4/29/2019.

#include "input_alphabet.h"
#include "tape_alphabet.h"
#include "validate.h"
#include "uppercase.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

Input_Alphabet::Input_Alphabet(): alphabet({})
{}

void Input_Alphabet::load(ifstream& definition, bool& valid)
{
	string value;
	while ((definition >> value) && (to_uppercase(value) != "TAPE_ALPHABET:"))
	{
		if(is_valid_char(value))
		{
			alphabet.push_back(value[0]);	
		}
		else
		{
			cout << "input character " << value << " is not a valid input alphabet character.\n\n";
			valid = false;
		}
	}
	if(to_uppercase(value) == "TAPE_ALPHABET:")
		return;
	else 
	{
		cout << "\nkeyword \"tape_alphabet:\" could not be found\n\n";
		valid = false;
	}
}

void Input_Alphabet::validate(const Tape_Alphabet& tape_alphabet, bool& valid) const
{
	for(int i = 0; i < alphabet.size(); ++i)
	{
		if(!tape_alphabet.is_element(alphabet[i]))
		{
			cout << "the input letter "<< alphabet[i] << " is not part of the tape alphabet.\n";
			valid = false;
		}	
	}
}

void Input_Alphabet::view() const
{
	cout << "\u03A3 = {";
	for(int i = 0; i < alphabet.size(); ++i)
	{
		cout << alphabet[i];
		if(i < alphabet.size() -1)
			cout << ", ";
	}
	cout << "}\n\n";
}

bool Input_Alphabet::is_element(const char value) const
{
	for(int i = 0; i < alphabet.size(); ++i)
		if(value == alphabet[i])
			return true;
	return false;
}
