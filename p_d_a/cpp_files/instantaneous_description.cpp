//Module: Main interface
//File: commands.h
//Application: turing machine application
//Language c++
//OS: linux os ubuntu
//Class: cpts 422

#include "../headers/instantaneous_description.h"

#include <string>
#include <iostream>

using namespace std;

Instantaneous_Description::Instantaneous_Description()
{}

Instantaneous_Description::Instantaneous_Description(string initial_state, string input_string, char start_character, int parent):
                                                                     current_state(" "), remaining_input_string(" "), stack(" ")
{
  pid = parent;
  current_state = initial_state;
  remaining_input_string = input_string;
  stack = start_character
}

void Instantaneous_Description::view(Configuration_Settings_Pointer configuration_settings_pointer) const
{
  //TODO Add check for truncation based on passed in configuration settings.
  if (remaining_input_string.length() <= configuration_settings_pointer->maximum_truncation_value && stack.length() <= configuration_settings_pointer->maximum_truncation_value)
  {
    cout << "[" << current_state << "] ";
    cout << "(" << remaining_input_string << ") ":
    cout << stack << endl;
  } else {
    //TODO truncate the remaining_input_string and stack
  }
}

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
    return remaining_input_string[0];
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
