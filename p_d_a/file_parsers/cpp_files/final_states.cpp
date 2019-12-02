//Module: Turing Machine
//File: final_states.cpp
//Application: turing machine application
//Language c++
//OS: linux os ubuntu
//Class: cpts 322
//Author: Trevor Surface
//Date: 4/29/2019.

#include "../headers/final_states.h"
#include "../headers/states.h"
#include "../../validation/headers/validate.h"
#include "../../validation/headers/uppercase.h"

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

Final_States::Final_States(): names({})
{}

void Final_States::load(ifstream& definition, bool& valid)
{
	string value;
	while (definition >> value)
	{
		if(is_valid_string(value))
			names.push_back(value);
		else
		{
			cout << "final state " << value << "is not a valid final state.\n\n";
			valid = false;
		}
	}
}

void Final_States::validate(States& states, bool& valid) const
{
	for(int i = 0; i < names.size(); ++i)
	{
		if(!states.is_element(names[i]))
		{
			cout << "final state " << names[i] << " is not in states.\n";
			valid = false;
		}
	}
}

void Final_States::view() const
{
	cout << "F = {";
	for(int i = 0; i < names.size(); ++i)
	{
		cout << names[i];
		if(i < names.size() - 1)
			cout << ", ";
	}
	cout << "}\n\n";
}

bool Final_States::is_element(string value) const
{
	for(int i = 0; i < names.size(); ++i)
	{
		if(value == names[i])
			return true;
	}
	return false;
}

