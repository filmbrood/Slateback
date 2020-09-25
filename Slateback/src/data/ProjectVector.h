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

	// Serializes m_Projects using Cereal library
	template<class Archive>
	void serialize(Archive& archive)
	{
		archive(m_Projects);
	}

private:
	std::vector<Project*> m_Projects;
};