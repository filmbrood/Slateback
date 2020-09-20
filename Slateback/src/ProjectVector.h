#pragma once

#include <vector>

#include "Project.h"

class ProjectVector
{
public:
	void PushBack(Project* p);

	Project* GetProject(unsigned int index);

	size_t GetVectorSize();

private:
	std::vector<Project*> m_Projects;
};