//module: Validate
//File: uppercase.cpp
//Application: turing machine application
//Language c++
//OS: linux os ubuntu
//Class: cpts 322
//Author: Trevor Surface
//Date: 4/29/2019.

#include <string>

using namespace std;

string to_uppercase(string& value)
{
	char letter;
	string return_string = value;
	for(int i = 0; i < value.length(); ++i)
	{
		letter = return_string[i];
		return_string[i] = toupper(letter);
	}
	return return_string;
}

