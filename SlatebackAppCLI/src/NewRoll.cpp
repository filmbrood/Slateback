#include "sltcli_pch.h"

#include "CommandList.h"

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