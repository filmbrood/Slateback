#pragma once

#include "../data/ProjectVector.h"

// Class that acts as controller for data system by directly manipulating the ProjectVector member m_Projects, and accessing all dataset classes from there. Runs as Singleton, access with Controller::Get().
class Controller
{
public:
	ProjectVector& GetProjectVector(); // Returns reference to m_Projects.
	void SetProjectVector(ProjectVector& projects); // Sets m_Projects equal to a different ProjectVector instance.
	void PushBackNewProject(); // Pushes a Project instance to the m_Projects ProjectVector.
	Project& GetActiveProject(); // Returns Project instance from m_Projects at the current m_ActiveProjectIndex value.
	void ChangeActiveProject(unsigned int index); // Sets value for m_ActiveProjectIndex in m_Projects.

	void PushBackNewCamera(); // Pushes Camera instance to the m_Cameras vector within the Project instance in m_Projects at the current m_ActiveProjectIndex value.
	Camera& GetActiveCamera(); // Returns a reference to a Camera instance from vector within the Project in m_Projects at the current m_ActiveProjectIndex value.
	void ChangeActiveCamera(unsigned int index); // Sets a new value for m_ActiveCameraIndex in the active Project instance.

	void PushBackNewRoll(); // Pushes a Roll instance to the Roll vector within the active Camera instance.
	Roll& GetActiveRoll(); // Returns a pointer to the roll at the current m_ActiveRollIndex value.
	void ChangeActiveRoll(unsigned int index); // Sets value for m_ActiveRollIndex in the active Camera instance.

	void PushBackNewShot(); // Pushes a Shot instance to the Shot vector within the active Roll instance.
	Shot& GetActiveShot(); // Returns the shot at the current m_ActiveShotIndex value from the active Roll instance.
	void ChangeActiveShot(unsigned int index); // Sets value for m_ActiveShotIndex within the active Roll instance.

	std::string GetLogOutputString(); // Combines all project data into a string and returns it to be outputted as the final camera log.

public:
	static Controller& Get(); // Returns singleton instance (s_Instance) of Controller

private:
	// Internal functions used in GetLogOutputString().
	std::string GetProjectLogStringFromProjectVector(ProjectVector& projectVector);
	std::string GetCameraLogStringFromProject(Project& project);
	std::string GetRollLogStringFromCamera(Camera& camera);
	std::string GetShotLogStringFromRoll(Roll& roll);

private:
	ProjectVector m_Projects;

	Controller() {}
	static Controller s_Instance;
};