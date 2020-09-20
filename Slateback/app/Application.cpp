#include <iostream>
#include <string>

#include "../src/ProjectVector.h"
#include "Commands.h"

#define PROGRAMTITLE "Slateback Camera Logger"
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
		// Takes in user command, displays active project, camera, roll, and shot
		std::cout << "\n";
		if (projects.GetVectorSize() != 0)
		{

			Project* activeProject = projects.GetProject(Commands::Get().GetActiveProjectIndex());

			std::cout << "Active Project: " << activeProject->GetTitle() << "\n";

			if (activeProject->GetCameraCount() != 0)
			{
				Camera* activeCamera = activeProject->GetCamera(Commands::Get().GetActiveCameraIndex());
				std::cout << "Active Camera: " << activeCamera->GetID() << " (" << activeCamera->GetModel() << " )\n";

				if (activeCamera->GetRollCount() != 0)
				{
					Roll* activeRoll = activeCamera->GetRoll(Commands::Get().GetActiveRollIndex());
					std::cout << "Active Roll: " << activeRoll->GetID() << "\n";
				}
			}

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
		else if (userinput == "change camera")
		{
			Commands::Get().ChangeCamera(projects, userinput);
		}
		else if (userinput == "new roll")
		{
			Commands::Get().NewRoll(projects, userinput);
		}
		else if (userinput == "new shot")
		{
			Commands::Get().NewShot(projects, userinput);
		}
		else if (userinput == "view shot")
		{
			Commands::Get().ViewShot(projects, userinput);
		}
		else
			std::cout << "Unknown command\n";
	}
}