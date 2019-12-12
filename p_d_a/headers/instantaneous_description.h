#ifndef INSTANTANEOUS_DESCRIPTION_H
#define INSTANTANEOUS_DESCRIPTION_H

#include "../headers/configuration_settings.h"
#include "../file_parsers/headers/transition_function.h"
#include "../file_parsers/headers/transition.h"

#include <string>
#include <vector>

using namespace std;

class Instantaneous_Description
{
    private:
        string current_state;

        string remaining_input_string;

        string stack;

        int id;

        int pid;

    public:
        Instantaneous_Description();
        Instantaneous_Description(string state, string input_string, string current_stack, int pid);
        void view(Configuration_Settings_Pointer configuration_settings_pointer) const;
        vector<Instantaneous_Description> perform_transition(Transition_Function transition_function, int& crashes, bool& found) const;
        string state() const;
        char input_character() const;
        char top_of_stack() const;
        bool is_empty_remaining_input_string() const;
        bool is_empty_stack() const;
};
typedef Instantaneous_Description *Instantaneous_Description_Pointer;

#endif
