#include "../headers/configuration_settings.h"
#include "../validation/headers/uppercase.h"

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

Configuration_Settings::Configuration_Settings()
{}

Configuration_Settings::Configuration_Settings(string definition_file_name, bool& valid): is_updated(false)
{
    ifstream definition;
    definition_file_name.append(".cfg");
    string value;
    int int_value;
    definition.open(definition_file_name);
    if(definition.good())
    {
        definition >> value;
        if(value[19] == '=')
        {
            int_value = stoi(value.substr(20, value.length() + 1));       
            maximum_number_of_transitions = int_value;
        }
        else
        {
            cout << "configuration setting " << value << "is invalid\n\n";
            valid = false;
        }
        definition >> value;
        if(value[18] == '=')
        {
            int_value = stoi(value.substr(19, value.length() + 1));       
            maximum_truncation_value = int_value;
        }
        else 
        {
            cout << "configuration setting " << value << "is invalid\n\n";
            valid = false;
        }
        definition >> value;
        if(value[14] == '=')
        {
            value = value.substr(15, value.length() + 1);       
            if(to_uppercase(value) == "NO")
                display_complete_paths = false;
            else if(to_uppercase(value) == "YES")
                display_complete_paths = true;
            else
            {
                cout << "configuration setting complete_paths cannot be set to " << value << "\n";
                valid = false;
            }
            
        }
        else 
        {
            cout << "configuration setting " << value << "is invalid\n\n";
            valid = false;
        }
        valid = true;
    }
}

int Configuration_Settings::number_of_transitions() const
{ return maximum_number_of_transitions; }

int Configuration_Settings::truncation_value() const
{ return maximum_truncation_value; }

bool Configuration_Settings::show_complete_paths() const
{ return display_complete_paths; }

void Configuration_Settings::change_complete_paths()
{
    display_complete_paths = !display_complete_paths;
}