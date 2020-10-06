#include "sltcli_pch.h"

#include "CommandList.h"

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