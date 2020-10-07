#include "slatebackpch.h"

#include "Serializer.h"

Serializer Serializer::s_Instance; // Initialize singleton instance of Serializer

// Serializer methods. See Serializer.h for more info.
void Serializer::SerializeProjectVector(ProjectVector& pv)
{
	std::ofstream* xml = new std::ofstream;
	xml->open("sltproj.xml");
	{
		cereal::XMLOutputArchive archive(*xml);
		archive(pv);
	}
	xml->close();
	delete xml;
}

void Serializer::DeserializeProjectVector(ProjectVector& pv, std::string filepath)
{
	std::ifstream* xml = new std::ifstream;
	xml->open("sltproj.xml");
	{
		cereal::XMLInputArchive archive(*xml);
		archive(pv);
	}
	xml->close();
	delete xml;
}

Serializer& Serializer::Get()
{
	return s_Instance;
}
