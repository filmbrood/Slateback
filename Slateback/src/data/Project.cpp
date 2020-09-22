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

void Project::PushBackCamera(Camera* c)
{
	m_Cameras.push_back(c);
}

Camera* Project::GetCamera(unsigned int index)
{
	return m_Cameras[index];
}

unsigned int Project::GetCameraCount()
{
	return m_Cameras.size();
}