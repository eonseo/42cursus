#pragma once

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>

// input.cpp
std::string readCommand();
void clearBuffer();
int isEOF();
std::string getValidInput(std::string information);
int isValidString(std::string tmp);
int isValidPhoneNumber(std::string tmp);

// main.cpp
void printIntro();
void printCommands();

// search.cpp
void printCell(std::string str);
