#pragma once

#include <vector>

#include <cereal/cereal.hpp>
#include <cereal/types/vector.hpp>
#include <cereal/types/string.hpp>

#include "Project.h"

// Container class for a vector of Project object pointers.
class ProjectVector
{
public:
	void PushBackProject();

	std::vector<Project> GetVector();
	size_t GetVectorSize();

	// Serializes m_Projects using Cereal library
	template<class Archive>
	void serialize(Archive& archive)
	{
		archive(m_Projects);
	}

private:

	std::vector<Project> m_Projects;
};