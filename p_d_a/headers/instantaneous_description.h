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
        //@param contains the current state of the ID

        string remaining_input_string;
        //@param contains the entirety of the remaining imput string

        string stack;
        //@param contains the entirity of the stack of the ID

        int id;
        //@param contains the id for the specific ID

        int pid;
        //@param contains the id for the parent ID

    public:
        Instantaneous_Description();
        //@param this function takes no parameters
    		//@func this function is the default constructor for the ID

        Instantaneous_Description(string state, string input_string, string current_stack, int pid);
        //@param this function takes a string for the current state
        //@param this function takes a string of the input string
        //@param this function takes a string of the current stack
        //@param this function takes an int of its parent ID's id
    		//@func this function is the constructor for an ID

        void view(int truncation_value) const;
        //@param this function takes an int for truncation value
    		//@func this function displays the current ID
    		//@return this function is void

        vector<Instantaneous_Description> perform_transition(Transition_Function transition_function, int& crashes, bool& found) const;
        //@param this function takes a bool to tell if there are any transitions from the current ID
        //@param this function takes an int containing how many times the currently running pda has crashed
        //@param this function takes a transition_function that contains all transitions in the pda
    		//@func this function performs transitions on the ID
        //@return this function is a vector of ID's

        string state() const;
        //@param this function takes no input
    		//@func this function returns the current state of the ID
    		//@returnthis function returns a string

        char input_character() const;
        //@param this function takes no input
    		//@func this function returns the first character in the input string
    		//@returnthis function returns a char

        char top_of_stack() const;
        //@param this function takes no input
    		//@func this function returns the top character on the stack
    		//@returnthis function returns a char

        bool is_empty_remaining_input_string() const;
        //@param this function takes no input
    		//@func this function checks if the input string is empty or not
    		//@returnthis function returns a bool

        bool is_empty_stack() const;
        //@param this function takes no input
    		//@func this function checks if the stack is empty or not
    		//@returnthis function returns a bool
};
typedef Instantaneous_Description *Instantaneous_Description_Pointer;

#endif
