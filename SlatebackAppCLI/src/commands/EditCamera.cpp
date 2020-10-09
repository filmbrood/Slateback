#include "sltcli_pch.h"

void EditCamera::OnInit()
{
	SetInput("editcamera");
	SetDesc("Edit the active camera details.");
}

void EditCamera::OnUpdate()
{
	LoadSltProjXML("No projects created");

	Camera& activeCamera = Controller::Get().GetActiveCamera();

	std::cout << "Editing active camera - Input new details now" << std::endl;

	std::string userinput;
	std::cout << "Current Model: " << activeCamera.GetModel() << std::endl;
	UserPrompt(userinput, "Change to");
	activeCamera.SetModel(userinput);

	std::cout << "Current ID: " << activeCamera.GetID() << std::endl;
	UserPrompt(userinput, "Change to");
	activeCamera.SetID(userinput);

	std::cout << "Current Sensor Size: " << activeCamera.GetFilmBack() << std::endl;
	UserPrompt(userinput, "Change to");
	activeCamera.SetFilmBack(userinput);

	std::cout << "Current Codec: " << activeCamera.GetCodec() << std::endl;
	UserPrompt(userinput, "Change to");
	activeCamera.SetCodec(userinput);

	std::cout << "Current Lens Set: " << activeCamera.GetLensSet() << std::endl;
	UserPrompt(userinput, "Change to");
	activeCamera.SetLensSet(userinput);

	std::cout << "Current Operator: " << activeCamera.GetCameraOperator() << std::endl;
	UserPrompt(userinput, "Change to");
	activeCamera.SetCameraOperator(userinput);

	std::cout << "Current 1st AC: " << activeCamera.GetFirstAssistantCamera() << std::endl;
	UserPrompt(userinput, "Change to");
	activeCamera.SetFirstAssistantCamera(userinput);

	std::cout << "Current 2nd AC: " << activeCamera.GetSecondAssistantCamera() << std::endl;
	UserPrompt(userinput, "Change to");
	activeCamera.SetSecondAssistantCamera(userinput);

	Serializer::Get().SerializeProjectVector(Controller::Get().GetProjectVector());
}