#pragma once

#include "Shot.h"

// Data class containing Roll details, which also acts as a container class for a vector of Shot objects.
class Roll
{
public:
	Roll() {}
	~Roll() {}
public:
	void SetID(std::string id); // Sets string value for m_ID.
	std::string GetID(); // Returns m_ID.
	size_t GetShotCount(); // Returns size of m_Shots.
	void PushNewShot(); // Pushes Shot instance to m_Shots.
	Shot& GetShot(unsigned int index); // Returns Shot instance from m_Shots at specified index.
	void SetActiveShotIndex(unsigned int index); // Sets value for m_ActiveShotIndex.
	unsigned int GetActiveShotIndex(); // Returns m_ActiveShotIndex.

	template<class Archive>
	void serialize(Archive& archive); // Serializes class using Cereal library

private:
	std::string m_ID;
	unsigned int m_ActiveShotIndex = 0;
	std::vector<Shot> m_Shots;
};

template<class Archive>
inline void Roll::serialize(Archive& archive)
{
	archive(CEREAL_NVP(m_ActiveShotIndex), CEREAL_NVP(m_Shots), CEREAL_NVP(m_ID));
}
