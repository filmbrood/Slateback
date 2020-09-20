#pragma once
#include <string>
#include <vector>

#include "Shot.h"

class Roll
{
public:
	void SetID(std::string id);
	void SetShotCount(unsigned int n);

	std::string GetID();
	unsigned int GetShotCount();

	
public:
	// For manipulating and retrieving data from m_Shots vector
	void PushNewShot(Shot* shot);
	Shot* GetShot(unsigned int index);

	std::string PrintShotDetailsToString();
private:
	std::string m_ID;
	unsigned int m_ShotCount;

	std::vector<Shot*> m_Shots;
};