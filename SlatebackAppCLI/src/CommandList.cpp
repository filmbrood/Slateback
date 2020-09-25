#include <iostream>
#include <filesystem>
#include <fstream>

#include <cereal/cereal.hpp>
#include <cereal/archives/json.hpp>
#include <cereal/types/string.hpp>
#include <cereal/types/vector.hpp>
#include <cereal/types/memory.hpp>

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

	std::unique_ptr<Project> activeProject = std::make_unique<Project>(Controller::Get().GetActiveProject());

	// For debug - displays size of ProjectVector in Controller class
	std::cout << Controller::Get().GetProjectVector().GetVectorSize() << std::endl;

	// User inputs project title before creation
	std::cout << "Project Title > ";
	getline(std::cin, userinput);
	activeProject->SetTitle(userinput);
	std::cout << "New project created - " << activeProject->GetTitle() << std::endl;

	// User inputs rest of details
	std::cout << "Project Company > ";
	getline(std::cin, userinput);
	activeProject->SetCompany(userinput);

	std::cout << "Project Director > ";
	getline(std::cin, userinput);
	activeProject->SetDirector(userinput);

	std::cout << "Project DP > ";
	getline(std::cin, userinput);
	activeProject->SetDP(userinput);

	std::ofstream serialOutput;
	serialOutput.open(activeProject->GetTitle() + ".json");
	{
		cereal::JSONOutputArchive archive(serialOutput);
		archive(CEREAL_NVP(activeProject));
	}
	serialOutput.close();

	std::cout << std::endl;
	std::cout << "Project details saved to projects.json" << std::endl;
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