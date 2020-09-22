#pragma once

#include <vector>

#include "Project.h"

// Container class for a vector of Project object pointers.
class ProjectVector
{
public:
	void PushBack(Project* p);

	Project* GetProject(unsigned int index);

	size_t GetVectorSize();

private:
	std::vector<Project*> m_Projects;
};