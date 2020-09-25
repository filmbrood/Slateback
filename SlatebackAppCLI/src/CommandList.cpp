#include <iostream>
#include <filesystem>
#include <fstream>

#include "slateback.h"
#include "CommandList.h"

CommandList::~CommandList()
{
	for (unsigned int i = 0; i < m_Commands.size(); i++)
		delete m_Commands[i];
}

// CommandList methods. These handle updating the program and pushing new commands to the CommandList vector.
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

// "project" argument methods
void NewProject::OnInit()
{
	SetInput("project");
}

void NewProject::OnUpdate()
{
	std::string userinput;

	Controller::Get().PushBackNewProject();

	Project& activeProject = Controller::Get().GetActiveProject();

	// User inputs project title before creation
	std::cout << "Project Title > ";
	getline(std::cin, userinput);
	activeProject.SetTitle(userinput);
	std::cout << "New project created - " << activeProject.GetTitle() << std::endl;

	// User inputs rest of details
	std::cout << "Project Company > ";
	getline(std::cin, userinput);
	activeProject.SetCompany(userinput);

	std::cout << "Project Director > ";
	getline(std::cin, userinput);
	activeProject.SetDirector(userinput);

	std::cout << "Project DP > ";
	getline(std::cin, userinput);
	activeProject.SetDP(userinput);

	Serializer::Get().SerializeProjectVector(Controller::Get().GetProjectVector());
}

// "camera" argument methods
void NewCamera::OnInit()
{
	SetInput("camera");
}

void NewCamera::OnUpdate()
{
	std::string userinput;

	ProjectVector pv;
	Serializer::Get().DeserializeProjectVector(pv, "projects.xml");
	Controller::Get().SetProjectVector(pv);

	Project& project = Controller::Get().GetActiveProject();
	project.PushBackCamera();

	Camera& camera = Controller::Get().GetActiveCamera();
	std::cout << "New camera created for " << project.GetTitle() << std::endl;

	std::cout << "Camera Model > ";
	getline(std::cin, userinput);
	camera.SetModel(userinput);

	std::cout << "Camera ID (A, B, C) > ";
	getline(std::cin, userinput);
	camera.SetID(userinput);

	std::cout << "Camera Sensor Size > ";
	getline(std::cin, userinput);
	camera.SetFilmBack(userinput);
	
	std::cout << "Camera Codec > ";
	getline(std::cin, userinput);
	camera.SetCodec(userinput);

	std::cout << "Camera Lens Set > ";
	getline(std::cin, userinput);
	camera.SetLensSet(userinput);

	std::cout << "Camera Operator > ";
	getline(std::cin, userinput);
	camera.SetCameraOperator(userinput);

	std::cout << "Camera 1st AC > ";
	getline(std::cin, userinput);
	camera.SetFirstAssistantCamera(userinput);

	std::cout << "Camera 2nd AC >";
	getline(std::cin, userinput);
	camera.SetSecondAssistantCamera(userinput);
	
	Serializer::Get().SerializeProjectVector(Controller::Get().GetProjectVector());
}

// "roll" argument methods
void NewRoll::OnInit()
{
	SetInput("roll");
}

void NewRoll::OnUpdate()
{
	std::cout << "Command not implemented" << std::endl;
}

// "shot" argument methods
void NewShot::OnInit()
{
	SetInput("shot");
}

void NewShot::OnUpdate()
{
	std::cout << "Command not implemented" << std::endl;
}

// "status" argument methods
void Status::OnInit()
{
	SetInput("status");
}

void Status::OnUpdate()
{
	ProjectVector pv;
	Serializer::Get().DeserializeProjectVector(pv, "projects.xml");
	Controller::Get().SetProjectVector(pv);

	if (pv.GetVectorSize())
	{
		Project& activeProject = Controller::Get().GetActiveProject();
		std::cout << "Current Project: " << activeProject.GetTitle() << std::endl;

		if (activeProject.GetCameraCount())
		{
			Camera& activeCamera = Controller::Get().GetActiveCamera();
			std::cout << "Active Camera: " << activeCamera.GetID() << " (" << activeCamera.GetModel() << ")" << std::endl;

			if (activeCamera.GetRollCount())
			{
				//Roll& activeRoll = Controller::Get().GetActiveRoll();
				//std::cout << "Active Roll: " << activeRoll.GetID() << std::endl;
			}
			else
				std::cout << "No rolls created." << std::endl;
		}
		else
			std::cout << "No cameras created." << std::endl;
	}
	else
		std::cout << "No projects created." << std::endl;

}