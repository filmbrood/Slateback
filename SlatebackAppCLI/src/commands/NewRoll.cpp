#include "sltcli_pch.h"

void NewRoll::OnInit()
{
	SetInput("roll");
	SetDesc("Creates a new roll within the active camera.");
}

void NewRoll::OnUpdate()
{
	LoadSltProjXML("Must create project and camera first");

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