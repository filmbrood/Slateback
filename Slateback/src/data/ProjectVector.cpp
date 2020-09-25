#include "ProjectVector.h"

void ProjectVector::PushBackProject()
{
	Project project;
	m_Projects.push_back(project);
}

Project ProjectVector::GetProject(size_t index)
{
	return m_Projects[index];
}

std::vector<Project> ProjectVector::GetVector()
{
	return m_Projects;
}

size_t ProjectVector::GetVectorSize()
{
	return m_Projects.size();
}