#include "Controller.h"

Controller Controller::s_Instance;

ProjectVector Controller::GetProjectVector()
{
	return m_Projects;
}

void Controller::SetProjectVector(ProjectVector projects)
{
	m_Projects = projects;
}

void Controller::PushBackNewProject()
{
	m_Projects.PushNewProject();
}

Project Controller::GetActiveProject()
{
	std::vector<Project>& buffer = m_Projects.GetVector();
	return buffer[m_ActiveProjectIndex];
}

void Controller::ChangeActiveProject(unsigned int index)
{
	m_ActiveProjectIndex = index;
}

void Controller::PushBackNewCamera()
{
	GetActiveProject().PushBackCamera();
}

Camera Controller::GetActiveCamera()
{
	return GetActiveProject().GetCamera(m_ActiveCameraIndex);
}

void Controller::ChangeActiveCamera(unsigned int index)
{
	m_ActiveCameraIndex = index;
}

void Controller::PushBackNewRoll()
{
	GetActiveProject().GetCamera(m_ActiveCameraIndex).PushNewRoll();
}

Roll Controller::GetActiveRoll()
{
	return GetActiveProject().GetCamera(m_ActiveCameraIndex).GetRoll(m_ActiveRollIndex);
}

void Controller::ChangeActiveRoll(unsigned int index)
{
	m_ActiveRollIndex = index;
}

void Controller::PushBackNewShot()
{
	GetActiveProject().GetCamera(m_ActiveCameraIndex).GetRoll(m_ActiveRollIndex).PushNewShot();
}

Shot Controller::GetActiveShot()
{
	return GetActiveProject().GetCamera(m_ActiveCameraIndex).GetRoll(m_ActiveRollIndex).GetShot(m_ActiveShotIndex);
}

void Controller::ChangeActiveShot(unsigned int index)
{
	m_ActiveShotIndex = index;
}

std::string Controller::GetLogOutputString()
{
	std::string output;

	output += GetProjectLogStringFromProjectVector(m_Projects);

	return output;
}

Controller& Controller::Get()
{
	return s_Instance;
}

std::string Controller::GetProjectLogStringFromProjectVector(ProjectVector& projectVector)
{
	std::string output;

	for (unsigned int i = 0; i < projectVector.GetVectorSize(); i++)
	{
		Project& activeProject = GetActiveProject();

		output += "Project Title: " + activeProject.GetTitle() + "\n";
		output += "Company: " + activeProject.GetCompany() + "\n";
		output += "Director: " + activeProject.GetDirector() + "\n";
		output += "DP: " + activeProject.GetDP() + "\n";
		output += "\n";

		output += GetCameraLogStringFromProject(activeProject);
	}

	return output;
}

std::string Controller::GetCameraLogStringFromProject(Project& project)
{
	std::string output;

	for (unsigned int i = 0; i < project.GetCameraCount(); i++)
	{
		Camera& activeCamera = project.GetCamera(i);

		output += "[CAMERA " + activeCamera.GetID() + "]\n";
		output += "Model: " + activeCamera.GetModel() + "\n";
		output += "Sensor Size: " + activeCamera.GetFilmBack() + "\n";
		output += "Codec: " + activeCamera.GetCodec() + "\n";
		output += "Lens Set: " + activeCamera.GetLensSet() + "\n";
		output += "Operator: " + activeCamera.GetCameraOperator() + "\n";
		output += "First Assistant: " + activeCamera.GetFirstAssistantCamera() + "\n";
		output += "Second Assistant: " + activeCamera.GetSecondAssistantCamera() + "\n";
		output += "\n";

		output += GetRollLogStringFromCamera(activeCamera);
	}

	return output;
}

std::string Controller::GetRollLogStringFromCamera(Camera& camera)
{
	std::string output;

	for (unsigned int i = 0; i < camera.GetRollCount(); i++)
	{
		Roll& activeRoll = camera.GetRoll(i);

		output += "[ROLL " + activeRoll.GetID() + "]\n";
		output += "Shot Count: " + std::to_string(activeRoll.GetShotCount()) + "\n";
		output += "\n";

		output += GetShotLogStringFromRoll(activeRoll);
	}

	return output;
}

std::string Controller::GetShotLogStringFromRoll(Roll& roll)
{
	std::string output;

	for (unsigned int i = 0; i < roll.GetShotCount(); i++)
	{
		Shot& activeShot = roll.GetShot(i);

		output += "[SHOT " + activeShot.GetScene() + "-" + activeShot.GetTake() + "]\n";
		output += "FPS: " + activeShot.GetFPS() + "\n";
		output += "Focal Length: " + activeShot.GetLens() + "\n";
		output += "f/Stop: " + activeShot.GetFStop() + "\n";
		output += "ISO: " + activeShot.GetISO() + "\n";
		output += "Color Temp: " + activeShot.GetColorTemp() + "\n";
		output += "Filter: " + activeShot.GetFilter() + "\n";
		output += "\n";
	}

	return output;
}
