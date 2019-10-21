//Module: Turing Machine
//File: states.cpp
//Application: turing machine application
//Language c++
//OS: linux os ubuntu
//Class: cpts 322
//Author: Trevor Surface
//Date: 4/29/2019.

#include "../headers/states.h"
#include "../headers/validate.h"
#include "../headers/uppercase.h"

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

States::States(): names({})
{}

void States::load(ifstream& definition, bool& valid)
{
	string value;
	while ((definition >> value) && (to_uppercase(value) != "INPUT_ALPHABET:"))
	{
		if(is_valid_string(value))
			names.push_back(value);
		else
		{
			cout << "state " << value << " is not a valid state.\n\n";
			valid = false;
		}
	}
	if(to_uppercase(value) == "INPUT_ALPHABET:")
		return;
	else 
	{
		cout << "\nkeyword \"input_alphabet:\" could not be found\n\n";
		valid = false;
	}
}

void States::view() const
{
	cout << "Q = {";
	for(int i = 0; i < names.size(); ++i)
	{
		cout << names[i];
		if(i < names.size() -1)
			cout << ", ";
	}
	cout << "}\n\n";
}

bool States::is_element(string value) const
{
	for(int i = 0; i < names.size(); ++i)
		if(value == names[i])
			return true;
	return false;
}

