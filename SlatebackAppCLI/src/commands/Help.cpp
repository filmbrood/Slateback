#include "sltcli_pch.h"

void Help::OnInit()
{
	SetInput("help");
	SetDesc("Displays list of functions.");
}

void Help::OnUpdate()
{
	auto commands = CommandList::Get();
	for (unsigned int i = 0; i < commands.GetCommandCount(); i++)
		std::cout << commands.GetCommand(i)->GetInput() << " - " << commands.GetCommand(i)->GetDesc() << std::endl;
}