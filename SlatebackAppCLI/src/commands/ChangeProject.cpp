#include "sltcli_pch.h"

void ChangeProject::OnInit()
{
	SetInput("changeproject");
	SetDesc("Change the active project.");
}

void ChangeProject::OnUpdate()
{
	LoadSltProjXML("No projects created");

	std::cout << "Change active project to: " << std::endl;
	for (unsigned int i = 0; i < Controller::Get().GetProjectVector().GetVectorSize(); i++)
		std::cout << i << " - " << Controller::Get().GetProjectVector().GetProject(i).GetTitle() << std::endl;

	std::string userinput;
	UserPrompt(userinput, "");

	for (unsigned int i = 0; i < Controller::Get().GetProjectVector().GetVectorSize(); i++)
	{
		if (userinput == std::to_string(i))
		{
			Controller::Get().ChangeActiveProject(i);
			std::cout << "Active project changed to " << Controller::Get().GetProjectVector().GetProject(i).GetTitle() << std::endl;
			Serializer::Get().SerializeProjectVector(Controller::Get().GetProjectVector());
			break;
		}
	}
}
