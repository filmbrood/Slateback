#pragma once
#include <string>

class Shot
{
public:
	void SetScene(std::string scene);
	void SetTake(std::string take);
	void SetFPS(std::string fps);
	void SetLens(std::string lens);
	void SetFStop(std::string fstop);
	void SetISO(std::string iso);
	void SetColorTemp(std::string colortemp);
	void SetFilter(std::string filter);

	std::string GetScene();
	std::string GetTake();
	std::string GetFPS();
	std::string GetLens();
	std::string GetFStop();
	std::string GetISO();
	std::string GetColorTemp();
	std::string GetFilter();

public:
	void ShotSetup();

	void PrintShotDetails();

private:
	std::string ShotSetupDetail(std::string detail);

	std::string m_Scene;
	std::string m_Take;
	std::string m_FPS;
	std::string m_Lens;
	std::string m_FStop;
	std::string m_ISO;
	std::string m_ColorTemp;
	std::string m_Filter;
	bool m_Print;
};