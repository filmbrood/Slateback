#include <iostream>
#include <filesystem>
#include <fstream>

#include "slateback.h"
#include "CommandList.h"

CommandList::~CommandList()
{
	for (unsigned int i = 0; i < m_Commands.size(); i++)
		delete m_Commands[i];
}

// CommandList functions. These handle updating the program and pushing new commands to the CommandList vector.
void CommandList::PushNewCommand(Command* command)
{
	m_Commands.push_back(command);
}

void CommandList::InitAllCommands()
{
	for (unsigned int i = 0; i < m_Commands.size(); i++)
		m_Commands[i]->OnInit();
}

void CommandList::OnUpdate(const char* argv)
{
	std::string userinput = argv;

	for (unsigned int i = 0; i < m_Commands.size(); i++)
	{
		if (m_Commands[i]->GetInput() == userinput)
			m_Commands[i]->OnUpdate();
	}
}

// Define command methods here.

// "project" argument functions
void NewProject::OnInit()
{
	SetInput("project");
}

void NewProject::OnUpdate()
{
	std::string userinput;

	Controller::Get().PushBackNewProject();

	Project& activeProject = Controller::Get().GetActiveProject();

	// User inputs project title before creation
	std::cout << "Project Title > ";
	getline(std::cin, userinput);
	activeProject.SetTitle(userinput);
	std::cout << "New project created - " << activeProject.GetTitle() << std::endl;

	// User inputs rest of details
	std::cout << "Project Company > ";
	getline(std::cin, userinput);
	activeProject.SetCompany(userinput);

	std::cout << "Project Director > ";
	getline(std::cin, userinput);
	activeProject.SetDirector(userinput);

	std::cout << "Project DP > ";
	getline(std::cin, userinput);
	activeProject.SetDP(userinput);

	Serializer::Get().SerializeProjectVector(Controller::Get().GetProjectVector());
}

// "camera" argument functions
void NewCamera::OnInit()
{
	SetInput("camera");
}

void NewCamera::OnUpdate()
{
	std::string userinput;

	ProjectVector pv;
	Serializer::Get().DeserializeProjectVector(pv, "projects.xml");
	Controller::Get().SetProjectVector(pv);

	Project& project = Controller::Get().GetActiveProject();
	project.PushBackCamera();

	Camera& camera = Controller::Get().GetActiveCamera();
	std::cout << "New camera created for " << project.GetTitle() << std::endl;

	std::cout << "Camera Model > ";
	getline(std::cin, userinput);
	camera.SetModel(userinput);

	std::cout << "Camera ID (A, B, C) > ";
	getline(std::cin, userinput);
	camera.SetID(userinput);

	std::cout << "Camera Sensor Size > ";
	getline(std::cin, userinput);
	camera.SetFilmBack(userinput);
	
	std::cout << "Camera Codec > ";
	getline(std::cin, userinput);
	camera.SetCodec(userinput);

	std::cout << "Camera Lens Set > ";
	getline(std::cin, userinput);
	camera.SetLensSet(userinput);

	std::cout << "Camera Operator > ";
	getline(std::cin, userinput);
	camera.SetCameraOperator(userinput);

	std::cout << "Camera 1st AC > ";
	getline(std::cin, userinput);
	camera.SetFirstAssistantCamera(userinput);

	std::cout << "Camera 2nd AC >";
	getline(std::cin, userinput);
	camera.SetSecondAssistantCamera(userinput);
	
	Serializer::Get().SerializeProjectVector(Controller::Get().GetProjectVector());
}

// "roll" argument functions
void NewRoll::OnInit()
{
	SetInput("roll");
}

void NewRoll::OnUpdate()
{
	std::cout << "Command not implemented" << std::endl;
}

// "shot" argument functions
void NewShot::OnInit()
{
	SetInput("shot");
}

void NewShot::OnUpdate()
{
	std::cout << "Command not implemented" << std::endl;
}

// "serialtest" argument functions
void SerializerTest::OnInit()
{
	SetInput("serialtest");
}

void SerializerTest::OnUpdate()
{
	ProjectVector pv;
	pv.PushNewProject();
	
	Project& project = pv.GetProject(0);
	project.SetTitle("Jack Jameson in: Out of the Sky");
	project.SetCompany("Three and a Half Walls");
	project.SetDirector("Joshua Key");
	project.SetDP("Ryan Kneezle");
	project.PushBackCamera();

	Camera& camera = project.GetCamera(0);
	camera.SetModel("Panasonic GH4");
	camera.SetID("A");
	camera.SetLensSet("Panasonic Kit");
	camera.SetFilmBack("Micro Four Thirds");
	camera.SetCodec("H.264");
	camera.PushNewRoll();

	Roll& roll = camera.GetRoll(0);
	roll.SetID("A001");
	roll.PushNewShot();

	Shot& shot = roll.GetShot(0);
	shot.SetScene("1A");
	shot.SetTake("1");
	shot.SetLens("35mm");
	shot.SetFPS("23.98");
	shot.SetISO("800");
	shot.SetColorTemp("5600K");
	shot.SetFStop("2.8");
	shot.SetFilter("N/A");

	pv.PushNewProject();
	Project& project2 = pv.GetProject(1);
	project2.SetTitle("One of the Ones");
	project2.SetCompany("One of the Ones Production, LLC");
	project2.SetDirector("Nate Myers");
	project2.SetDP("Thais Castralli");

	project2.PushBackCamera();
	Camera& camera2 = project2.GetCamera(0);
	camera2.SetModel("Arri Alexa Mini");
	camera2.SetID("A");
	camera2.SetFilmBack("Super 35");
	camera2.SetCodec("ProRes 4444 XQ");
	camera2.SetLensSet("Zeiss Super Speeds");
	camera2.SetCameraOperator("Thais Castralli");
	camera2.SetFirstAssistantCamera("Dawn Moore");
	camera2.SetSecondAssistantCamera("Makayla Hufziger");

	camera2.PushNewRoll();
	Roll& roll2 = camera2.GetRoll(0);
	roll2.SetID("A008");
	
	roll.PushNewShot();
	Shot& shot2 = roll.GetShot(0);
	shot2.SetScene("7C");
	shot2.SetTake("4");
	shot2.SetFPS("29.97");
	shot2.SetFStop("2.8");
	shot2.SetLens("35mm");
	shot2.SetISO("400");
	shot2.SetColorTemp("4300K");
	shot2.SetFilter("Glimmer Glass 1/2");

	Serializer::Get().SerializeProjectVector(pv);
}

// "deserialtest" argument functions
void DeserializerTest::OnInit()
{
	SetInput("deserialtest");
}

void DeserializerTest::OnUpdate()
{
	ProjectVector testVector;
	Serializer::Get().DeserializeProjectVector(testVector, "projects.xml");

	Controller::Get().SetProjectVector(testVector);
	std::cout << Controller::Get().GetLogOutputString() << std::endl;
	std::cin.get();
}
