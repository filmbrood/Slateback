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
	if (std::filesystem::exists("projects.xml"))
	{
		ProjectVector pv;
		Serializer::Get().DeserializeProjectVector(pv, "projects.xml");
		Controller::Get().SetProjectVector(pv);
	}

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

	if (std::filesystem::exists("projects.xml"))
	{
		ProjectVector pv;
		Serializer::Get().DeserializeProjectVector(pv, "projects.xml");
		Controller::Get().SetProjectVector(pv);
	}
	else
	{
		std::cout << "Must create project first" << std::endl;
		return;
	}

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

	std::cout << "Camera 2nd AC > ";
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
	if (std::filesystem::exists("projects.xml"))
	{
		ProjectVector pv;
		Serializer::Get().DeserializeProjectVector(pv, "projects.xml");
		Controller::Get().SetProjectVector(pv);
	}
	else
	{
		std::cout << "Must create project and camera first" << std::endl;
	}

	if (!Controller::Get().GetActiveProject().GetCameraCount())
	{
		std::cout << "Must create camera first" << std::endl;
		return;
	}

	Camera& activeCamera = Controller::Get().GetActiveCamera();
	activeCamera.PushNewRoll();

	Roll& activeRoll = Controller::Get().GetActiveRoll();
	std::string newRollID = activeCamera.GetID() + std::to_string(activeCamera.GetRollCount());
	activeRoll.SetID(newRollID);

	std::cout << "New roll created for camera " << activeCamera.GetID() << " - " << activeRoll.GetID() << std::endl;

	Serializer::Get().SerializeProjectVector(Controller::Get().GetProjectVector());
}

// "shot" argument methods
void NewShot::OnInit()
{
	SetInput("shot");
}

void NewShot::OnUpdate()
{
	if (std::filesystem::exists("projects.xml"))
	{
		ProjectVector pv;
		Serializer::Get().DeserializeProjectVector(pv, "projects.xml");
		Controller::Get().SetProjectVector(pv);
	}
	else
	{
		std::cout << "Must create project, camera, and roll first" << std::endl;
	}

	if (!Controller::Get().GetActiveProject().GetCameraCount())
	{
		std::cout << "Must create camera and roll first" << std::endl;
		return;
	}

	if (!Controller::Get().GetActiveCamera().GetRollCount())
	{
		std::cout << "Must create roll first" << std::endl;
		return;
	}

	std::string userinput;

	Controller::Get().PushBackNewShot();
	Shot& activeShot = Controller::Get().GetActiveShot();

	std::cout << "New shot created for Roll " << Controller::Get().GetActiveRoll().GetID() << std::endl;

	std::cout << "Scene > ";
	getline(std::cin, userinput);
	activeShot.SetScene(userinput);

	std::cout << "Take > ";
	getline(std::cin, userinput);
	activeShot.SetTake(userinput);

	std::cout << "FPS > ";
	getline(std::cin, userinput);
	activeShot.SetFPS(userinput);

	std::cout << "Focal Length > ";
	getline(std::cin, userinput);
	activeShot.SetLens(userinput);

	std::cout << "f/Stop > ";
	getline(std::cin, userinput);
	activeShot.SetFStop(userinput);

	std::cout << "ISO > ";
	getline(std::cin, userinput);
	activeShot.SetFStop(userinput);

	std::cout << "Color Temp > ";
	getline(std::cin, userinput);
	activeShot.SetColorTemp(userinput);

	std::cout << "Filter > ";
	getline(std::cin, userinput);
	activeShot.SetFilter(userinput);

	Serializer::Get().SerializeProjectVector(Controller::Get().GetProjectVector());
}

// "status" argument methods
void Status::OnInit()
{
	SetInput("status");
}

void Status::OnUpdate()
{
	ProjectVector pv;

	if (std::filesystem::exists("projects.xml"))
	{
		Serializer::Get().DeserializeProjectVector(pv, "projects.xml");
		Controller::Get().SetProjectVector(pv);
	}
	else
	{
		std::cout << "No projects created." << std::endl;
		return;
	}

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
				Roll& activeRoll = Controller::Get().GetActiveRoll();
				std::cout << "Active Roll: " << activeRoll.GetID() << std::endl;
				std::cout << "Shot count: " << activeRoll.GetShotCount() << std::endl;
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

// "print" argument methods
void Print::OnInit()
{
	SetInput("print");
}

void Print::OnUpdate()
{
	if (std::filesystem::exists("projects.xml"))
	{
		ProjectVector pv;
		Serializer::Get().DeserializeProjectVector(pv, "projects.xml");
		Controller::Get().SetProjectVector(pv);
	}
	else
	{
		std::cout << "No projects created - nothing to print." << std::endl;
		return;
	}

	std::ofstream logfile;
	logfile.open("CameraReport.txt");
	logfile << Controller::Get().GetLogOutputString() << std::endl;
	logfile.close();
}

void Help::OnInit()
{
	SetInput("help");
}

void Help::OnUpdate()
{
	std::cout << "Use 'slt project' to create a new project, then 'slt camera' to create a camera, 'slt roll' to create a roll, and finally 'slt shot' to create a new shot" << std::endl;
}
