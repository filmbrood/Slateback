#include "sltcli_pch.h"

#include "Helpers.h"

// Helper functions. See Helpers.h for more info.

void LoadSltProjXML(const std::string& errormessage)
{
	ProjectVector pv;
	if (std::filesystem::exists("sltproj.xml"))
	{
		Serializer::Get().DeserializeProjectVector(pv, "sltproj.xml");
		Controller::Get().SetProjectVector(pv);
	}
	else
	{
		std::cout << errormessage << std::endl;
		return;
	}
}

void UserPrompt(std::string& userinput, const std::string& message)
{
	std::cout << message << " > ";
	getline(std::cin, userinput);
}

void UserPrompt(unsigned int& userInputInt, const std::string& message)
{
	std::cout << message << " > ";
	std::string buffer;
	getline(std::cin, buffer);

	userInputInt = std::atoi(buffer.c_str());
}
