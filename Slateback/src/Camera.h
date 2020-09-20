#pragma once
#include <string>
#include <vector>

#include "Roll.h"

class Camera
{
public:
	void SetModel(std::string model);
	void SetFilmBack(std::string filmback);
	void SetCodec(std::string setcodec);
	void SetID(std::string id);
	void SetLensSet(std::string lenses);
	void SetCameraOperator(std::string camop);
	void SetFirstAssistantCamera(std::string firstAC);
	void SetSecondAssistantCamera(std::string secondAC);

	std::string GetModel();
	std::string GetFilmBack();
	std::string GetCodec();
	std::string GetID();
	std::string GetLensSet();
	std::string GetCameraOperator();
	std::string GetFirstAssistantCamera();
	std::string GetSecondAssistantCamera();

	void CameraSetup();
	void PrintCameraDetails();

public:
	// For accessing Roll vector and data surrounding it
	void PushNewRoll(Roll* roll);
	Roll* GetRoll(unsigned int index);

	unsigned int GetRollCount();

private:
	std::string m_Model;
	std::string m_FilmBack;
	std::string m_Codec;
	std::string m_ID;
	std::string m_LensSet;
	std::string m_CameraOperator;
	std::string m_FirstAssistantCamera;
	std::string m_SecondAssistantCamera;

	std::string CameraSetupDetail(std::string detail);

	std::vector<Roll*> m_Rolls;

	unsigned int m_RollCount = 0;
};