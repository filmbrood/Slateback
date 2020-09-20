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
	Project* activeProject = projects.GetProject(m_ActiveProjectIndex);

	activeProject->PushBackCamera(new Camera);

	unsigned int cameraCount = activeProject->GetCameraCount();

	m_ActiveCameraIndex = cameraCount - 1;

	std::cout << "New camera for " << activeProject->GetTitle() << "\n";

	activeProject->GetCamera(m_ActiveCameraIndex)->CameraSetup();
	activeProject->GetCamera(m_ActiveCameraIndex)->PrintCameraDetails();

	std::cout << "New camera created successfully.\n";
}