#include <iostream>
#include <filesystem>
#include <fstream>

#include "slateback.h"
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

/* 

Define individual Command children methods below.

*/

// "project" argument methods
void NewProject::OnInit()
{
	SetInput("project");
	SetDesc("Creates a new project within Slateback.");
}

void NewProject::OnUpdate()
{
	ProjectVector pv;
	if (std::filesystem::exists("projects.xml"))
	{
		Serializer::Get().DeserializeProjectVector(pv, "projects.xml");
		Controller::Get().SetProjectVector(pv);
	}

	Controller::Get().PushBackNewProject();
	Project& activeProject = Controller::Get().GetActiveProject();

	std::string userinput;
	std::cout << "Project Title > ";
	getline(std::cin, userinput);
	activeProject.SetTitle(userinput);
	std::cout << "New project created - " << activeProject.GetTitle() << std::endl;

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
	SetDesc("Creates a new camera within the active project.");
}

void NewCamera::OnUpdate()
{

	ProjectVector pv;
	if (std::filesystem::exists("projects.xml"))
	{
		Serializer::Get().DeserializeProjectVector(pv, "projects.xml");
		Controller::Get().SetProjectVector(pv);
	}
	else
	{
		std::cout << "Must create project first" << std::endl;
		return;
	}

	Controller::Get().PushBackNewCamera();
	Project& project = Controller::Get().GetActiveProject();
	Camera& camera = Controller::Get().GetActiveCamera();
	std::cout << "New camera created for " << project.GetTitle() << std::endl;

	std::string userinput;
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
	SetDesc("Creates a new roll within the active camera.");
}

void NewRoll::OnUpdate()
{
	ProjectVector pv;
	if (std::filesystem::exists("projects.xml"))
	{
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
	SetDesc("Creates a new shot within the active roll.");
}

void NewShot::OnUpdate()
{
	ProjectVector pv;
	if (std::filesystem::exists("projects.xml"))
	{
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

	Controller::Get().PushBackNewShot();
	Shot& activeShot = Controller::Get().GetActiveShot();
	std::cout << "New shot created for Roll " << Controller::Get().GetActiveRoll().GetID() << std::endl;

	std::string userinput;
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
	activeShot.SetISO(userinput);

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
	SetDesc("Displays active project, camera, and roll.");
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
	SetDesc("Outputs project camera report to CameraReport.txt.");
}

void Print::OnUpdate()
{
	ProjectVector pv;
	if (std::filesystem::exists("projects.xml"))
	{
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
	SetDesc("Displays list of functions.");
}

void Help::OnUpdate()
{
	auto commands = CommandList::Get();
	for (unsigned int i = 0; i < commands.GetCommandCount(); i++)
		std::cout << commands.GetCommand(i)->GetInput() << " - " << commands.GetCommand(i)->GetDesc() << std::endl;
}

// "changeproject" argument methods
void ChangeProject::OnInit()
{
	SetInput("changeproject");
	SetDesc("Change the active project.");
}

void ChangeProject::OnUpdate()
{
	ProjectVector pv;
	if (std::filesystem::exists("projects.xml"))
	{
		Serializer::Get().DeserializeProjectVector(pv, "projects.xml");
		Controller::Get().SetProjectVector(pv);
	}
	else
	{
		std::cout << "No projects created" << std::endl;
		return;
	}
	
	std::string userinput;
	std::cout << "Change active project to: " << std::endl;
	for (unsigned int i = 0; i < Controller::Get().GetProjectVector().GetVectorSize(); i++)
		std::cout << i << " - " << Controller::Get().GetProjectVector().GetProject(i).GetTitle() << std::endl;

	std::cout << "> ";
	getline(std::cin, userinput);

	for (unsigned int i = 0; i < Controller::Get().GetProjectVector().GetVectorSize(); i++)
	{
		if (userinput == std::to_string(i))
		{
			Controller::Get().ChangeActiveProject(i);
			std::cout << "Active project changed to " << Controller::Get().GetProjectVector().GetProject(i).GetTitle() << std::endl;
			Serializer::Get().SerializeProjectVector(Controller::Get().GetProjectVector());
			break;
		}
	}
}

// "changecamera" argument methods
void ChangeCamera::OnInit()
{
	SetInput("changecamera");
	SetDesc("Changes the active camera.");
}

void ChangeCamera::OnUpdate()
{
	ProjectVector pv;
	if (std::filesystem::exists("projects.xml"))
	{
		Serializer::Get().DeserializeProjectVector(pv, "projects.xml");
		Controller::Get().SetProjectVector(pv);
	}
	else
	{
		std::cout << "No projects or cameras created" << std::endl;
		return;
	}

	std::string userinput;
	Project& activeProject = Controller::Get().GetActiveProject();
	std::cout << "Change active camera to: " << std::endl;
	for (unsigned int i = 0; i < Controller::Get().GetActiveProject().GetCameraCount(); i++)
	{
		Camera& activeCamera = Controller::Get().GetActiveProject().GetCamera(i);
		std::cout << activeCamera.GetID() << " (" << activeCamera.GetModel() << ")" << std::endl;
	}

	std::cout << "> ";
	getline(std::cin, userinput);

	for (unsigned int i = 0; i < activeProject.GetCameraCount(); i++)
	{
		Camera& activeCamera = activeProject.GetCamera(i);
		if (userinput == activeCamera.GetID())
		{
			Controller::Get().ChangeActiveCamera(i);
			std::cout << "Active camera changed to " << activeCamera.GetID() << " (" << activeCamera.GetModel() << ")" << std::endl;
			Serializer::Get().SerializeProjectVector(Controller::Get().GetProjectVector());
			break;
		}
	}
}
