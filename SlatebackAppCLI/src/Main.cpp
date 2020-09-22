#include "CommandList.h"

#include <iostream>

bool running = true;

int main()
{
	std::string userinput;
	CommandList commands;

	commands.PushNewCommand(new NewProject);
	commands.PushNewCommand(new NewCamera);
	commands.PushNewCommand(new NewRoll);
	commands.PushNewCommand(new NewShot);

	commands.InitAllCommands();

	while (running)
	{
		std::cout << "> ";
		getline(std::cin, userinput);

		commands.OnUpdate(userinput);
	}
}