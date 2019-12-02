//Module: Main interface
//File: commands.h
//Application: turing machine application
//Language c++
//OS: linux os ubuntu
//Class: cpts 322
//Author: Trevor Surface
//Date: 4/29/2019.

#include "../headers/instantaneous_description.h"

#include <string>
#include <iostream>

using namespace std;

Instantaneous_Description::Instantaneous_Description()
{}

Instantaneous_Description::Instantaneous_Description(string initial_state, string inputstring, char start_character):
                                                                     current_state(" "), remaining_input_string(" "), stack(" ")
{}

void Instantaneous_Description::view(Configuration_Settings_Pointer configuration_settings_pointer) const
{}

void Instantaneous_Description::perform_transition(string destination_state, string push_string, Instantaneous_Description& instantaneous_description) const
{}

void Instantaneous_Description::perform_lamda_transition(string destination_state, string push_string, Instantaneous_Description& instantaneous_description) const
{}

string Instantaneous_Description::state() const
{
    return current_state;
}

char Instantaneous_Description::input_character() const
{
    return 'a';
}

char Instantaneous_Description::top_of_stack() const
{ return stack[0]; }

bool Instantaneous_Description::is_empty_remaining_input_string() const
{
    return false;
}

bool Instantaneous_Description::is_empty_stack() const
{
    return false;
}