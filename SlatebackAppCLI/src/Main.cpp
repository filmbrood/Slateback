#include "CommandList.h"

#include <iostream>

bool running = true;

int main(int argc, char** argv)
{
	CommandList commands;
	commands.PushNewCommand(new NewProject);
	commands.PushNewCommand(new NewCamera);
	commands.PushNewCommand(new NewRoll);
	commands.PushNewCommand(new NewShot);
	commands.PushNewCommand(new SerializerTest);
	commands.InitAllCommands();

	commands.OnUpdate(argv[1]);

	return 0;
}