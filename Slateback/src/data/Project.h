#pragma once
#include <string>
#include <vector>
#include <cereal/cereal.hpp>

#include "Camera.h"

// Data class containing Project details, which also acts as a container for a vector of Camera object pointers.
class Project
{
public:
	Project() {}
	~Project() {}

public:
	void SetTitle(std::string title);
	void SetCompany(std::string company);
	void SetDirector(std::string director);
	void SetDP(std::string dop);
	
	std::string GetTitle();
	std::string GetCompany();
	std::string GetDirector();
	std::string GetDP();

public:
	// Pushes new camera object into m_Cameras vector
	void PushBackCamera();

	// Retrieves camera object at index
	Camera& GetCamera(unsigned int index);

	// Retrieves number of cameras in m_Cameras vector
	size_t GetCameraCount();

	// Serializes m_Cameras using Cereal library
	template<class Archive>
	void serialize(Archive& archive);

private:

	std::string m_Title;
	std::string m_Company;
	std::string m_Director;
	std::string m_DP;

	// Dynamic array with cameras per project
	std::vector<Camera> m_Cameras;
};

template<class Archive>
inline void Project::serialize(Archive& archive)
{
	archive(CEREAL_NVP(m_Cameras), CEREAL_NVP(m_Title), CEREAL_NVP(m_Company), CEREAL_NVP(m_Director), CEREAL_NVP(m_DP));
}
