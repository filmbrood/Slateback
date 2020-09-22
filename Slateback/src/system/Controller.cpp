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

Controller& Controller::Get()
{
	return s_Instance;
}