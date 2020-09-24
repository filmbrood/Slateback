#include <iostream>

#include "slateback.h"
#include "CommandList.h"

// CommandList functions. These handle updating the program and pushing new commands to the CommandList vector.
void CommandList::PushNewCommand(Command* command)
{
	m_Commands.push_back(command);
}

void CommandList::InitAllCommands()
{
	for (unsigned int i = 0; i < m_Commands.size(); i++)
		m_Commands[i]->OnInit();
}

void CommandList::OnUpdate(const char* argv)
{
	std::string userinput = argv;

	for (unsigned int i = 0; i < m_Commands.size(); i++)
	{
		if (m_Commands[i]->GetInput() == userinput)
			m_Commands[i]->OnUpdate();
	}
}

// Define command methods here.

// "project" argument functions
void NewProject::OnInit()
{
	SetInput("project");
}

void NewProject::OnUpdate()
{
	Controller::Get().PushBackNewProject();
	std::cout << "New project added." << std::endl;
}

// "camera" argument functions
void NewCamera::OnInit()
{
	SetInput("camera");
}

void NewCamera::OnUpdate()
{
	Controller::Get().PushBackNewCamera();
	std::cout << "New camera added." << std::endl;
}

// "roll" argument functions
void NewRoll::OnInit()
{
	SetInput("roll");
}

void NewRoll::OnUpdate()
{
	Controller::Get().PushBackNewRoll();
	std::cout << "New roll added." << std::endl;
}

// "shot" argument functions
void NewShot::OnInit()
{
	SetInput("shot");
}

void NewShot::OnUpdate()
{
	Controller::Get().PushBackNewShot();
	std::cout << "New shot added." << std::endl;
}