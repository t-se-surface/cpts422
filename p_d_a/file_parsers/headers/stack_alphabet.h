//Module: Turing Machine
//File: tape_alphabet.h
//Application: turing machine application
//Language c++
//OS: linux os ubuntu
//Class: cpts 322
//Author: Trevor Surface
//Date: 4/29/2019.

#ifndef STACK_ALPHABET_H
#define STACK_ALPHABET_H

#include "../../validation/headers/validate.h"
#include "../../validation/headers/uppercase.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Stack_Alphabet
{
    private:
        vector<char> alphabet;
        //@param this creates a vector in which the stack alphabet will be stored

    public:
        Stack_Alphabet();
        //@param the constructor for the Stack_Alphabet class

        void load(ifstream& definition, bool& valid);
        //@param takes a file descriptor and a boolean value
        //@func this function reads from pda file and loads the Stack_Alphabet
        //will also validate all strings read in, and return false if an error occurs
        //@return there is no return value

        void view() const;
        //@param takes no parameters
        //@func allows the user to view the Stack_Alphabet
        //@return has no return value

        bool is_element(char value) const;
        //@param takes in a character
        //@func checks the see if a passed in value is part of the Stack_Alphabet
        //@return returns a boolean

};

#endif
