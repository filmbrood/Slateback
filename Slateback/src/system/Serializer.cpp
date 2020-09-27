#include "slatebackpch.h"

#include "Serializer.h"

Serializer Serializer::s_Instance;

void Serializer::SerializeProjectVector(ProjectVector& pv)
{
	std::ofstream xml;
	xml.open("projects.xml");
	{
		cereal::XMLOutputArchive archive(xml);
		archive(pv);
	}
	xml.close();
}

void Serializer::DeserializeProjectVector(ProjectVector& pv, std::string filepath)
{
	std::ifstream xml;
	xml.open("projects.xml");
	{
		cereal::XMLInputArchive archive(xml);

		archive(pv);
	}
}

Serializer& Serializer::Get()
{
	return s_Instance;
}
