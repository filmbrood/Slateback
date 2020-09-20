#include <iostream>

#include "Camera.h"

void Camera::SetModel(std::string model)
{
	m_Model = model;
}

void Camera::SetFilmBack(std::string filmback)
{
	m_FilmBack = filmback;
}

void Camera::SetCodec(std::string codec)
{
	m_Codec = codec;
}

void Camera::SetID(std::string id)
{
	m_ID = id;
}

void Camera::SetLensSet(std::string lenses)
{
	m_LensSet = lenses;
}

std::string Camera::GetModel()
{
	return m_Model;
}

std::string Camera::GetFilmBack()
{
	return m_FilmBack;
}

std::string Camera::GetCodec()
{
	return m_Codec;
}

std::string Camera::GetID()
{
	return m_ID;
}

std::string Camera::GetLensSet()
{
	return m_LensSet;
}

void Camera::CameraSetup()
{
	SetModel(CameraSetupDetail("Model"));
	SetFilmBack(CameraSetupDetail("Film Back (Sensor Size)"));
	SetCodec(CameraSetupDetail("Codec or Film Stock"));
	SetID(CameraSetupDetail("ID (A, B, C)"));
	SetLensSet(CameraSetupDetail("Lens Set"));
	SetCameraOperator(CameraSetupDetail("Camera Operator"));
	SetFirstAssistantCamera(CameraSetupDetail("First Assistant Camera"));
	SetSecondAssistantCamera(CameraSetupDetail("Second Assistant Camera"));
}

void Camera::PrintCameraDetails()
{
	std::cout << "Model: " << GetModel() << std::endl;
	std::cout << "Film Back: " << GetFilmBack() << std::endl;
	std::cout << "Codec: " << GetCodec() << std::endl;
	std::cout << "ID: " << GetID() << std::endl;
	std::cout << "Lens Set: " << GetLensSet() << std::endl;
	std::cout << "Camera Operator: " << GetCameraOperator() << std::endl;
	std::cout << "1st AC: " << GetFirstAssistantCamera() << std::endl;
	std::cout << "2nd AC: " << GetSecondAssistantCamera() << std::endl;
}

void Camera::PushNewRoll(Roll* roll)
{
	m_RollCount++;
	m_Rolls.push_back(roll);
}

Roll* Camera::GetRoll(unsigned int index)
{
	return m_Rolls[index];
}

unsigned int Camera::GetRollCount()
{
	return m_RollCount;
}

std::string Camera::PrintCameraDetailsToString()
{
	std::string output;

	std::string details[7] =
	{
		"[Camera " + GetID() + "]\n",
		"Model: " + GetModel() + "\n",
		"Film Back: " + GetFilmBack() + "\n",
		"Lens Set: " + GetLensSet() + "\n",
		"Operator: " + GetCameraOperator() + "\n",
		"1st AC: " + GetFirstAssistantCamera() + "\n",
		"2nd AC: " + GetSecondAssistantCamera() + "\n"
	};

	for (unsigned int i = 0; i < 7; i++)
		output += details[i];

	return output;
}

std::string Camera::CameraSetupDetail(std::string detail)
{
	std::string userinput;

	std::cout << "Input " << detail << " > ";
	getline(std::cin, userinput);

	return userinput;
}

void Camera::SetCameraOperator(std::string camop)
{
	m_CameraOperator = camop;
}

void Camera::SetFirstAssistantCamera(std::string firstAC)
{
	m_FirstAssistantCamera = firstAC;
}

void Camera::SetSecondAssistantCamera(std::string secondAC)
{
	m_SecondAssistantCamera = secondAC;
}

std::string Camera::GetCameraOperator()
{
	return m_CameraOperator;
}

std::string Camera::GetFirstAssistantCamera()
{
	return m_FirstAssistantCamera;
}

std::string Camera::GetSecondAssistantCamera()
{
	return m_SecondAssistantCamera;
}