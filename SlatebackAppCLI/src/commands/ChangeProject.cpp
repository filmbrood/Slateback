#include "sltcli_pch.h"

#include "SlatebackAppCLI/src/CommandList.h"

void ChangeProject::OnInit()
{
	SetInput("changeproject");
	SetDesc("Change the active project.");
}

void ChangeProject::OnUpdate()
{
	ProjectVector pv;
	if (std::filesystem::exists("sltproj.xml"))
	{
		Serializer::Get().DeserializeProjectVector(pv, "sltproj.xml");
		Controller::Get().SetProjectVector(pv);
	}
	else
	{
		std::cout << "No projects created" << std::endl;
		return;
	}

	std::string userinput;
	std::cout << "Change active project to: " << std::endl;
	for (unsigned int i = 0; i < Controller::Get().GetProjectVector().GetVectorSize(); i++)
		std::cout << i << " - " << Controller::Get().GetProjectVector().GetProject(i).GetTitle() << std::endl;

	std::cout << "> ";
	getline(std::cin, userinput);

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