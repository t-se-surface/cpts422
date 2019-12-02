//Module: Push Down Automata
//File: transition.cpp
//Application: push down automata
//Language c++
//OS: linux os ubuntu
//Class: cpts 422
//Author: Trevor Surface
//Date: 10/31/2019.

#include "../headers/transition.h"

#include <string>

using namespace std;

Transition::Transition(string source_state, char read_character, char read_stack_character,
				string destination_state, string push_stack_string):
				source(source_state), read(read_character), read_stack(read_stack_character), 
				destination(destination_state), push(push_stack_string)
{}

string Transition::source_state() const
{
	return source;
}
char Transition::read_character() const
{
	return read;
}

char Transition::read_stack_character() const
{
	return read_stack;
}

string Transition::destination_state() const
{
	return destination;
}

string Transition::push_stack_characters() const
{
	return push;
}