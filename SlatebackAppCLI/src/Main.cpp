#include "CommandList.h"

#include <iostream>

bool running = true;

int main(int argc, char** argv)
{
	CommandList::Get().PushNewCommand(new NewProject);
	CommandList::Get().PushNewCommand(new NewCamera);
	CommandList::Get().PushNewCommand(new NewRoll);
	CommandList::Get().PushNewCommand(new NewShot);
	CommandList::Get().PushNewCommand(new Status);
	CommandList::Get().PushNewCommand(new Print);
	CommandList::Get().PushNewCommand(new Help);
	CommandList::Get().PushNewCommand(new ChangeProject);
	CommandList::Get().InitAllCommands();

	CommandList::Get().OnUpdate(argv[1]);

	CommandList::Get().ClearCommandsFromMemory();

	return 0;
}