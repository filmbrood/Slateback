#include <iostream>
#include <string>

#include "Commands.h"

Commands Commands::s_Instance;

Commands& Commands::Get()
{
	return s_Instance;
}

unsigned int Commands::GetActiveProjectIndex()
{
	return m_ActiveProjectIndex;
}

unsigned int Commands::GetActiveCameraIndex()
{
	return m_ActiveCameraIndex;
}

unsigned int Commands::GetActiveRollIndex()
{
	return m_ActiveRollIndex;
}

void Commands::NewProject(ProjectVector& projects, std::string userinput)
{
	m_ProjectCount++;
	std::cout << "New Project created. Input project details now.\n\n";
	projects.PushBack(new Project);
	projects.GetProject(m_ProjectCount - 1)->ProjectSetup();
	std::cout << "\n";
	projects.GetProject(m_ProjectCount - 1)->PrintProjectDetails();
	std::cout << "Project setup complete.\n";

	m_ActiveProjectIndex = m_ProjectCount - 1;
}

void Commands::ChangeProject(ProjectVector& projects, std::string userinput)
{
	std::cout << "Change active project to:\n\n";

	for (size_t i = 0; i < projects.GetVectorSize(); i++)
		std::cout << projects.GetProject(i)->GetTitle() << "\n";

	getline(std::cin, userinput);

	for (size_t i = 0; i < projects.GetVectorSize(); i++)
		if (userinput == projects.GetProject(i)->GetTitle())
			m_ActiveProjectIndex = i;
}

void Commands::NewCamera(ProjectVector& projects, std::string userinput)
{
	if (projects.GetVectorSize() < 1)
	{
		std::cout << "You must create a project before creating any cameras.\n";
		return;
	}
	
	Project* activeProject = projects.GetProject(m_ActiveProjectIndex);

	activeProject->PushBackCamera(new Camera);

	unsigned int cameraCount = activeProject->GetCameraCount();

	m_ActiveCameraIndex = cameraCount - 1;

	std::cout << "New camera for " << activeProject->GetTitle() << "\n";

	activeProject->GetCamera(m_ActiveCameraIndex)->CameraSetup();
	activeProject->GetCamera(m_ActiveCameraIndex)->PrintCameraDetails();

	std::cout << "New camera created successfully.\n";
}

void Commands::ChangeCamera(ProjectVector& projects, std::string userinput)
{
	std::cout << "Change active camera to: " << std::endl;

	Project* activeProject = projects.GetProject(m_ActiveProjectIndex);

	for (size_t i = 0; i < activeProject->GetCameraCount(); i++)
		std::cout << activeProject->GetCamera(i)->GetID() << " (" << activeProject->GetCamera(i)->GetModel() << ")\n";

	getline(std::cin, userinput);

	for (size_t i = 0; i < activeProject->GetCameraCount(); i++)
		if (userinput == activeProject->GetCamera(i)->GetID())
			m_ActiveCameraIndex = i;
}

void Commands::NewRoll(ProjectVector& projects, std::string userinput)
{
	if (projects.GetVectorSize() < 1)
	{
		std::cout << "You must create a project and a camera before you create any rolls.\n";
		return;
	}

	Project* activeProject = projects.GetProject(m_ActiveProjectIndex);

	if (activeProject->GetCameraCount() < 1)
	{
		std::cout << "You must create a camera before you create any rolls.\n";
		return;
	}

	Camera* activeCamera = activeProject->GetCamera(m_ActiveCameraIndex);

	std::cout << "New roll created for Camera " << activeCamera->GetID() << " (" << activeCamera->GetModel() << "\n";

	std::string newRollID = activeCamera->GetID() + "0" + std::to_string(activeCamera->GetRollCount() + 1);
	
	activeCamera->PushNewRoll(new Roll);
	activeCamera->GetRoll(m_ActiveRollIndex)->SetID(newRollID);
	
	std::cout << "Roll number: " << activeCamera->GetRoll(m_ActiveRollIndex)->GetID() << "\n";
}

void Commands::ChangeRoll(ProjectVector& projects, std::string userinput)
{
	Project* activeProject = projects.GetProject(m_ActiveProjectIndex);
	Camera* activeCamera = activeProject->GetCamera(m_ActiveCameraIndex);
	
	std::cout << "Change active roll to: " << std::endl;

	for (size_t i = 0; i < activeCamera->GetRollCount(); i++)
		std::cout << activeCamera->GetRoll(i)->GetID() << "\n";

	getline(std::cin, userinput);

	for (size_t i = 0; i < activeCamera->GetRollCount(); i++)
		if (userinput == activeCamera->GetRoll(i)->GetID())
			m_ActiveRollIndex = i;
}

void Commands::NewShot(ProjectVector& projects, std::string userinput)
{
	Project* activeProject = projects.GetProject(m_ActiveProjectIndex);
	Camera* activeCamera = activeProject->GetCamera(m_ActiveCameraIndex);
	Roll* activeRoll = activeCamera->GetRoll(m_ActiveRollIndex);

	activeRoll->PushNewShot(new Shot);

	std::cout << "New shot added to roll " << activeRoll->GetID();
}

void Commands::ViewShot(ProjectVector& projects, std::string userinput)
{
	std::cout << "Enter shot to view details of, formatted as 'Scene-Take' e.g. 1A-1 > ";
	getline(std::cin, userinput);

	Roll* activeRoll = projects.GetProject(m_ActiveProjectIndex)->GetCamera(m_ActiveCameraIndex)->GetRoll(m_ActiveRollIndex);

	for (unsigned int i = 0; i < activeRoll->GetShotCount(); i++)
		if (userinput == activeRoll->GetShot(i)->GetScene() + "-" + activeRoll->GetShot(i)->GetTake())
			activeRoll->GetShot(i)->PrintShotDetails();
}
