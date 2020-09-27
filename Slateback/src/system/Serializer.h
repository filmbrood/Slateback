#pragma once

#include "../data/ProjectVector.h"

// Singleton class for data serialization of the ProjectVector class
class Serializer
{
public:
	void SerializeProjectVector(ProjectVector& pv); // Sends project vector data to .XML file named "projects.xml"
	void DeserializeProjectVector(ProjectVector& pv, std::string filepath); // Retreives project vector data from .XML file

public:
	static Serializer& Get(); // Returns singleton instance (s_Instance)

private:
	Serializer() {}
	static Serializer s_Instance;
};