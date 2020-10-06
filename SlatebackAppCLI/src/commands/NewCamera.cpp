#include "sltcli_pch.h"

void NewCamera::OnInit()
{
	SetInput("camera");
	SetDesc("Creates a new camera within the active project.");
}

void NewCamera::OnUpdate()
{
	LoadSltProjXML("Must create project first");

	Controller::Get().PushBackNewCamera();
	Project& project = Controller::Get().GetActiveProject();
	Camera& camera = Controller::Get().GetActiveCamera();
	std::cout << "New camera created for " << project.GetTitle() << std::endl;

	std::string userinput;

	UserPrompt(userinput, "Camera Model");
	camera.SetModel(userinput);

	UserPrompt(userinput, "Camera ID (A, B, C)");
	camera.SetID(userinput);

	UserPrompt(userinput, "Camera Sensor Size");
	camera.SetFilmBack(userinput);

	UserPrompt(userinput, "Camera Codec");
	camera.SetCodec(userinput);

	UserPrompt(userinput, "Camera Lens Set");
	camera.SetLensSet(userinput);

	UserPrompt(userinput, "Camera Operator");
	camera.SetCameraOperator(userinput);

	UserPrompt(userinput, "Camera 1st AC");
	camera.SetFirstAssistantCamera(userinput);

	UserPrompt(userinput, "Camera 2nd AC");
	camera.SetSecondAssistantCamera(userinput);

	Serializer::Get().SerializeProjectVector(Controller::Get().GetProjectVector());
}