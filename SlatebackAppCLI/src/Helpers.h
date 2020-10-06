#pragma once
#include <string>

// Miscellaneous functions for repetitive tasks that don't fit anywhere else.

void LoadSltProjXML(const std::string& errormessage = "Must create project first"); // Loads in ProjectVector data into new ProjectVector instance, then copies that data into the Controller's ProjectVector member
void UserPrompt(std::string& userinput, const std::string& message); // Outputs " > " to the screen and obtains user input, can display a message before the " > "