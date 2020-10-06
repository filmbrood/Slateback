#pragma once

#include "Camera.h"

// Data class containing Project details, which also acts as a container for a vector of Camera object pointers.
class Project
{
public:
	// Methods for setting member variables. Names are self-explanatory.
	void SetTitle(std::string title);
	void SetCompany(std::string company);
	void SetDirector(std::string director);
	void SetDP(std::string dop);
	
	// Methods for returning member variables.
	std::string GetTitle();
	std::string GetCompany();
	std::string GetDirector();
	std::string GetDP();

public:
	void PushBackCamera(); // Pushes a Camera instance into m_Cameras vector
	Camera& GetCamera(unsigned int index); // Returns reference to camera instance from m_Cameras at specified index
	size_t GetCameraCount(); // Returns size of m_Cameras
	void SetActiveCameraIndex(unsigned int index); // Sets value for m_ActiveCameraIndex
	unsigned int GetActiveCameraIndex(); // Returns m_ActiveCameraIndex
	Camera& GetActiveCamera(); // Returns reference to Camera instance from m_Cameras at current m_ActiveCameraIndex value

	template<class Archive>
	void serialize(Archive& archive); // Serializes class using Cereal library

private:
	std::string m_Title;
	std::string m_Company;
	std::string m_Director;
	std::string m_DP;
	unsigned int m_ActiveCameraIndex = 0;
	std::vector<Camera> m_Cameras;
};

template<class Archive>
inline void Project::serialize(Archive& archive)
{
	archive(CEREAL_NVP(m_ActiveCameraIndex), CEREAL_NVP(m_Cameras), CEREAL_NVP(m_Title), CEREAL_NVP(m_Company), CEREAL_NVP(m_Director), CEREAL_NVP(m_DP));
}
