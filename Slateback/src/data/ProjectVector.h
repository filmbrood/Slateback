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
	void PushNewProject();
	Project& GetProject(size_t index);

	std::vector<Project>& GetVector();
	size_t GetVectorSize();

	void SetActiveProjectIndex(unsigned int index);
	unsigned int GetActiveProjectIndex();

	// Serializes m_Projects using Cereal library
	template<class Archive>
	void serialize(Archive& archive);

private:
	unsigned int m_ActiveProjectIndex = 0;

	std::vector<Project> m_Projects;
};

template<class Archive>
inline void ProjectVector::serialize(Archive& archive)
{
	archive(CEREAL_NVP(m_Projects), CEREAL_NVP(m_ActiveProjectIndex));
}
