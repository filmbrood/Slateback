#include "slateback.h"

#include <string>
#include <iostream>

int main()
{
	std::string teststring;

	auto slateback = Controller::Get();
	slateback.PushBackNewProject();
	slateback.GetActiveProject()->SetDirector("Wes Anderson");

	slateback.PushBackNewCamera();
	slateback.GetActiveCamera()->SetModel("Arri Alexa Mini");

	slateback.PushBackNewCamera();
	slateback.GetActiveCamera()->SetModel("Blackmagic Pocket");

	slateback.PushBackNewRoll();
	slateback.GetActiveRoll()->SetID("A001");

	slateback.PushBackNewShot();
	slateback.GetActiveShot()->SetScene("1A");

	teststring += slateback.GetLogOutputString();

	std::cout << teststring;
	std::cin.get();
}