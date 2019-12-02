#ifndef INSTANTANEOUS_DESCRIPTION_H
#define INSTANTANEOUS_DESCRIPTION_H

#include "../headers/configuration_settings.h"
#include <string>

using namespace std;

class Instantaneous_Description
{
    private:
        string current_state;
        
        string remaining_input_string;
        
        string stack;
    
    public:
        Instantaneous_Description();
        Instantaneous_Description(string initial_state, string inputstring, char start_character);
        void view(Configuration_Settings_Pointer configuration_settings_pointer) const;
        void perform_transition(string destination_state, string push_string, Instantaneous_Description& instantaneous_description) const;
        void perform_lamda_transition(string destination_state, string push_string, Instantaneous_Description& instantaneous_description) const;
        string state() const;
        char input_character() const;
        char top_of_stack() const;
        bool is_empty_remaining_input_string() const;
        bool is_empty_stack() const;
};
typedef Instantaneous_Description *Instantaneous_Description_Pointer;

#endif