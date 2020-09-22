#include "slateback.h"

#include <string>
#include <iostream>

int main()
{
	auto slateback = Controller::Get();
	slateback.PushBackNewProject();
	slateback.GetActiveProject()->SetDirector("Wes Anderson\n");
	std::string teststring = slateback.GetActiveProject()->GetDirector();

	slateback.PushBackNewCamera();
	slateback.GetActiveCamera()->SetModel("Arri Alexa Mini\n");
	teststring += slateback.GetActiveCamera()->GetModel();

	slateback.PushBackNewCamera();
	slateback.GetActiveCamera()->SetModel("Blackmagic Pocket\n");
	teststring += slateback.GetActiveCamera()->GetModel();

	slateback.PushBackNewRoll();
	slateback.GetActiveRoll()->SetID("A001\n");
	teststring += slateback.GetActiveRoll()->GetID();

	slateback.PushBackNewShot();
	slateback.GetActiveShot()->SetScene("1A\n");
	teststring += slateback.GetActiveShot()->GetScene();

	std::cout << teststring;
	std::cin.get();
}