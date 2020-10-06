#include "sltcli_pch.h"

#include "SlatebackAppCLI/src/CommandList.h"

void ChangeCamera::OnInit()
{
	SetInput("changecamera");
	SetDesc("Changes the active camera.");
}

void ChangeCamera::OnUpdate()
{
	ProjectVector pv;
	if (std::filesystem::exists("sltproj.xml"))
	{
		Serializer::Get().DeserializeProjectVector(pv, "sltproj.xml");
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