#include "sltcli_pch.h"

void Take::OnInit()
{
	SetInput("take");
	SetDesc("Creates new shot with identical details to previous, but increments the 'take' detail.");
}

void Take::OnUpdate()
{
	LoadSltProjXML("No projects created");

	Roll& activeRoll = Controller::Get().GetActiveRoll();
	activeRoll.PushNewShot();

	Shot& currentShot = Controller::Get().GetActiveShot();
	unsigned int index = activeRoll.GetActiveShotIndex();

	currentShot = activeRoll.GetShot(index - 1);
	currentShot.SetTake(currentShot.GetTake() + 1);

	std::cout << "Created new take of previous shot.\nEdit with 'slt editshot' if any details of the shot have changed from the previous take." << std::endl;
	Serializer::Get().SerializeProjectVector(Controller::Get().GetProjectVector());
}
