#pragma once

#include "../data/ProjectVector.h"

class Serializer
{
public:
	void SerializeProjectVector(ProjectVector& pv);
	void SerializeProject(Project& project);
	void SerializeCamera(Camera& camera);
	void SerializeRoll(Roll& roll);
	void SerializeShot(Shot& shot);

	//ProjectVector DeserializeProjectVector(std::string filepath);

private:
};