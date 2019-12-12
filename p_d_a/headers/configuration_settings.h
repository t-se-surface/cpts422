#ifndef CONFIGURATION_SETTINGS_H
#define CONFIGURATION_SETTINGS_H

#include "../validation/headers/uppercase.h"

#include <string>

using namespace std;

class Configuration_Settings
{
    private:
        bool is_updated;
        int maximum_number_of_transitions;
        int maximum_truncation_value;
        bool display_complete_paths;

    public:
        Configuration_Settings();
        Configuration_Settings(string definition_file_name, bool& valid);
        int number_of_transitions() const;
        void set_number_of_transitions(int value);
        int truncation_value() const;
        void set_truncation_value(int value);
        bool show_complete_paths() const;
};
typedef Configuration_Settings *Configuration_Settings_Pointer;

#endif
