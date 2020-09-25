#pragma once

#include "../data/ProjectVector.h"

// Singleton class for data serialization of the ProjectVector class
class Serializer
{
public:
	// Sends project vector data to .XML file named "projects.xml"
	void SerializeProjectVector(ProjectVector& pv);
	
	// Retreives project vector data from .XML file
	ProjectVector DeserializeProjectVector(std::string filepath);

public:
	// Returns singleton instance (s_Instance)
	static Serializer& Get();

private:
	Serializer() {}

	static Serializer s_Instance;
};