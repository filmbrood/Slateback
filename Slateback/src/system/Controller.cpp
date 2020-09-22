#include "Controller.h"

Controller Controller::s_Instance;

void Controller::PushBackNewProject()
{
	if (m_Projects.GetVectorSize() != 0)
		m_ActiveProjectIndex++;

	m_Projects.PushBack(new Project);
}

Project* Controller::GetActiveProject()
{
	return m_Projects.GetProject(m_ActiveProjectIndex);
}

void Controller::ChangeActiveProject(unsigned int index)
{
	m_ActiveProjectIndex = index;
}

void Controller::PushBackNewCamera()
{
	if (m_Projects.GetProject(m_ActiveProjectIndex)->GetCameraCount() != 0)
		m_ActiveCameraIndex++;

	m_Projects.GetProject(m_ActiveProjectIndex)->PushBackCamera(new Camera);
}

Camera* Controller::GetActiveCamera()
{
	return m_Projects.GetProject(m_ActiveProjectIndex)->GetCamera(m_ActiveCameraIndex);
}

void Controller::ChangeActiveCamera(unsigned int index)
{
	m_ActiveCameraIndex = index;
}

void Controller::PushBackNewRoll()
{
	if (m_Projects.GetProject(m_ActiveProjectIndex)->GetCamera(m_ActiveCameraIndex)->GetRollCount() != 0)
		m_ActiveRollIndex++;

	m_Projects.GetProject(m_ActiveProjectIndex)->GetCamera(m_ActiveCameraIndex)->PushNewRoll(new Roll);
}

Roll* Controller::GetActiveRoll()
{
	return m_Projects.GetProject(m_ActiveProjectIndex)->GetCamera(m_ActiveCameraIndex)->GetRoll(m_ActiveRollIndex);
}

void Controller::ChangeActiveRoll(unsigned int index)
{
	m_ActiveRollIndex = index;
}

void Controller::PushBackNewShot()
{
	if (m_Projects.GetProject(m_ActiveProjectIndex)->GetCamera(m_ActiveCameraIndex)->GetRoll(m_ActiveRollIndex)->GetShotCount() != 0)
		m_ActiveShotIndex++;

	m_Projects.GetProject(m_ActiveProjectIndex)->GetCamera(m_ActiveCameraIndex)->GetRoll(m_ActiveRollIndex)->PushNewShot(new Shot);
}

Shot* Controller::GetActiveShot()
{
	return m_Projects.GetProject(m_ActiveProjectIndex)->GetCamera(m_ActiveCameraIndex)->GetRoll(m_ActiveRollIndex)->GetShot(m_ActiveShotIndex);
}

void Controller::ChangeActiveShot(unsigned int index)
{
	m_ActiveShotIndex = index;
}

std::string Controller::GetLogOutputString()
{
	std::string output;

	output += GetProjectLogStringFromProjectVector(&m_Projects);

	return output;
}

Controller& Controller::Get()
{
	return s_Instance;
}

std::string Controller::GetProjectLogStringFromProjectVector(ProjectVector* projectVector)
{
	std::string output;

	for (unsigned int i = 0; i < projectVector->GetVectorSize(); i++)
	{
		Project* activeProject = projectVector->GetProject(i);

		output += "Project Title: " + activeProject->GetTitle() + "\n";
		output += "Company: " + activeProject->GetCompany() + "\n";
		output += "Director: " + activeProject->GetDirector() + "\n";
		output += "DP: " + activeProject->GetDP() + "\n";
		output += "\n";

		output += GetCameraLogStringFromProject(activeProject);
	}

	return output;
}

std::string Controller::GetCameraLogStringFromProject(Project* project)
{
	std::string output;

	for (unsigned int i = 0; i < project->GetCameraCount(); i++)
	{
		Camera* activeCamera = project->GetCamera(i);

		output += "[CAMERA " + activeCamera->GetID() + "]\n";
		output += "Model: " + activeCamera->GetModel() + "\n";
		output += "Sensor Size: " + activeCamera->GetFilmBack() + "\n";
		output += "Codec: " + activeCamera->GetCodec() + "\n";
		output += "Lens Set: " + activeCamera->GetLensSet() + "\n";
		output += "Operator: " + activeCamera->GetCameraOperator() + "\n";
		output += "First Assistant: " + activeCamera->GetFirstAssistantCamera() + "\n";
		output += "Second Assistant: " + activeCamera->GetSecondAssistantCamera() + "\n";
		output += "\n";

		output += GetRollLogStringFromCamera(activeCamera);
	}

	return output;
}

std::string Controller::GetRollLogStringFromCamera(Camera* camera)
{
	std::string output;

	for (unsigned int i = 0; i < camera->GetRollCount(); i++)
	{
		Roll* activeRoll = camera->GetRoll(i);

		output += "[ROLL " + activeRoll->GetID() + "]\n";
		output += "Shot Count: " + std::to_string(activeRoll->GetShotCount()) + "\n";
		output += "\n";

		output += GetShotLogStringFromRoll(activeRoll);
	}

	return output;
}

std::string Controller::GetShotLogStringFromRoll(Roll* roll)
{
	std::string output;

	for (unsigned int i = 0; i < roll->GetShotCount(); i++)
	{
		Shot* activeShot = roll->GetShot(i);

		output += "[SHOT " + activeShot->GetScene() + "-" + activeShot->GetTake() + "]\n";
		output += "FPS: " + activeShot->GetFPS() + "\n";
		output += "Focal Length: " + activeShot->GetLens() + "\n";
		output += "f/Stop: " + activeShot->GetFStop() + "\n";
		output += "ISO: " + activeShot->GetISO() + "\n";
		output += "Color Temp: " + activeShot->GetColorTemp() + "\n";
		output += "Filter: " + activeShot->GetFilter() + "\n";
		output += "\n";
	}

	return output;
}
