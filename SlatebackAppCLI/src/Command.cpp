#include "sltcli_pch.h"

#include "Command.h"

// Command class methods. See Command.h for more info.
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
