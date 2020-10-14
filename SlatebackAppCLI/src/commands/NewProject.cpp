#include "sltcli_pch.h"

void NewProject::OnInit()
{
	SetInput("project");
	SetDesc("Creates a new project within Slateback.");
}

void NewProject::OnUpdate()
{
	LoadSltProjXML("Initialized new sltproj.xml for save data");

	std::string userinput;

	Controller::Get().PushBackNewProject();
	Project& activeProject = Controller::Get().GetActiveProject();

	UserPrompt(userinput, "Project Title");
	activeProject.SetTitle(userinput);

	UserPrompt(userinput, "Project Company");
	activeProject.SetCompany(userinput);

	UserPrompt(userinput, "Project Director");
	activeProject.SetDirector(userinput);

	UserPrompt(userinput, "Project DP");
	activeProject.SetDP(userinput);

	Serializer::Get().SerializeProjectVector(Controller::Get().GetProjectVector());
}
