#include "ProjectVector.h"

void ProjectVector::PushNewProject()
{
	if (m_Projects.size() > 0)
		m_ActiveProjectIndex++;

	Project project;
	m_Projects.push_back(project);
}

Project& ProjectVector::GetProject(size_t index)
{
	return m_Projects[index];
}

std::vector<Project>& ProjectVector::GetVector()
{
	return m_Projects;
}

size_t ProjectVector::GetVectorSize()
{
	return m_Projects.size();
}

void ProjectVector::SetActiveProjectIndex(unsigned int index)
{
	m_ActiveProjectIndex = index;
}

unsigned int ProjectVector::GetActiveProjectIndex()
{
	return m_ActiveProjectIndex;
}