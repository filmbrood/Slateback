#include "sltcli_pch.h"

void NewShot::OnInit()
{
	SetInput("shot");
	SetDesc("Creates a new shot within the active roll.");
}

void NewShot::OnUpdate()
{
	LoadSltProjXML("Must create project, camera, and roll first");

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
	unsigned int userInputInt = 0;

	UserPrompt(userinput, "Scene");
	activeShot.SetScene(userinput);

	UserPrompt(userInputInt, "Take");
	activeShot.SetTake(userInputInt);

	UserPrompt(userinput, "FPS");
	activeShot.SetFPS(userinput);

	UserPrompt(userinput, "Focal Length");
	activeShot.SetLens(userinput);

	UserPrompt(userinput, "f/Stop");
	activeShot.SetFStop(userinput);

	UserPrompt(userinput, "ISO");
	activeShot.SetISO(userinput);

	UserPrompt(userinput, "Color Temp");
	activeShot.SetColorTemp(userinput);

	UserPrompt(userinput, "Filter");
	activeShot.SetFilter(userinput);

	Serializer::Get().SerializeProjectVector(Controller::Get().GetProjectVector());
}