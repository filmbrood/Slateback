#include "sltcli_pch.h"

void EditShot::OnInit()
{
	SetInput("editshot");
	SetDesc("Edit the last recorded shot's details.");
}

void EditShot::OnUpdate()
{
	LoadSltProjXML("No project created");

	Shot& activeShot = Controller::Get().GetActiveShot();

	std::cout << "Editing last recorded shot's details." << std::endl;

	std::string userinput;

	std::cout << "Current Scene: " << activeShot.GetScene() << std::endl;
	UserPrompt(userinput, "Change to");
	activeShot.SetScene(userinput);

	unsigned int userInputInt;
	std::cout << "Current Take: " << activeShot.GetTake() << std::endl;
	std::cout << "Change to > ";
	std::cin >> userInputInt;
	activeShot.SetTake(userInputInt);

	std::cout << "Current FPS: " << activeShot.GetFPS() << std::endl;
	UserPrompt(userinput, "Change to");
	activeShot.SetFPS(userinput);

	std::cout << "Current Focal Length: " << activeShot.GetLens() << std::endl;
	UserPrompt(userinput, "Change to");
	activeShot.SetLens(userinput);

	std::cout << "Current f/Stop: " << activeShot.GetFStop() << std::endl;
	UserPrompt(userinput, "Change to");
	activeShot.SetFStop(userinput);

	std::cout << "Current ISO: " << activeShot.GetISO() << std::endl;
	UserPrompt(userinput, "Change to");
	activeShot.SetISO(userinput);

	std::cout << "Current Color Temp: " << activeShot.GetColorTemp() << std::endl;
	UserPrompt(userinput, "Change to");
	activeShot.SetColorTemp(userinput);

	std::cout << "Current Filter: " << activeShot.GetFilter() << std::endl;
	UserPrompt(userinput, "Change to");
	activeShot.SetFilter(userinput);

	Serializer::Get().SerializeProjectVector(Controller::Get().GetProjectVector());

}