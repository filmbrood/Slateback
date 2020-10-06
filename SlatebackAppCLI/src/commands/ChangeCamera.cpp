#include "sltcli_pch.h"

void ChangeCamera::OnInit()
{
	SetInput("changecamera");
	SetDesc("Changes the active camera.");
}

void ChangeCamera::OnUpdate()
{
	LoadSltProjXML("No projects or cameras created");

	Project& activeProject = Controller::Get().GetActiveProject();
	std::cout << "Change active camera to: " << std::endl;
	for (unsigned int i = 0; i < Controller::Get().GetActiveProject().GetCameraCount(); i++)
	{
		Camera& activeCamera = Controller::Get().GetActiveProject().GetCamera(i);
		std::cout << activeCamera.GetID() << " (" << activeCamera.GetModel() << ")" << std::endl;
	}

	std::string userinput;
	UserPrompt(userinput, "");

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