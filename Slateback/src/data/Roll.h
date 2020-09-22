#pragma once
#include <string>
#include <vector>

#include "Shot.h"

// Data class containing Roll details, which also acts as a container class for a vector of Shot objects.
class Roll
{
public:
	void SetID(std::string id);

	std::string GetID();
	unsigned int GetShotCount();

	
public:
	// For manipulating and retrieving data from m_Shots vector
	void PushNewShot(Shot* shot);
	Shot* GetShot(unsigned int index);

private:
	std::string m_ID;

	std::vector<Shot*> m_Shots;
};