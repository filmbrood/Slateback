#pragma once

#include <vector>

#include <cereal/cereal.hpp>

#include "Project.h"

// Container class for a vector of Project object pointers.
class ProjectVector
{
public:
	ProjectVector() {}
	~ProjectVector() {}

public:
	void PushBackProject();
	Project GetProject(size_t index);

	std::vector<Project> GetVector();
	size_t GetVectorSize();

	// Serializes m_Projects using Cereal library
	template<class Archive>
	void serialize(Archive& archive);

private:

	std::vector<Project> m_Projects;
};

template<class Archive>
inline void ProjectVector::serialize(Archive& archive)
{
	archive(m_Projects);
}
