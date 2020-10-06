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
	std::string userinput = argv;
	CommandList::Get().PushNewCommand(new NewProject);
	CommandList::Get().PushNewCommand(new NewCamera);
	CommandList::Get().PushNewCommand(new NewRoll);
	CommandList::Get().PushNewCommand(new NewShot);
	CommandList::Get().PushNewCommand(new Status);
	CommandList::Get().PushNewCommand(new Print);
	CommandList::Get().PushNewCommand(new Help);
	CommandList::Get().PushNewCommand(new ChangeCamera);
	CommandList::Get().PushNewCommand(new ChangeProject);
	CommandList::Get().InitAllCommands();

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