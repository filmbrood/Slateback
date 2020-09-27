#include "Command.h"

std::string Command::GetInput()
{
	return m_Input;
}

void Command::SetInput(std::string input)
{
	m_Input = input;
}

std::string Command::GetDesc()
{
	return m_Desc;
}

void Command::SetDesc(std::string desc)
{
	m_Desc = desc;
}
