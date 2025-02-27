//Module: Main interface
//File: commands.h
//Application: turing machine application
//Language c++
//OS: linux os ubuntu
//Class: cpts 422

#include "../headers/instantaneous_description.h"
#include "../file_parsers/headers/transition_function.h"
#include "../file_parsers/headers/transition.h"

#include <string>
#include <iostream>
#include <vector>

using namespace std;

Instantaneous_Description::Instantaneous_Description()
{}

Instantaneous_Description::Instantaneous_Description(string initial_state, string input_string, string current_stack, int parent):
                                                                     current_state(" "), remaining_input_string(" "), stack(" ")
{
  pid = parent;
  current_state = initial_state;
  remaining_input_string = input_string;
  stack = current_stack;
}

void Instantaneous_Description::view(int truncation_value) const
{
  //TODO Add check for truncation based on passed in configuration settings.
  // if (remaining_input_string.length() <= configuration_settings_pointer->maximum_truncation_value && stack.length() <= configuration_settings_pointer->maximum_truncation_value)
  // {
    cout << "[" << current_state << "] ";
    cout << "(" << remaining_input_string << ") ";
    cout << stack << endl;
  // } else {
  //   //TODO truncate the remaining_input_string and stack
  // }
}

vector<Instantaneous_Description> Instantaneous_Description::perform_transition(Transition_Function transition_function, int& crashes, bool& found) const
{
  vector<Instantaneous_Description> temp_IDs;
  vector<Transition> transitions;
  string temp_input_string;
  string temp_stack;
  Instantaneous_Description garbage(temp_stack, temp_stack, temp_stack, 5);

  if (remaining_input_string.length() != 0)
  {
    temp_input_string = remaining_input_string;
    temp_input_string.erase(temp_input_string.begin());
  }
  else
    temp_input_string = '\0';

  transitions = transition_function.find_transitions(state(), input_character(), top_of_stack(), found);

  if (found)
  {
    for(vector<Transition>::iterator it = transitions.begin(); it != transitions.end(); ++it)
    {
      string stack_characters = it->push_stack_characters();

      temp_stack = stack;
      temp_stack.erase(0, 1);
      if (stack_characters[0] != '\\')
        temp_stack.insert(0, it->push_stack_characters());

      Instantaneous_Description t_ID(it->destination_state(), temp_input_string, temp_stack, id);
      temp_IDs.push_back(t_ID);
    }
    return temp_IDs;
  }
  else
  {
    temp_IDs.push_back(garbage);
    return temp_IDs;
  }
}

string Instantaneous_Description::state() const
{
    return current_state;
}

char Instantaneous_Description::input_character() const
{
    if (remaining_input_string.length() != 0)
      return remaining_input_string[0];
    else
      return '\0';
}

char Instantaneous_Description::top_of_stack() const
{ return stack[0]; }

bool Instantaneous_Description::is_empty_remaining_input_string() const
{
  if(remaining_input_string[0] == '\0')
  {
    return true;
  }
  else
    return false;
}

bool Instantaneous_Description::is_empty_stack() const
{
  if(stack.length() == 0)
    return true;
  else
    return false;
}
