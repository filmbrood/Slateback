#include "sltcli_pch.h"

void Print::OnInit()
{
	SetInput("print");
	SetDesc("Outputs project camera report to CameraReport.txt.");
}

void Print::OnUpdate()
{
	LoadSltProjXML("No projects created - nothing to print");

	std::ofstream logfile;
	logfile.open("CameraReport.txt");
	logfile << Controller::Get().GetLogOutputString() << std::endl;
	logfile.close();
}