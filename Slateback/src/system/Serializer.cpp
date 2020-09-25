#include "Serializer.h"

#include <cereal/cereal.hpp>
#include <cereal/types/vector.hpp>
#include <cereal/types/string.hpp>
#include <cereal/types/memory.hpp>
#include <cereal/archives/xml.hpp>

#include <fstream>
#include <sstream>

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

//ProjectVector Serializer::DeserializeProjectVector(std::string filepath)
//{
//	
//}