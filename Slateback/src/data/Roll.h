#pragma once
#include <string>
#include <vector>
#include <memory>

#include <cereal/cereal.hpp>
#include <cereal/types/vector.hpp>
#include <cereal/types/string.hpp>

#include "Shot.h"

// Data class containing Roll details, which also acts as a container class for a vector of Shot objects.
class Roll
{
public:
	void SetID(std::string id);
	std::string GetID();

	size_t GetShotCount();

public:
	// For manipulating and retrieving data from m_Shots vector
	void PushNewShot();
	Shot GetShot(unsigned int index);

	// Serializes m_Shots using Cereal library
	template<class Archive>
	void serialize(Archive& archive)
	{
		archive(m_Shots, m_ID);
	}

private:

	std::string m_ID;

	std::vector<Shot> m_Shots;
};