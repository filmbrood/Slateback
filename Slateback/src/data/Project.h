#pragma once
#include <string>
#include <vector>

#include "Camera.h"

// Data class containing Project details, which also acts as a container for a vector of Camera object pointers.
class Project
{
public:
	// Deconstructor for deleting m_Cameras pointer vector
	~Project();

	void SetTitle(std::string title);
	void SetCompany(std::string company);
	void SetDirector(std::string director);
	void SetDP(std::string dop);
	
	std::string GetTitle();
	std::string GetCompany();
	std::string GetDirector();
	std::string GetDP();

public:
	// Runs command line setup for applying values to all member variables
	void ProjectSetup();

	// Pushes new pointer camera object into m_Cameras vector
	void PushBackCamera(Camera* c);

	// Retrieves pointer to camera object at index
	Camera* GetCamera(unsigned int index);

	// Retrieves number of cameras in m_Cameras vector
	size_t GetCameraCount();

private:
	std::string m_Title;
	std::string m_Company;
	std::string m_Director;
	std::string m_DP;

	// Dynamic array with cameras per project
	std::vector<Camera*> m_Cameras;
};