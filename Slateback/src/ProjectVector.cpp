#include "ProjectVector.h"

void ProjectVector::PushBack(Project* p)
{
	m_Projects.push_back(p);
}

Project* ProjectVector::GetProject(unsigned int index)
{
	return m_Projects[index];
}

size_t ProjectVector::GetVectorSize()
{
	return m_Projects.size();
}
