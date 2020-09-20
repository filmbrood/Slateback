#pragma once

#include "../src/ProjectVector.h"

// Singleton container for application console commands.
class Commands
{
public:

	void NewProject(ProjectVector& projects, std::string userinput);
	void ChangeProject(ProjectVector& projects, std::string userinput);

	void NewCamera(ProjectVector& projects, std::string userinput);


public:
	static Commands& Get();

	unsigned int GetActiveProjectIndex();
	unsigned int GetActiveCameraIndex();

private:
	Commands() {}

	static Commands s_Instance;

	unsigned int m_ProjectCount = 0;
	unsigned int m_ActiveProjectIndex = 0;
	unsigned int m_ActiveCameraIndex = 0;
};