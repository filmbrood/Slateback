#include <iostream>

#include "Shot.h"

void Shot::SetScene(std::string scene)
{
	m_Scene = scene;
}

void Shot::SetTake(std::string take)
{
	m_Take = take;
}

void Shot::SetFPS(std::string fps)
{
	m_FPS = fps;
}

void Shot::SetLens(std::string lens)
{
	m_Lens = lens;
}

void Shot::SetFStop(std::string fstop)
{
	m_FStop = fstop;
}

void Shot::SetISO(std::string iso)
{
	m_ISO = iso;
}

void Shot::SetColorTemp(std::string colortemp)
{
	m_ColorTemp = colortemp;
}

void Shot::SetFilter(std::string filter)
{
	m_Filter = filter;
}

void Shot::SetPrint(bool p)
{
	m_Print = p;
}

std::string Shot::GetScene()
{
	return m_Scene;
}

std::string Shot::GetTake()
{
	return m_Take;
}

std::string Shot::GetFPS()
{
	return m_Take;
}

std::string Shot::GetLens()
{
	return m_Lens;
}

std::string Shot::GetFStop()
{
	return m_FStop;
}

std::string Shot::GetISO()
{
	return m_ISO;
}

std::string Shot::GetColorTemp()
{
	return m_ColorTemp;
}

std::string Shot::GetFilter()
{
	return m_Filter;
}

bool Shot::CheckPrint()
{
	return m_Print;
}

void Shot::ShotSetup()
{
	SetScene(ShotSetupDetail("Scene"));
	SetTake(ShotSetupDetail("Take"));
	SetFPS(ShotSetupDetail("FPS"));
	SetLens(ShotSetupDetail("Lens"));
	SetFStop(ShotSetupDetail("f/Stop"));
	SetISO(ShotSetupDetail("ISO"));
	SetColorTemp(ShotSetupDetail("Color Temp"));
	SetFilter(ShotSetupDetail("Filter"));

	if (ShotSetupDetail("Set shot to Print? Y/N") == "Y")
		SetPrint(true);
	else
		SetPrint(false);
}

void Shot::PrintShotDetails()
{
	std::cout << "\n";
	std::cout << "Shot: " << GetScene() << "\n";
	std::cout << "Take: " << GetTake() << "\n";
	std::cout << "Lens: " << GetLens() << "\n";
	std::cout << "FPS: " << GetFPS() << "\n";
	std::cout << "f/Stop: " << GetFStop() << "\n";
	std::cout << "ISO: " << GetISO() << "\n";
	std::cout << "Color Temp: " << GetColorTemp() << "\n";
	std::cout << "Filter: " << GetFilter() << "\n";
	if (CheckPrint())
		std::cout << "Print: Yes\n";
	else
		std::cout << "Print: No\n";
}

std::string Shot::ShotSetupDetail(std::string detail)
{
	std::string userinput;

	std::cout << "Input Project " << detail << " > ";
	getline(std::cin, userinput);

	return userinput;
}
