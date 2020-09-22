#pragma once

#include "../data/ProjectVector.h"

// Class that acts as controller for data system by directly manipulating the ProjectVector member m_Projects, and accessing all dataset classes from there.
// Essentially the class that manipulates a state machine, the state machine being the project data itself.

// !!! Runs as a singleton. Access with Controller::Get().

class Controller
{
public:
	// Pushes back new project to the m_Projects ProjectVector.
	void PushBackNewProject();

	// Returns project pointer from m_Projects at the current m_ActiveProjectIndex value.
	Project* GetActiveProject();

	// Sets a new value for m_ActiveProjectIndex.
	void ChangeActiveProject(unsigned int index);

	// Pushes a new camera to the camera pointer vector within the Project in m_Projects at the current m_ActiveProjectIndex value.
	void PushBackNewCamera();

	// Returns camera pointer from vector within the Project in m_Projects at the current m_ActiveProjectIndex value.
	Camera* GetActiveCamera();

	// Sets a new value for m_ActiveCameraIndex.
	void ChangeActiveCamera(unsigned int index);

	// Pushes a new roll to the roll pointer vector within the active camera.
	void PushBackNewRoll();

	// Returns a pointer to the roll at the current m_ActiveRollIndex value.
	Roll* GetActiveRoll();

	// Sets a new value for m_ActiveRollIndex.
	void ChangeActiveRoll(unsigned int index);

	// Pushes a new shot to the shot pointer vector within the active roll.
	void PushBackNewShot();

	// Returns a pointer to the shot at the current m_ActiveShotIndex value.
	Shot* GetActiveShot();

	// Sets a new value for m_ActiveShotIndex.
	void ChangeActiveShot(unsigned int index);

	// Combines all project data into a string and returns it to be outputted as the final camera log.
	std::string GetLogOutputString();

public:
	// Returns singleton instance of Controller
	static Controller& Get();

private:
	// Internal functions used in GetLogOutputString().
	std::string GetProjectLogStringFromProjectVector(ProjectVector* projectVector);
	std::string GetCameraLogStringFromProject(Project* project);
	std::string GetRollLogStringFromCamera(Camera* camera);
	std::string GetShotLogStringFromRoll(Roll* roll);

private:
	Controller() {}
	static Controller s_Instance;

	ProjectVector m_Projects;

	unsigned int m_ActiveProjectIndex = 0;
	unsigned int m_ActiveCameraIndex = 0;
	unsigned int m_ActiveRollIndex = 0;
	unsigned int m_ActiveShotIndex = 0;
};