#include "sltcli_pch.h"

void EditProject::OnInit()
{
	SetInput("editproject");
	SetDesc("Edit the active project details.");
}

void EditProject::OnUpdate()
{
	LoadSltProjXML("No projects created");

	Project& activeProject = Controller::Get().GetActiveProject();

	std::cout << "Editing active project - Input new details now" << std::endl;

	std::string userinput;
	std::cout << "Current Title: " << activeProject.GetTitle() << std::endl;
	UserPrompt(userinput, "Change to");
	activeProject.SetTitle(userinput);

	std::cout << "Current Company: " << activeProject.GetCompany() << std::endl;
	UserPrompt(userinput, "Change to");
	activeProject.SetCompany(userinput);

	std::cout << "Current Director: " << activeProject.GetDirector() << std::endl;
	UserPrompt(userinput, "Change to");
	activeProject.SetDirector(userinput);

	std::cout << "Current DP: " << activeProject.GetDP() << std::endl;
	UserPrompt(userinput, "Change to");
	activeProject.SetDP(userinput);

	Serializer::Get().SerializeProjectVector(Controller::Get().GetProjectVector());
}
