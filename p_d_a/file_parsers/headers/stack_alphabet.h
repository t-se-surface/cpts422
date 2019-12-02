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
    
    public:
        Stack_Alphabet();

        void load(ifstream& definition, bool& valid);

        void view() const;

        bool is_element(char value) const;

};

#endif