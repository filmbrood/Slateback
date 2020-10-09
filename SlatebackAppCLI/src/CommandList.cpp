#include <slateback.h>
#include "sltcli_pch.h"
#include "CommandList.h"

CommandList CommandList::s_Instance; // Initialize singleton instance of CommandList

// CommandList methods. See CommandList.h for more info.
void CommandList::PushNewCommand(Command* command) 
{
	m_Commands.push_back(command);
}

void CommandList::InitAllCommands()
{
	for (unsigned int i = 0; i < m_Commands.size(); i++)
		m_Commands[i]->OnInit();
}

void CommandList::ClearCommandsFromMemory()
{
	for (unsigned int i = 0; i < m_Commands.size(); i++)
		delete m_Commands[i];

	m_Commands.clear();
}

size_t CommandList::GetCommandCount()
{
	return m_Commands.size();
}

Command* CommandList::GetCommand(unsigned int index)
{
	return m_Commands[index];
}

void CommandList::OnUpdate(const char* argv)
{
	// Checks if argv == 0. If true, will push all commands and display the Help screen by default.
	if (!argv)
	{
		PushNewCommand(new Help);
		PushNewCommand(new NewProject);
		PushNewCommand(new NewCamera);
		PushNewCommand(new NewRoll);
		PushNewCommand(new NewShot);
		PushNewCommand(new Status);
		PushNewCommand(new Print);
		PushNewCommand(new ChangeCamera);
		PushNewCommand(new ChangeProject);
		PushNewCommand(new About);
		PushNewCommand(new ChangeRoll);
		PushNewCommand(new EditProject);
		PushNewCommand(new EditCamera);
		PushNewCommand(new EditShot);
		PushNewCommand(new Take);
		InitAllCommands();

		m_Commands[0]->OnUpdate();
		return;
	}

	std::string userinput = argv;

	PushNewCommand(new Help);
	PushNewCommand(new NewProject);
	PushNewCommand(new NewCamera);
	PushNewCommand(new NewRoll);
	PushNewCommand(new NewShot);
	PushNewCommand(new Status);
	PushNewCommand(new Print);
	PushNewCommand(new ChangeCamera);
	PushNewCommand(new ChangeProject);
	PushNewCommand(new About);
	PushNewCommand(new ChangeRoll);
	PushNewCommand(new EditProject);
	PushNewCommand(new EditCamera);
	PushNewCommand(new EditShot);
	PushNewCommand(new Take);
	InitAllCommands();

	for (unsigned int i = 0; i < m_Commands.size(); i++)
	{
		if (m_Commands[i]->GetInput() == userinput)
		{
			m_Commands[i]->OnUpdate();
			break;
		}
	}

	CommandList::Get().ClearCommandsFromMemory();
}

CommandList& CommandList::Get()
{
	return s_Instance;
}