#include <iostream>
#include <string>

#include "../src/ProjectVector.h"
#include "Commands.h"

#define PROGRAMTITLE "2nd AC Logging Toolkit"
#define VERSIONINFO "Pre-Alpha"
#define AUTHOR "Dawn Moore"
#define COPYRIGHT "2020"

int main()
{
	// Print program info to console
	std::cout << PROGRAMTITLE << "\n";
	std::cout << VERSIONINFO << "\n";
	std::cout << "Coded by " << AUTHOR << " (c)" << COPYRIGHT << "\n";

	// System variables
	bool running = true;
	std::string userinput;

	// Vector for projects
	ProjectVector projects;

	while (running)
	{
		// Takes in user command, displays active project and active camera
		std::cout << "\n";
		if (projects.GetVectorSize() != 0)
		{
			Project* activeProject = projects.GetProject(Commands::Get().GetActiveProjectIndex());
			unsigned int activeCamera = Commands::Get().GetActiveCameraIndex();

			std::cout << "Active Project: " << activeProject->GetTitle() << "\n";

			if (activeProject->GetCameraCount() != 0)
				std::cout << "Active Camera: " << activeProject->GetCamera(activeCamera)->GetID() << " (" << activeProject->GetCamera(activeCamera)->GetModel() << " )\n";
		}
		std::cout << "Input Command > ";

		getline(std::cin, userinput);

		// Branching options for different commands
		if (userinput == "new project")
		{
			Commands::Get().NewProject(projects, userinput);
		}
		else if (userinput == "change project")
		{
			Commands::Get().ChangeProject(projects, userinput);
		}
		else if (userinput == "new camera")
		{
			Commands::Get().NewCamera(projects, userinput);
		}
		else
			std::cout << "Unknown command\n";
	}
}