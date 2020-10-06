#include "sltcli_pch.h"

#include "SlatebackAppCLI/src/CommandList.h"

void Print::OnInit()
{
	SetInput("print");
	SetDesc("Outputs project camera report to CameraReport.txt.");
}

void Print::OnUpdate()
{
	ProjectVector pv;
	if (std::filesystem::exists("sltproj.xml"))
	{
		Serializer::Get().DeserializeProjectVector(pv, "projects.xml");
		Controller::Get().SetProjectVector(pv);
	}
	else
	{
		std::cout << "No projects created - nothing to print." << std::endl;
		return;
	}
	std::ofstream logfile;
	logfile.open("CameraReport.txt");
	logfile << Controller::Get().GetLogOutputString() << std::endl;
	logfile.close();
}