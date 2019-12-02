//Module: Validation
//File: validate.h
//Application: turing machine application
//Language c++
//OS: linux os ubuntu
//Class: cpts 322
//Author: Trevor Surface
//Date: 4/29/2019.

#ifndef VALIDATE_H
#define VALIDATE_H

#include <string>
#include <iostream>

using namespace std;

bool is_valid_char(string value);
//@param this function takes in a string value
//@func this function checks the value to see if it is a character, 
//then checks if it is a character of value, and not a reserved character.
//After the checks it returns a bool, or an error message.
//@return the function returns a bool

bool is_valid_string(string value);
//@param this function takes in a string value
//@func this function takes in a string and validates its properties to make
//sure the string is made up of non reserved characters and printable ones.
//@return the function returns a bool

int is_valid_number(string value);
//@param this function takes in a string value
//@func this function takes in a string and tries to parse the value,
//to see if the passed in value is a viable number.
//@return the function returns a bool

#endif
