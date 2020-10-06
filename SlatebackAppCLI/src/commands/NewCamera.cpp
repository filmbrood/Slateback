#include "sltcli_pch.h"

#include "SlatebackAppCLI/src/CommandList.h"

void NewCamera::OnInit()
{
	SetInput("camera");
	SetDesc("Creates a new camera within the active project.");
}

void NewCamera::OnUpdate()
{

	ProjectVector pv;
	if (std::filesystem::exists("sltproj.xml"))
	{
		Serializer::Get().DeserializeProjectVector(pv, "sltproj.xml");
		Controller::Get().SetProjectVector(pv);
	}
	else
	{
		std::cout << "Must create project first" << std::endl;
		return;
	}

	Controller::Get().PushBackNewCamera();
	Project& project = Controller::Get().GetActiveProject();
	Camera& camera = Controller::Get().GetActiveCamera();
	std::cout << "New camera created for " << project.GetTitle() << std::endl;

	std::string userinput;
	std::cout << "Camera Model > ";
	getline(std::cin, userinput);
	camera.SetModel(userinput);

	std::cout << "Camera ID (A, B, C) > ";
	getline(std::cin, userinput);
	camera.SetID(userinput);

	std::cout << "Camera Sensor Size > ";
	getline(std::cin, userinput);
	camera.SetFilmBack(userinput);

	std::cout << "Camera Codec > ";
	getline(std::cin, userinput);
	camera.SetCodec(userinput);

	std::cout << "Camera Lens Set > ";
	getline(std::cin, userinput);
	camera.SetLensSet(userinput);

	std::cout << "Camera Operator > ";
	getline(std::cin, userinput);
	camera.SetCameraOperator(userinput);

	std::cout << "Camera 1st AC > ";
	getline(std::cin, userinput);
	camera.SetFirstAssistantCamera(userinput);

	std::cout << "Camera 2nd AC > ";
	getline(std::cin, userinput);
	camera.SetSecondAssistantCamera(userinput);

	Serializer::Get().SerializeProjectVector(Controller::Get().GetProjectVector());
}