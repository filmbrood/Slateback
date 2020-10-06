#include "sltcli_pch.h"

#include "CommandList.h"

void NewProject::OnInit()
{
	SetInput("project");
	SetDesc("Creates a new project within Slateback.");
}

void NewProject::OnUpdate()
{
	ProjectVector pv;
	if (std::filesystem::exists("projects.xml"))
	{
		Serializer::Get().DeserializeProjectVector(pv, "projects.xml");
		Controller::Get().SetProjectVector(pv);
	}

	Controller::Get().PushBackNewProject();
	Project& activeProject = Controller::Get().GetActiveProject();

	std::string userinput;
	std::cout << "Project Title > ";
	getline(std::cin, userinput);
	activeProject.SetTitle(userinput);
	std::cout << "New project created - " << activeProject.GetTitle() << std::endl;

	std::cout << "Project Company > ";
	getline(std::cin, userinput);
	activeProject.SetCompany(userinput);

	std::cout << "Project Director > ";
	getline(std::cin, userinput);
	activeProject.SetDirector(userinput);

	std::cout << "Project DP > ";
	getline(std::cin, userinput);
	activeProject.SetDP(userinput);

	Serializer::Get().SerializeProjectVector(Controller::Get().GetProjectVector());
}