#pragma once
#include <string>

// Abstract class to be inherited by commands for CommandList. Must define OnInit() and OnUpdate() in children.
class Command
{
public:
	virtual void OnInit() = 0;
	virtual void OnUpdate() = 0;

	virtual void SetInput(std::string input); // Sets m_Input string.
	virtual void SetDesc(std::string desc); // Sets m_Desc string
	virtual std::string GetInput(); // Returns m_Input string
	virtual std::string GetDesc(); // Returns m_Desc string

private:
	std::string m_Input; // What string the user must enter for this command to execute.
	std::string m_Desc; // Description that will show alongside command when 'help' command is inputted.
};