#include "slatebackpch.h"

#include "Controller.h"

Controller Controller::s_Instance; // Initialize singleton instance of Controller

// Controller methods. See Controller.h for more info.
ProjectVector& Controller::GetProjectVector()
{
	return m_Projects;
}

void Controller::SetProjectVector(ProjectVector& projects)
{
	m_Projects = projects;
}

void Controller::PushBackNewProject()
{
	m_Projects.PushNewProject();
}

Project& Controller::GetActiveProject()
{
	return m_Projects.GetActiveProject();
}

void Controller::ChangeActiveProject(unsigned int index)
{
	m_Projects.SetActiveProjectIndex(index);
}

void Controller::PushBackNewCamera()
{
	GetActiveProject().PushBackCamera();
}

Camera& Controller::GetActiveCamera()
{
	return GetActiveProject().GetActiveCamera();
}

void Controller::ChangeActiveCamera(unsigned int index)
{
	GetActiveProject().SetActiveCameraIndex(index);
}

void Controller::PushBackNewRoll()
{
	GetActiveCamera().PushNewRoll();
}

Roll& Controller::GetActiveRoll()
{
	unsigned int index = GetActiveCamera().GetActiveRollIndex();
	return GetActiveCamera().GetRoll(index);
}

void Controller::ChangeActiveRoll(unsigned int index)
{
	GetActiveCamera().SetActiveRollIndex(index);
}

void Controller::PushBackNewShot()
{
	GetActiveRoll().PushNewShot();
}

Shot& Controller::GetActiveShot()
{
	unsigned int index = GetActiveRoll().GetActiveShotIndex();
	return GetActiveRoll().GetShot(index);
}

void Controller::ChangeActiveShot(unsigned int index)
{
	GetActiveRoll().SetActiveShotIndex(index);
}

std::string Controller::GetLogOutputString()
{
	std::string output;

	output += "Camera Report Generated with Slateback\n\n";
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
		Project& activeProject = projectVector.GetProject(i);

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

		output += "  [CAMERA " + activeCamera.GetID() + "]\n";
		output += "  Model: " + activeCamera.GetModel() + "\n";
		output += "  Sensor Size: " + activeCamera.GetFilmBack() + "\n";
		output += "  Codec: " + activeCamera.GetCodec() + "\n";
		output += "  Lens Set: " + activeCamera.GetLensSet() + "\n";
		output += "  Operator: " + activeCamera.GetCameraOperator() + "\n";
		output += "  First Assistant: " + activeCamera.GetFirstAssistantCamera() + "\n";
		output += "  Second Assistant: " + activeCamera.GetSecondAssistantCamera() + "\n";
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

		output += "    [ROLL " + activeRoll.GetID() + "]\n";
		output += "    Shot Count: " + std::to_string(activeRoll.GetShotCount()) + "\n";
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

		output += "      [SHOT " + activeShot.GetScene() + "-" + activeShot.GetTake() + "]\n";
		output += "      FPS: " + activeShot.GetFPS() + "\n";
		output += "      Focal Length: " + activeShot.GetLens() + "\n";
		output += "      f/Stop: " + activeShot.GetFStop() + "\n";
		output += "      ISO: " + activeShot.GetISO() + "\n";
		output += "      Color Temp: " + activeShot.GetColorTemp() + "\n";
		output += "      Filter: " + activeShot.GetFilter() + "\n";
		output += "\n";
	}

	return output;
}
