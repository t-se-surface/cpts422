//module: Validation
//File: validate.cpp
//Application: turing machine application
//Language c++
//OS: linux os ubuntu
//Class: cpts 322
//Author: Trevor Surface
//Date: 4/29/2019.

#include "../headers/validate.h"

#include <string>
#include <iostream>

using namespace std;

bool is_valid_char(string value)
{
	if(value.length() != 1)
	{
		cout << "the character " << value << " is not a char.\n";
		return false;
	}
	if((value[0] == '[') || (value[0] == ']'))
	{
		cout << "the character " << value << " cannot be either [ or ].\n";
		return false;
	}
	if((value[0] == '<') || (value[0] == '>'))
	{
		cout << "the character " << value << " cannot be either < or >.\n";
		return false;
	}
	if((value[0] <= '!') || (value[0] >= '~'))
	{
		cout << "the character is not a printable cahracter.\n";
		return false;
	}
	return true;
}

bool is_valid_string(string value)
{
	for(int i = 0; i < value.length(); ++i)
	{
		if((value[i] == '[') || (value[i] == ']'))
		{
			cout << "the string " << value << " cannot contain either [ or ].\n";
			return false;
		}
		if((value[i] == '<') || (value[i] == '>'))
		{
			cout << "the string " << value << " cannot contain either < or >.\n";
			return false;
		}
		if((value[i] <= '!') || (value[i] >= '~'))
		{
			cout << "the string has a none printable cahracter.\n";
			return false;
		}
	}
	return true;
}

int is_valid_number(string value)
{
	int return_val = -1;
	if(return_val = stoi(value))
		return return_val;
	else 
	{
		cout << "please enter a valid integer.\n\n";
		return return_val;
	}
}