#include "Command.h"

std::string Command::GetInput()
{
	return m_Input;
}

void Command::SetInput(std::string input)
{
	m_Input = input;
}