#include "slatebackpch.h"

#include "Project.h"

// Project methods. See Project.h for more info.

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

void Project::PushBackCamera()
{
	if (m_Cameras.size() > 0)
		m_ActiveCameraIndex++;

	Camera camera;
	m_Cameras.push_back(camera);
}

Camera& Project::GetCamera(unsigned int index)
{
	return m_Cameras[index];
}

size_t Project::GetCameraCount()
{
	return m_Cameras.size();
}

void Project::SetActiveCameraIndex(unsigned int index)
{
	m_ActiveCameraIndex = index;
}

unsigned int Project::GetActiveCameraIndex()
{
	return 0;
}

Camera& Project::GetActiveCamera()
{
	return m_Cameras[m_ActiveCameraIndex];
}
