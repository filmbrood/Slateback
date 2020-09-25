#include <iostream>
#include <filesystem>
#include <sstream>

#include <cereal/cereal.hpp>
#include <cereal/archives/binary.hpp>
#include <cereal/types/string.hpp>
#include <cereal/types/vector.hpp>

#include "slateback.h"
#include "CommandList.h"

CommandList::~CommandList()
{
	for (unsigned int i = 0; i < m_Commands.size(); i++)
		delete m_Commands[i];
}

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
	std::string userinput;

	Controller::Get().PushBackNewProject();
	std::cout << "New project created." << std::endl;

	// User input for project detail member variables
	std::cout << "Project Title > ";
	getline(std::cin, userinput);
	Controller::Get().GetActiveProject()->SetTitle(userinput);

	// Use project title to create new directory
	std::string& projectTitle = Controller::Get().GetActiveProject()->GetTitle();

	std::cout << "Project Company > ";
	getline(std::cin, userinput);
	Controller::Get().GetActiveProject()->SetCompany(userinput);

	std::cout << "Project Director > ";
	getline(std::cin, userinput);
	Controller::Get().GetActiveProject()->SetDirector(userinput);

	std::cout << "Project DP > ";
	getline(std::cin, userinput);
	Controller::Get().GetActiveProject()->SetDP(userinput);

	std::stringstream serialOutput;
	{
		cereal::BinaryOutputArchive archive(serialOutput);

		ProjectVector projects = Controller::Get().GetProjectVector();
		archive(projects);
	}

	std::cout << std::endl;
	std::cout << "Project details saved." << std::endl;
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