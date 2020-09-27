#pragma once

#include <vector>

#include <cereal/cereal.hpp>

#include "Project.h"

// Container class for a vector of Project object pointers.
class ProjectVector
{
public:
	void PushNewProject(); // Pushes Project instance to m_Projects.
	Project& GetProject(size_t index); // Returns reference to Project instance in m_Projects.
	std::vector<Project>& GetVector(); // Returns reference to m_Projects.
	size_t GetVectorSize(); // Returns size of m_Projects.
	void SetActiveProjectIndex(unsigned int index); // Sets value for m_ActiveProjectIndex.
	unsigned int GetActiveProjectIndex(); // Returns m_ActiveProjectIndex.
	Project& GetActiveProject(); // Returns Project instance from m_Projects at current m_ActiveProjectIndex value.

	template<class Archive>
	void serialize(Archive& archive); // Serializes class using Cereal library

private:
	unsigned int m_ActiveProjectIndex = 0;
	std::vector<Project> m_Projects;
};

template<class Archive>
inline void ProjectVector::serialize(Archive& archive)
{
	archive(CEREAL_NVP(m_ActiveProjectIndex), CEREAL_NVP(m_Projects));
}
