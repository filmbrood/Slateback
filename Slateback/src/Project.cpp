#include <iostream>
#include <string>

#include "Project.h"

void Project::SetTitle(std::string title)
{
	m_Title = title;
}

void Project::SetCompany(std::string company)
{
	m_Company = company;
}

void Project::SetDirector(std::string director)
{
	m_Director = director;
}

void Project::SetDP(std::string dop)
{
	m_DP = dop;
}

void Project::SetCameraOperator(std::string camop)
{
	m_CameraOperator = camop;
}

void Project::SetFirstAssistantCamera(std::string firstAC)
{
	m_FirstAssistantCamera = firstAC;
}

void Project::SetSecondAssistantCamera(std::string secondAC)
{
	m_SecondAssistantCamera = secondAC;
}

std::string Project::GetTitle()
{
	return m_Title;
}

std::string Project::GetCompany()
{
	return m_Company;
}

std::string Project::GetDirector()
{
	return m_Director;
}

std::string Project::GetDP()
{
	return m_DP;
}

std::string Project::GetCameraOperator()
{
	return m_CameraOperator;
}

std::string Project::GetFirstAssistantCamera()
{
	return m_FirstAssistantCamera;
}

std::string Project::GetSecondAssistantCamera()
{
	return m_SecondAssistantCamera;
}

void Project::ProjectSetup()
{
	SetTitle(ProjectSetupDetail("Title"));
	SetCompany(ProjectSetupDetail("Company"));
	SetDirector(ProjectSetupDetail("Director"));
	SetDP(ProjectSetupDetail("DP"));
	SetCameraOperator(ProjectSetupDetail("Camera Operator"));
	SetFirstAssistantCamera(ProjectSetupDetail("First Assistant Camera"));
	SetSecondAssistantCamera(ProjectSetupDetail("Second Assistant Camera"));
}

void Project::PrintProjectDetails()
{
	std::cout << "Title: " << GetTitle() << std::endl;
	std::cout << "Company: " << GetCompany() << std::endl;
	std::cout << "Director: " << GetDirector() << std::endl;
	std::cout << "DP: " << GetDP() << std::endl;
	std::cout << "Camera Operator: " << GetCameraOperator() << std::endl;
	std::cout << "1st AC: " << GetFirstAssistantCamera() << std::endl;
	std::cout << "2nd AC: " << GetSecondAssistantCamera() << std::endl;
}

void Project::PushBackCamera(Camera* c)
{
	m_Cameras.push_back(c);
	m_CameraCount++;
}

Camera* Project::GetCamera(unsigned int index)
{
	return m_Cameras[index];
}

unsigned int Project::GetCameraCount()
{
	return m_CameraCount;
}

std::string Project::ProjectSetupDetail(std::string detail)
{
	std::string userinput;

	std::cout << "Input Project " << detail << " > ";
	getline(std::cin, userinput);

	return userinput;
}
