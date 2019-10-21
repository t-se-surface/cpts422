//Module: Turing Machine
//File: tape.cpp
//Application: turing machine application
//Language c++
//OS: linux os ubuntu
//Class: cpts 322
//Author: Trevor Surface
//Date: 4/29/2019.

#include "../headers/tape.h"
#include "../headers/input_alphabet.h"
#include "../headers/tape_alphabet.h"
#include "../headers/direction.h"
#include "../headers/uppercase.h"
#include "../headers/validate.h"

#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

Tape::Tape(): cells(" "), current_cell(0), blank_character(' ')
{}

void Tape::load(ifstream& definition, bool& valid)
{
	string value; 
		if((definition >> value) && (is_valid_char(value)))
			blank_character = value[0];
		else
		{
			cout << "blank character " << value << " is an invalid blank character.\n\n";
			valid = false;	
		}
}

void Tape::validate(const Input_Alphabet& input_alphabet, const Tape_Alphabet& tape_alphabet, bool& valid) const
{
	if(input_alphabet.is_element(blank_character))
	{
		cout << "blank character " << blank_character << " is in the input alphabet\n\n";
		valid = false;
	}
	if(!tape_alphabet.is_element(blank_character))
	{
		cout << "blank character " << blank_character << "is not in the tape alphabet.\n\n";
		valid = false;
	}
}

void Tape::view() const
{
	cout << "B = " << blank_character << "\n\n";
}

void Tape::initialize(string input_string)
{
	cells = input_string + blank_character;
	current_cell = 0;
}

void Tape::update(char write_character, direction move_direction)
{
	exception ex;
	move_direction = toupper(move_direction);
	if((move_direction == 'L') && (current_cell == 0))
		throw ex;
	if((move_direction == 'R') && (current_cell == cells.length() -1))
		cells += blank_character;
	cells[current_cell] = write_character;
	if (move_direction == 'L')
		--current_cell;
	else
		++current_cell;
}

string Tape::left(int maximum_number_of_cells) const
{
	int first_cell = max(0, current_cell - maximum_number_of_cells);
	string value = cells.substr(first_cell, current_cell - first_cell);
	if (value.length() < current_cell)
		value.insert(0, "<");
	return value;
}

string Tape::right(int maximum_number_of_cells) const
{
	int end_cell = cells.length() - 1;
	while((end_cell >= current_cell) && (cells[end_cell] == blank_character))
		--end_cell;
	int last_cell = min(end_cell, current_cell + maximum_number_of_cells - 1);
	string value = cells.substr(current_cell, last_cell - current_cell + 1);
	if(value.length() < end_cell - current_cell + 1)
		value.append(">");
	return value;
}

char Tape::current_character() const
{
	return cells[current_cell];
}

bool Tape::is_first_cell() const
{
	return (current_cell == 0);
}
