#include "ProjectVector.h"

void ProjectVector::PushBackProject()
{
	Project project;
	m_Projects.push_back(project);
}

std::vector<Project> ProjectVector::GetVector()
{
	return m_Projects;
}

size_t ProjectVector::GetVectorSize()
{
	return m_Projects.size();
}