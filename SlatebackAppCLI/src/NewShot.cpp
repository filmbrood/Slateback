#include "sltcli_pch.h"

#include "CommandList.h"

void NewShot::OnInit()
{
	SetInput("shot");
	SetDesc("Creates a new shot within the active roll.");
}

void NewShot::OnUpdate()
{
	ProjectVector pv;
	if (std::filesystem::exists("projects.xml"))
	{
		Serializer::Get().DeserializeProjectVector(pv, "projects.xml");
		Controller::Get().SetProjectVector(pv);
	}
	else
	{
		std::cout << "Must create project, camera, and roll first" << std::endl;
	}

	if (!Controller::Get().GetActiveProject().GetCameraCount())
	{
		std::cout << "Must create camera and roll first" << std::endl;
		return;
	}

	if (!Controller::Get().GetActiveCamera().GetRollCount())
	{
		std::cout << "Must create roll first" << std::endl;
		return;
	}

	Controller::Get().PushBackNewShot();
	Shot& activeShot = Controller::Get().GetActiveShot();
	std::cout << "New shot created for Roll " << Controller::Get().GetActiveRoll().GetID() << std::endl;

	std::string userinput;
	std::cout << "Scene > ";
	getline(std::cin, userinput);
	activeShot.SetScene(userinput);

	std::cout << "Take > ";
	getline(std::cin, userinput);
	activeShot.SetTake(userinput);

	std::cout << "FPS > ";
	getline(std::cin, userinput);
	activeShot.SetFPS(userinput);

	std::cout << "Focal Length > ";
	getline(std::cin, userinput);
	activeShot.SetLens(userinput);

	std::cout << "f/Stop > ";
	getline(std::cin, userinput);
	activeShot.SetFStop(userinput);

	std::cout << "ISO > ";
	getline(std::cin, userinput);
	activeShot.SetISO(userinput);

	std::cout << "Color Temp > ";
	getline(std::cin, userinput);
	activeShot.SetColorTemp(userinput);

	std::cout << "Filter > ";
	getline(std::cin, userinput);
	activeShot.SetFilter(userinput);

	Serializer::Get().SerializeProjectVector(Controller::Get().GetProjectVector());
}