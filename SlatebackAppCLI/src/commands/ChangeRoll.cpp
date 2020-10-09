#include "sltcli_pch.h"

void ChangeRoll::OnInit()
{
	SetInput("changeroll");
	SetDesc("Change the active camera roll. (NOT YET IMPLEMENTED)");
}

void ChangeRoll::OnUpdate()
{
	LoadSltProjXML("No projects created");

	Camera& activeCamera = Controller::Get().GetActiveCamera();

	std::cout << "Change active roll to: " << std::endl;
	for (unsigned int i = 0; i < activeCamera.GetRollCount(); i++)
		std::cout << i << " - " << activeCamera.GetRoll(i).GetID() << std::endl;

	std::string userinput;
	UserPrompt(userinput, "");

	for (unsigned int i = 0; i < activeCamera.GetRollCount(); i++)
	{
		if (userinput == std::to_string(i))
		{
			Controller::Get().ChangeActiveRoll(i);
			std::cout << "Active roll changed to " << Controller::Get().GetActiveRoll().GetID() << std::endl;
			Serializer::Get().SerializeProjectVector(Controller::Get().GetProjectVector());
			break;
		}
	}
}